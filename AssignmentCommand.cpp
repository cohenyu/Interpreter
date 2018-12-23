//
// Created by yuval on 19/12/18.
//

#include "AssignmentCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#define BIND "bind"

AssignmentCommand::AssignmentCommand(SymbolTableManager *stm) {
    this->stm = stm;
}


int AssignmentCommand::doCommand(vector<string> data, int index) {
    int returnValue;
    string prm1 = data[index - 1];
    if (data[index + 1] == BIND){
        string prm2 = data[index + 2];
        returnValue = 3;
        // TODO - ניצור תלות

    } else {
        returnValue = 2;
        string prm2 = data[index + 1];
        ShuntingYard shuntingYard(stm);
        Expression *exp;
        exp = shuntingYard.fromInfixToExp(prm2);
        int value = exp->calculate();
        delete exp;

        // TODO - נעדכן את התלויים של הפרמטר הראשון
    }
    return returnValue;
}