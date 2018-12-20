//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H
#define YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H

#include <string>
#include <map>
using namespace std;

class SymbolTableManager {
    map<string, double> symbolTable;
public:
    SymbolTableManager();
    void addSymbol(string name, double value);
    void updateSymbol(string name, double value);
    double getValue(string name);
};


#endif //YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H