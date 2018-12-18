//
// Created by yuval on 16/12/18.
//

#ifndef PROJECT1_MY_LEXER_H
#define PROJECT1_MY_LEXER_H

#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
class Lexer {

    vector<string> fromTxtToData (string fileName);

    vector<string> fromConsoleToData(int argc, char* argv[]);
    vector<string> arithmeticProcess(vector<string> data);
    bool isCommand(string str);
    bool isIp(string str);
    bool isCmpOperator(string str);
    bool isOperator(string str);
public:
    vector<string> lexer(int argc ,char* argv[]);



};


#endif //PROJECT1_MY_LEXER_H
