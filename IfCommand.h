//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_IFCOMMAND_H
#define YUVALANDMIRIEL_IFCOMMAND_H

#include "ConditionParser.h"
#include "SymbolTableManager.h"
/*
* this class represent if command its heiress from ConditionParser
 * the if command is a if condition that if the condition is true
 * the commands are in the scope are execute.
 * this class containing a  SymbolTableManager in order to achieve the values of parameters
 * in the program.
 */
class IfCommand : public ConditionParser{
    SymbolTableManager* stm;
public:
    IfCommand(SymbolTableManager* stm);
    virtual int doCommand(vector<string> data, int index);
   //~IfCommand(){
   //    delete stm;
   //}
};


#endif //YUVALANDMIRIEL_IFCOMMAND_H
