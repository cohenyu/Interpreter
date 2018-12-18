//
// Created by yuval on 16/12/18.
//

#include "Parser.h"

void Parser::parser(vector<string> data) {
    int i = 0;
    while (i < data.size()){
       commands.at(data[i])->calculate();



    }

}
