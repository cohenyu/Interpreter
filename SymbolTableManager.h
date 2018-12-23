//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H
#define YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include <set>

#define PATHS_AMOUNT 23

using namespace std;

class SymbolTableManager {
    map<string, double> symbolTable;
    map<string, int> fromPathToIndex;
    double flightGearValues[PATHS_AMOUNT];
    map<string, set<string>> dependencyMap;
    int socket;

public:
    SymbolTableManager();
    void addSymbol(string name, double value);
    void updateSymbol(string name, double value);
    double getValue(string name);
    void updateValuesFromFlightGear(vector<string> values);
    void updateDependency(string prm1, double value);
    void updateValue(string prm1, string prm2);
    void createDependency(string prm1, string prm2);
    void setSocket(int sock);
    void setValueOfFlightGear(string path, double value);

private:
    void initializationArrayToZero();
    map<string, int> initPathsToIndex();
    double strToDouble(string str);
};


#endif //YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H