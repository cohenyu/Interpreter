//
// Created by yuval on 16/12/18.
//

#include "Parser.h"

void Parser::parser(vector<string> data) {
    int index = 0;
    while (index < data.size()){
        Command* c1 = commands.at(data[index]);
        if (c1 != nullptr){
            index += c1->doCommand(data, index);
        } else {
            Command* c2  = commands.at(data[index+1]);
            if (c2 != nullptr){
                index += c2->doCommand(data, index);
            }
        }

    }

}
