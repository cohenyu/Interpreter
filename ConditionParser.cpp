#include "ConditionParser.h"
#include "ShuntingYard.h"

#define EQUAL '='
#define LESS '<'
#define GREATER '>'
#define NOT '!'
#define F_CL_BRACKET "}"



bool ConditionParser::checkCondition(string leftStr, string op, string rightStr, SymbolTableManager* stm) {
    ShuntingYard shuntingYard(stm);
    Expression *left = shuntingYard.fromInfixToExp(leftStr);
    Expression *right = shuntingYard.fromInfixToExp(rightStr);

    double leftCal = left->calculate();
    double rightCal = right->calculate();

    delete  left;
    delete  right;

   if(op.length() == 2){
       switch (op[0]) {
           case EQUAL:
               return leftCal == rightCal;
           case LESS:
               return leftCal <= rightCal;
           case GREATER:
               return leftCal >= rightCal;
           case NOT:
           default:
               return leftCal != rightCal;
       }
   } else {
       switch (op[0]){
           case LESS:
               return leftCal < rightCal;
           case GREATER:
           default:
               return leftCal > rightCal;
       }
   }
}

vector<string> ConditionParser::createConditionData(vector<string> data, int index) {
    int counter = 1;
    vector<string> conditionData;
    int i = index;
    while (counter != 0 && i < data.size()){
        if (data[i] == "{"){
            counter++;
        } else if(data[i] == "}"){
            counter--;
        }
        conditionData.push_back(data[i]);
        i++;
    }
    conditionData.pop_back();
    return conditionData;
}