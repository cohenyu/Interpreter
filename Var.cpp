//
// Created by yuval on 19/12/18.
//

#include "Var.h"
#include "SymbolTableManager.h"

Var::Var(string name) {
    this->name = name;
}

double Var::calculate() {
    return SymbolTableManager::getValue(name);
}