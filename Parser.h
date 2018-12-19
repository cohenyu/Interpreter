//
// Created by yuval on 16/12/18.
//

#ifndef PROJECT1_MY_PARSER_H
#define PROJECT1_MY_PARSER_H

#include "Command.h"
#include "Expression.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "SleepCommand.h"
#include "CommandExpression.h"
#include "AssignmentCommand.h"
#include "ConditionParser.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "PrintCommand.h"
#include <vector>
#include <string>
#include <map>
#define OPEN_DATA_SERVER "openDataServer"
#define CONNECT "connect"
#define  ASSIGNMENT "="
#define VAR "var"
#define WHILE "while"
#define PRINT "print"
#define IF "if"
#define SLEEP "sleep"


using  namespace std;

class Parser {
    map<string, Expression*> expsfCommand;
    vector<string> data;
    int index;
public:
    Parser(vector<string> data);
    void parser(vector<string> data);

private:
    map<string, Expression*> initializationMapExp();
};



#endif //PROJECT1_MY_PARSER_H
