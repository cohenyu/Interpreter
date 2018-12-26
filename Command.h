

#ifndef PROJECT1_MY_COMMAND_H
#define PROJECT1_MY_COMMAND_H

#include <vector>
#include <string>

using namespace std;
/*
 * this class represent a command
 * for each command there is do command method that excecute the command
 * with the given parameters as interpreter
 */
class Command{
public:
    virtual int doCommand(vector<string> data,int index) = 0;

};




#endif //PROJECT1_MY_COMMAND_H
