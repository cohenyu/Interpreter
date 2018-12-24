#include <iostream>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"
#include "DataReaderServer.h"
#include <ostream>
#include <unistd.h>

int main(int argc, char **argv) {

    SymbolTableManager stm;
    ShuntingYard shuntingYard(&stm);
    Expression *exp;
    int rate, port;

    DataReaderServer(5400, 10).acceptConnectionsAndReadData(&stm);

    while (true) {
        sleep(1);
    }
}

   //100
    //ShuntingYard* x = new ShuntingYard;
    //Expression *i = x->fromInfixToExp("100 * ( 2 + 12 ) / 14");
    //double r = i->calculate();
    //cout << r << endl;

//    // 0
    //Expression *p = x->fromInfixToExp("((100 / 50)+(9 * 2)) /20 -1");
    //double q = p->calculate();
    //cout << q << endl;

    // 24
    //Expression *e = x->fromInfixToExp("40 - 8 * 2");
    //double l = e->calculate();
    //cout << l << endl;

  // // 8
  // Expression *k = x->fromInfixToExp("(200 * 2) / 100 + 4");
  // double s = k->calculate();
  // cout << s << endl;

  // //0
  // Expression *h = x->fromInfixToExp("(200 * -2) / 100 + 4");
  // double n = h->calculate();
  // cout << s << endl;

  //-100
    //ShuntingYard* x = new ShuntingYard;
    //Expression *i = x->fromInfixToExp("-10 * -2");
    //double r = i->calculate();
   // cout << r << endl;

   // -5
    //ShuntingYard* x = new ShuntingYard;
    //Expression *i = x->fromInfixToExp("-10 / 2");
    //double r = i->calculate();
    //cout << r << endl;

    // 17
    //ShuntingYard* x = new ShuntingYard;
    //Expression *i = x->fromInfixToExp("4 * 5 -(-3*-2) / 2");
    //double r = i->calculate();
    //cout << r << endl;
  //SymbolTableManager *s = new SymbolTableManager();
  //ShuntingYard* x = new ShuntingYard(s);
  //Expression *i = x->fromInfixToExp("-3.5+5");
  //double r = i->calculate();
  //cout << r << endl;

//   SymbolTableManager* stm = new SymbolTableManager; // = new SymbolTableManager();
//   //s->addVarToSymbolTable("idan", 5);
//   //s->addVarToSymbolTable("xyz", 2);
//   //ShuntingYard* x = new ShuntingYard(s);
//   //Expression *i = x->fromInfixToExp("(idan-xyz)");
//   //double r = i->calculate();
//   //cout << r << endl;
//
//
//    //create empty symbolTableManager
//    SymbolTableManager stm;
//    //read the file
//    Lexer* lexer = new Lexer();
//    vector<string> vec = lexer->lexer(argc, argv);
//    //parser
//    Parser* parser =new Parser(vec,&stm);
//    parser->parser();
//}