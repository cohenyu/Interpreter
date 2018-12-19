//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H
#define YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H

#include <string>
#include <map>
using namespace std;

class SymbolTableManager {
    static map<string, double> symbolTable;
public:
    static void addSymbol(string name, double value);
    static void updateSymbol(string name, double value);
    static double getValue(string name);
};


#endif //YUVALANDMIRIEL_SYMBOLTABLEMANAGER_H
