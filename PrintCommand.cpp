//
// Created by yuval on 19/12/18.
//

#include <iostream>
#include "PrintCommand.h"

using namespace std;

PrintCommand::PrintCommand(SymbolTableManager* stm) {
    this->stm=stm;
}

int PrintCommand::doCommand(vector<string> data, int index) {
    string str = data[index +1];
    cout << str << endl;
    return 2;
}