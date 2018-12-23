//
// Created by yuval on 16/12/18.
//

#include "Parser.h"

/*
 * constractor of parser
 */
Parser::Parser(vector<string> data, SymbolTableManager* stm) {
    this->stm = stm;
    this->expsfCommand = this->initializationMapExp();
    this->data = data;
    this->index = 0;

}
/*
 * parser function
 */
void Parser::parser() {
    //stand on thr cur commend
    index = 0;
    while (index < this->data.size()){
        if(expsfCommand.find(data[index]) != expsfCommand.end()){
            Expression* commandExp = expsfCommand.find(data[index])->second;
            index += commandExp->calculate();
        } else {
            index++;
        }
    }
    this->stm->closeSockets();
}

map<string, Expression*> Parser::initializationMapExp() {
    map<string, Expression*> expC;

    expC.insert(make_pair(OPEN_DATA_SERVER,new CommandExpression(new OpenServerCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(CONNECT,new CommandExpression(new ConnectCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(VAR,new CommandExpression(new DefineVarCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(ASSIGNMENT,new CommandExpression(new AssignmentCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(PRINT,new CommandExpression(new PrintCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(SLEEP,new CommandExpression(new SleepCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(IF,new CommandExpression(new IfCommand(this->stm), this->data, this->index)));

    expC.insert(make_pair(WHILE, new CommandExpression(new WhileCommand(this->stm), this->data, this->index)));

    return expC;
}