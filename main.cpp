#include <iostream>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"
#include "DataReaderServer.h"
#include <ostream>
#include <unistd.h>
#include <math.h>
#include <TCPClient.h>

int main(int argc, char **argv) {

//
//    SymbolTableManager stm;
//
//    ShuntingYard *x = new ShuntingYard(&stm);
//    stm.addVarToSymbolTable("roll", 2);
//    stm.addVarToSymbolTable("heading", 4);
//    stm.addVarToSymbolTable("h0", 10);
//    Expression *i = x->fromInfixToExp("(h0-heading)/roll");
//    double r = i->calculate();
//    cout << r << endl;
//}
////
//    TCPClient client("10.0.2.2", 5402);
//    client.connectToServer();
//    while (true) {
//        client.writeToServer("set /controls/flight/rudder 1\r\n");
//        sleep(1);
//        client.writeToServer("set /controls/flight/rudder -1\r\n");
//        sleep(1);
//    }
//}

//    SymbolTableManager stm;
//    ShuntingYard shuntingYard(&stm);
//    Expression *exp;
//    int rate, port;
//
//    DataReaderServer(5400, 10).acceptConnectionsAndReadData(&stm);
//
//    while (true) {
//        sleep(1);
//    }
//}
//
   // SymbolTableManager stm;
//
//    ShuntingYard* x = new ShuntingYard(&stm);
//    stm.addVarToSymbolTable("roll", 2);
//    stm.addVarToSymbolTable("heading", 4);
//    stm.addVarToSymbolTable("h0", 10);
//    Expression *i = x->fromInfixToExp("(h0-heading)/roll");
//    double r = i->calculate();
//    cout << r << endl;

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
//   //double  d = stm->strToDouble("0.30000000000000002");
//   ShuntingYard* m = new ShuntingYard(stm);
//   Expression * z= m->fromInfixToExp("1.193444");
//   cout << z->calculate() << endl;
//    cout << stod("-1.193444") << endl;
//    cout << stof("1.193444") << endl;
//   ShuntingYard* x = new ShuntingYard(stm);
//   Expression *i = x->fromInfixToExp("--1");
//   double r = i->calculate();
//   cout << r << endl;



    //create empty symbolTableManager
    SymbolTableManager stm;
    //read the file
    Lexer lexer;
    vector<string> vec = lexer.lexer(argc, argv);

    //parser
    Parser parser(vec,&stm);
    parser.parser();

    //parser.freeMemory();
   while(true){
      sleep(1);
   }
//    long double d =stold("1.193444");
//    cout << d <<endl;


    return 0;
}
