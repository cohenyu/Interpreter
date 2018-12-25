#include <iostream>
#include "ShuntingYard.h"
#include "Lexer.h"
#include "Parser.h"
#include "DataReaderServer.h"
#include <ostream>
#include <unistd.h>
#include <math.h>
#include <TCPClient.h>

//int main(int argc, char **argv) {
//
//    TCPClient client("10.0.2.2", 5402);
//    client.connectToServer();
//    while (true){
//        client.writeToServer("set /controls/flight/aileron 2.02");
//        sleep(5);
//    }


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
//    ShuntingYard* x = new ShuntingYard();
//    Expression *i = x->fromInfixToExp("-1");
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



//    //create empty symbolTableManager
//    SymbolTableManager stm;
//    //read the file
//    Lexer lexer;
//    vector<string> vec = lexer.lexer(argc, argv);
//
//    //parser
//    Parser parser(vec,&stm);
//    parser.parser();
//
//    //parser.freeMemory();
//   while(true){
//      sleep(1);
//   }
//    long double d =stold("1.193444");
//    cout << d <<endl;


//    return 0;
//}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>



using  namespace std;
int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 5402;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("10.0.2.2");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    cout << "connected" << endl;

    /* Now ask for a message from the user, this message
       * will be read by server
    */


    int i = 1;
    while (i < 3){
        i++;
        printf("Please enter the message: ");
        bzero(buffer,256);
        fgets(buffer,255,stdin);
        /* Send message to the server */
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        /* Now read server response */
        bzero(buffer,256);
    }
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    return 0;
}

