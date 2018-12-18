//
// Created by yuval on 16/12/18.
//

#ifndef PROJECT1_MY_PARSER_H
#define PROJECT1_MY_PARSER_H

#include "Command.h"
#include "Expression.h"
#include <vector>
#include <string>
#include <map>

using  namespace std;

class Parser {
    map<string, Command*> commands;
public:

   void parser(vector<string> data);
};


#endif //PROJECT1_MY_PARSER_H
