
#ifndef YUVALANDMIRIEL_ENTERC_H
#define YUVALANDMIRIEL_ENTERC_H

#include "Command.h"

class EnterC : public Command {
public:
    EnterC();
    virtual unsigned int doCommand(vector<string> data, unsigned int index);

};



#endif //YUVALANDMIRIEL_ENTERC_H
