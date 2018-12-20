#include "SymbolTableManager.h"


SymbolTableManager::SymbolTableManager() {}

void SymbolTableManager::addSymbol(string name, double value) {
    this->symbolTable.insert(make_pair(name, value));

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