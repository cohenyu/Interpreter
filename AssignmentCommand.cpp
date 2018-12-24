//
// Created by yuval on 19/12/18.
//

#include "AssignmentCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#define BIND "bind"

using namespace std;
AssignmentCommand::AssignmentCommand(SymbolTableManager *stm) {
    this->stm = stm;
}


int AssignmentCommand::doCommand(vector<string> data, int index) {
    int returnValue;
    string prm1 = data[index - 1];
    //todo
    if (prm1[0] == '\"'){
        prm1 = deleteQuote(prm1);
    }
    if (data[index + 1] == BIND){
        string prm2 = data[index + 2];
        if (prm2[0] == '\"'){
            prm2 = deleteQuote(prm2);
        }
        returnValue = 3;
        this->stm->createDependency(prm1, prm2);

    } else {
        returnValue = 2;
        string prm2 = data[index + 1];
        if (prm2[0] == '\"'){
            prm2 = deleteQuote(prm2);
        }
        double value = stm->getValueOfPathOrVar(prm2);
        stm->updateValueAndDependentOn(prm1, value);
    }

    return returnValue;
}

string AssignmentCommand::deleteQuote(string str) {
    return  str.substr(1, str.length()-2);
}