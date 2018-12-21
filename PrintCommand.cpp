//
// Created by yuval on 19/12/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "ShuntingYard.h"

using namespace std;

PrintCommand::PrintCommand(SymbolTableManager* stm) {
    this->stm=stm;
}

int PrintCommand::doCommand(vector<string> data, int index) {
    string str = data[index +1];
    if (str[0] == '\"'){
        str = str.substr(1, str.length()-2);
        cout << str << endl;
    } else {
        ShuntingYard shuntingYard(stm);
        Expression *exp;
        exp = shuntingYard.fromInfixToExp(str);
        cout << exp->calculate() << endl;
        delete exp;
    }
    return 2;
}