//
// Created by yuval on 18/12/18.
//

#include "CommandExpression.h"
CommandExpression::CommandExpression(Command &command, vector<string>& data, int& index):
    command(command) , data(data), index(index){

}

double CommandExpression::calculate() {
    return this->command.doCommand(this->data, this->index);
}
