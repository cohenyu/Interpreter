

#include "SleepCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include <unistd.h>

SleepCommand::SleepCommand(SymbolTableManager* stm) {
    this->stm=stm;
}

int SleepCommand::doCommand(vector<string> data, int index) {
    string str = data[index + 1];
    ShuntingYard shuntingYard(stm);
    Expression *milisec = shuntingYard.fromInfixToExp(str);
    usleep(milisec->calculate() * 1000);
    delete milisec;
    return 2;
}