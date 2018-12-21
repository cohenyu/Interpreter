//
// Created by yuval on 19/12/18.
//

#include "WhileCommand.h"
#include "Parser.h"
#define FIRST_PRM 1
#define SEC_PRM 2
#define THIRD_PRM 3
#define START_EXCUT 5

WhileCommand::WhileCommand(SymbolTableManager* stm) {
    this->stm=stm;
}

int WhileCommand::doCommand(vector<string> data, int index) {

    string leftStr = data[index + FIRST_PRM];
    string op = data[index + SEC_PRM];
    string rightStr = data[index + THIRD_PRM];

    vector<string> conditionData = this->createConditionData(data, index + START_EXCUT);
    while (this->checkCondition(leftStr, op, rightStr, this->stm)) {
        Parser parser(conditionData, this->stm);
        parser.parser();
    }

    return conditionData.size() + START_EXCUT + 1;
}