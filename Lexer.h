//
// Created by yuval on 16/12/18.
//

#ifndef PROJECT1_MY_LEXER_H
#define PROJECT1_MY_LEXER_H

#include <vector>
#include <string>

using namespace std;
class Lexer {

    vector<string> fromTxtToData (string fileName);

    vector<string> fromConsoleToData(int argc, char* argv[]);

    vector<string> lexer(int argc ,char* argv[]);



};


#endif //PROJECT1_MY_LEXER_H
