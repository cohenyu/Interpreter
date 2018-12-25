//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H
#define YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "TCPClient.h"
#include "TCPServer.h"

#define PATHS_AMOUNT 23

using namespace std;

class SymbolTableManager {
    map<string, double> symbolTable;
    map<string, int> fromPathToIndex;
    double flightGearValues[PATHS_AMOUNT];
    map<string, set<string>> dependencyMap;
    TCPClient* client;
    TCPServer server;

public:
    SymbolTableManager();
    double getValueOfPathOrVar(string prm);
    void addVarToSymbolTable(string name, double value);
    double getValueFromSymbolTable(string name);
    void setValuesFromFlightGear(vector<string> values);
    void updateValueAndDependentOn(string prm1, double value);
    void createDependency(string prm1, string prm2);
    void setClient(TCPClient* client);
    void setServer(TCPServer server);
    void closeSockets();
   ~SymbolTableManager(){
       //delete this->server;
       delete this->client;
   }

private:
    //double strToDouble(string str);
    void setVarOrPath(string prm1, double value);
    void setVarAtSymbolTable(string name, double value);
    void setValueOfFlightGear(string path, double value);
    void initializationArrayToZero();
    map<string, int> initPathsToIndex();
};


#endif //YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H