//
// Created by yuval on 19/12/18.
//

#include "WhileCommand.h"
#include "Parser.h"
#define FIRST_PRM 1
#define SEC_PRM 2
#define THIRD_PRM 3
#define START_EXCUT 5

// constructor
WhileCommand::WhileCommand(SymbolTableManager* stm) {
    this->stm=stm;
}

/**
 * while loop. The function takes the condition, and as long as the condition is true,
 * it parse the the information vector that contain the commands in the scope.
 * @param data the commands
 * @param index data
 * @return How much to move in the main vector to read the next command.
 */
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