#include <iostream>
#include "ShuntingYard.h"
int main() {
    //100
    ShuntingYard* x = new ShuntingYard;
    Expression *i = x->fromInfixToExp("100 * ( 2 + 12 ) / 14");
    double r = i->calculate();
    cout << r << endl;

    // 0
    Expression *p = x->fromInfixToExp("((100 / 50)+(9 * 2)) /20 -1");
    double q = p->calculate();
    cout << q << endl;

    // 24
    Expression *e = x.fromInfixToExp("40 - 8 * 2");
    double l = e->calculate();
    cout << l << endl;

    // 8
    Expression *k = x.fromInfixToExp("(200 * 2) / 100 + 4");
    double s = k->calculate();
    cout << s << endl;
}