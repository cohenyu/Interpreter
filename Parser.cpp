//
// Created by yuval on 16/12/18.
//

#include "Parser.h"


Parser::Parser(vector<string> data) {
    this->expsfCommand = this->initializationMapExp();
    this->data = data;
    this->index = 0;
}
void Parser::parser(vector<string> data) {
    //stand on thr cur commend
    int index = 0;
    while (index < data.size()){
        Expression* commandExp = expsfCommand.at(data[index]);
        if (commandExp != nullptr){
            index += commandExp->calculate();
        }
    }
}

map<string, Expression*> Parser::initializationMapExp() {
    map<string, Expression*> expC;

    expC.insert(make_pair(OPEN_DATA_SERVER,new CommandExpression(new OpenServerCommand(), this->data, this->index)));

    expC.insert(make_pair(CONNECT,new CommandExpression(new ConnectCommand(), this->data, this->index)));

    expC.insert(make_pair(VAR,new CommandExpression(new DefineVarCommand(), this->data, this->index)));

    expC.insert(make_pair(ASSIGNMENT,new CommandExpression(new AssignmentCommand(), this->data, this->index)));

    expC.insert(make_pair(PRINT,new CommandExpression(new PrintCommand(), this->data, this->index)));

    expC.insert(make_pair(SLEEP,new CommandExpression(new SleepCommand(), this->data, this->index)));

    expC.insert(make_pair(IF,new CommandExpression(new IfCommand(), this->data, this->index)));

    expC.insert(make_pair(WHILE, new CommandExpression(new WhileCommand(), this->data, this->index)));

    return expC;
}