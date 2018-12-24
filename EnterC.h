//
// Created by yuval on 24/12/18.
//

#ifndef YUVALANDMIRIEL_ENTERC_H
#define YUVALANDMIRIEL_ENTERC_H

#include "Command.h"

class EnterC : public Command {
public:
    EnterC();
    int doCommand(vector<string> data, int index) override;

};



#endif //YUVALANDMIRIEL_ENTERC_H
