//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H
#define YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H

#include "Command.h"
class AssignmentCommand: public Command{
public:
    virtual int doCommand(vector<string> data, int index);
};


#endif //YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H
