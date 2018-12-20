//
// Created by yuval on 18/12/18.
//

#include "CommandExpression.h"
CommandExpression::CommandExpression(Command* command, vector<string>& data, int& index ):
    data(data), index(index){
    this->command = command;

}

double CommandExpression::calculate() {
    return this->command->doCommand(this->data, this->index);
}
