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
    string dest = data[index - 1];
    if (data[index + 1] == BIND){
        returnValue = 2;
        string sorc = data[index + 2];
        // TODO - ניצור תלות

    } else {
        returnValue = 3;
        string sorc = data[index + 1];
        ShuntingYard shuntingYard(stm);
        Expression *exp;
        exp = shuntingYard.fromInfixToExp(sorc);
        this->stm->updateSymbol(dest, exp->calculate());
        delete exp;
        // TODO - נעדכן את התלויים
        // האם עדכון והוספה של תלות זו אותה פונקציה?
    }
    return returnValue;
}