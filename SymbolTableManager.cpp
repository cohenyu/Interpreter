

#include "SymbolTableManager.h"


void SymbolTableManager::addSymbol(string name, double value) {
   symbolTable.insert(make_pair(name, value));

}

void SymbolTableManager::updateSymbol(string name, double value) {
    if (symbolTable.find(name) == symbolTable.end()){
        throw "this var does not have declaration";
    }
    symbolTable.find(name)->second = value;
}

double SymbolTableManager::getValue(string name) {
    if(symbolTable.find(name) != SymbolTableManager::symbolTable.end()){
        return SymbolTableManager::symbolTable.find(name)->second;
    }
    throw "var not found";
}