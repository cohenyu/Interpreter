//
// Created by yuval on 16/12/18.
//

#include "Parser.h"

/*
 * constractor of parser
 */
Parser::Parser(vector<string> data,SymbolTableManager* stm) {
    this->expsfCommand = this->initializationMapExp();
    this->data = data;
    this->index = 0;
    this->stm=stm;

}
/*
 * parser function
 */
void Parser::parser() {
    //stand on thr cur commend
    int index = 0;
    while (index < this->data.size()){
        Expression* commandExp = expsfCommand.at(data[index]);
        if (commandExp != nullptr){
            index += commandExp->calculate();
        }
    }
}

map<string, Expression*> Parser::initializationMapExp() {
    map<string, Expression*> expC;


    expC.insert(make_pair(OPEN_DATA_SERVER,new CommandExpression(new OpenServerCommand(stm), this->data, this->index)));

    expC.insert(make_pair(CONNECT,new CommandExpression(new ConnectCommand(stm), this->data, this->index)));

    expC.insert(make_pair(VAR,new CommandExpression(new DefineVarCommand(stm), this->data, this->index)));

    expC.insert(make_pair(ASSIGNMENT,new CommandExpression(new AssignmentCommand(stm), this->data, this->index)));

    expC.insert(make_pair(PRINT,new CommandExpression(new PrintCommand(stm), this->data, this->index)));

    expC.insert(make_pair(SLEEP,new CommandExpression(new SleepCommand(stm), this->data, this->index)));

    expC.insert(make_pair(IF,new CommandExpression(new IfCommand(stm), this->data, this->index)));

    expC.insert(make_pair(WHILE, new CommandExpression(new WhileCommand(stm), this->data, this->index)));

    return expC;
}