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

private:
    bool isCommand(string str);
    bool isIp(string str);
    bool isCmpOperator(string str);
    bool isOperator(string str);
    vector<string> fromTxtToData (string fileName);
    vector<string> arithmeticProcess(vector<string> data);
public:
    vector<string> lexer(int argc ,char* argv[]);



};


#endif //PROJECT1_MY_LEXER_H
