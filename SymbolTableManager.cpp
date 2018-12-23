#include <math.h>
#include "SymbolTableManager.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "SocketCommunication.h"
#define DOT '.'

using namespace std;

SymbolTableManager::SymbolTableManager() {
    initializationArrayToZero();
    this->fromPathToIndex = initPathsToIndex();
    this->socket = -1;
}

void SymbolTableManager::addSymbol(string name, double value) {
    set<string> vars;
    vars.insert(name);
    this->symbolTable.insert(make_pair(name, value));
    dependencyMap.insert(make_pair(name, vars));

}

void SymbolTableManager::updateSymbol(string name, double value) {
    if (this->symbolTable.find(name) == this->symbolTable.end()){
        throw "this var does not have declaration";
    }
    this->symbolTable.find(name)->second = value;
}

double SymbolTableManager::getValue(string name) {
    if(this->symbolTable.find(name) != this->symbolTable.end()){
        return this->symbolTable.find(name)->second;
    }
    throw "var not found";
}

void SymbolTableManager::initializationArrayToZero() {
    for(int i = 0; i < PATHS_AMOUNT; i++){
        this->flightGearValues[i] = 0;
    }
}

map<string, int> SymbolTableManager::initPathsToIndex() {
    map<string, int> pathAndIndex;
    pathAndIndex.insert(make_pair("/instrumentation/airspeed-indicator/indicated-speed-kt", 0));
    pathAndIndex.insert(make_pair("/instrumentation/altimeter/indicated-altitude-ft", 1));
    pathAndIndex.insert(make_pair("/instrumentation/altimeter/pressure-alt-ft", 2));
    pathAndIndex.insert(make_pair("/instrumentation/attitude-indicator/indicated-pitch-deg", 3));
    pathAndIndex.insert(make_pair("/instrumentation/attitude-indicator/indicated-roll-deg", 4));
    pathAndIndex.insert(make_pair("/instrumentation/attitude-indicator/internal-pitch-deg", 5));
    pathAndIndex.insert(make_pair("/instrumentation/attitude-indicator/internal-roll-deg", 6));
    pathAndIndex.insert(make_pair("/instrumentation/encoder/indicated-altitude-ft", 7));
    pathAndIndex.insert(make_pair("/instrumentation/encoder/pressure-alt-ft", 8));
    pathAndIndex.insert(make_pair("/instrumentation/gps/indicated-altitude-ft", 9));
    pathAndIndex.insert(make_pair("/instrumentation/gps/indicated-ground-speed-kt", 10));
    pathAndIndex.insert(make_pair("/instrumentation/gps/indicated-vertical-speed", 11));
    pathAndIndex.insert(make_pair("/instrumentation/heading-indicator/indicated-heading-deg", 12));
    pathAndIndex.insert(make_pair("/instrumentation/magnetic-compass/indicated-heading-deg", 13));
    pathAndIndex.insert(make_pair("/instrumentation/slip-skid-ball/indicated-slip-skid", 14));
    pathAndIndex.insert(make_pair("/instrumentation/turn-indicator/indicated-turn-rate", 15));
    pathAndIndex.insert(make_pair("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 16));
    pathAndIndex.insert(make_pair("/controls/flight/aileron", 17));
    pathAndIndex.insert(make_pair("/controls/flight/elevator", 18));
    pathAndIndex.insert(make_pair("/controls/flight/rudder", 19));
    pathAndIndex.insert(make_pair("/controls/flight/flaps", 20));
    pathAndIndex.insert(make_pair("/controls/engines/engine/throttle", 21));
    pathAndIndex.insert(make_pair("/engines/engine/rpm", 22));
    // נעדכן את הערך שלהם
    for(map<string,int>::iterator it = pathAndIndex.begin(); it != pathAndIndex.end(); ++it){
        set<string> vars;
        vars.insert(it->first);
        dependencyMap.insert(make_pair(it->first, vars));
    }


    return pathAndIndex;
}

void SymbolTableManager::updateValuesFromFlightGear(vector<string> values) {
    for (int i = 0; i < PATHS_AMOUNT; i++){
        this->flightGearValues[i] = this->strToDouble(values[i]);
    }
    // TODO - עדכון תלויות
}

double SymbolTableManager::strToDouble(string str) {
    double val = 0;
    int i = 0;

    while(i < str.length() && isdigit(str[i])) { // str[i] != DOT
        val = (val * 10) + (str[i] - '0');
        i++;
    }
    int couter = 0;
    if (str[i] == DOT){
        i++;
        while(i < str.length() && isdigit(str[i]))
        {
            val = (val * 10) + (str[i] - '0');
            couter++;
            i++;
        }
    }

    return  val/pow(10,couter);
}

void SymbolTableManager::updateValue(string prm1, string prm2) {
    double value;
    if (this->fromPathToIndex.find(prm2) != this->fromPathToIndex.end()) {
        int index = fromPathToIndex.at(prm2);
        value = flightGearValues[index];
    } else {
        ShuntingYard sy(this);
        Expression* exp = sy.fromInfixToExp(prm2);
        value = exp->calculate();
        delete exp;
    }

  updateDependency(prm1, value);

}

void SymbolTableManager::updateDependency(string prm1, double value) {
    for(string s: dependencyMap.at(prm1)){
        if (this->fromPathToIndex.find(s) != this->fromPathToIndex.end()) {
            setValueOfFlightGear(prm1, value);
        } else {
            updateSymbol(s, value);
        }
    }
}

void SymbolTableManager::createDependency(string prm1, string prm2) {
    set<string> mainSet;
    if (dependencyMap.find(prm1) == dependencyMap.end()){
        throw "use of undeclared identifier";
//        set<string> prm1Set;
//        dependencyMap.insert(make_pair(prm1, prm1Set));
    } else {
        for (string s: dependencyMap.find(prm1)->second) {
            mainSet.insert(s);
        }
    }

    if (dependencyMap.find(prm2) == dependencyMap.end()){
        throw "use of undeclared identifier";
//        set<string> prm2Set;
//        dependencyMap.insert(make_pair(prm2, prm2Set));
    } else {
        for (string s: dependencyMap.find(prm2)->second) {
            mainSet.insert(s);
        }
    }

    for(string s: mainSet){

        // נעדכן את הערך שלהם
       if (dependencyMap.find(s) != dependencyMap.end()){
           dependencyMap.find(s)->second = mainSet;
       }

    }
}

void SymbolTableManager::setSocket(int sock) {
    // TODO איזה סוקט בדיוק לשמור? מהלקוח או מהשרת
    this->socket = sock;
}

void SymbolTableManager::setValueOfFlightGear(string path, double value) {

    if (this->socket != -1){
        string data = "set "+ path + ' ' + to_string(value);
        SocketCommunication sc;
        sc.writeToSocket(this->socket, data);
    }
}