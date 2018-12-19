//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_COMMAND_H
#define PROJECT1_MY_COMMAND_H

#include <vector>
#include <string>
using namespace std;
class Command{
public:
    virtual int doCommand(vector<string> data,int index) = 0;
};



#endif //PROJECT1_MY_COMMAND_H
