//
// Created by yuval on 16/12/18.
//

#include <fstream>
#include "Lexer.h"
#include <vector>
#define MULT '*'
#define DIV '/'
#define MINUS '-'
#define PLUS '+'
#define EQUAL '='
#define LESS '<'
#define GREATER '>'
#define NOT '!'
#define TAB '\t'
#define COMMA ','
#define SPACE ' '
#define OP_BRACKET '('
#define CL_BRACKET ')'
#define F_OP_BRACKET '{'
#define F_CL_BRACKET '}'
#define GERESH '\"'
#define B_SLASH '\\'
#define GREATER_E ">="
#define LESS_E "<="
#define EQUAL_E "=="
#define NOT_E "!="



vector<string> Lexer::lexer(int argc, char **argv) {

    string string = argv[1];
    ///// TODO- how we know if this file or console?
    if (string.find("txt") > 0){
        return fromTxtToData(string);
    }
    return fromConsoleToData(argc,argv);
}

vector<string> Lexer::fromTxtToData(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open()){
        throw "error opening file";
    }
    vector<string> data;
    string token ="";
    for(string line; getline(inputFile, line);){
        for (int j =0; j<line.length(); j++){
            char cur= line[j];
            // if the cur is not a letter or a number so we want to put the token in the vector
            //and initialize the token
            if ((token.length()!=0) && (!isdigit(cur) &&
            !((cur >='A'&& cur <= 'Z')|| (cur >= 'a' && cur <= 'z') || cur == '.'))){
                data.push_back(token);
                token="";
            }

            //if saw operators
            if((cur ==PLUS)|| (cur ==MINUS)|| (cur ==DIV)||(cur== MULT)) {
                string temp;
                temp += cur;
                data.push_back(temp);
                //if we sew something before =
            } else if ((cur== NOT)||(cur==GREATER)||(cur==LESS)||(cur==EQUAL)){
                if (line[j+1]== EQUAL){
                    string str;
                    str += cur;
                    str += line[j+1];
                    data.push_back(str);
                    j++;
                    //if only =
                } else {
                    string temp;
                    temp += cur;
                    data.push_back(temp);
                }
                // if we saw '(' read until ')'.
            } else if (cur == OP_BRACKET){
                int counter = 1;
                string str;
                str += line[j];
                j++;
                while (counter != 0 && (j < line.length())){
                    str += line[j];
                    if (line[j] == OP_BRACKET){
                        counter++;
                    } else if (line[j] == CL_BRACKET){
                        counter--;
                    }
                    j++;
                }
                j-- ;
                if(counter != 0){
                    throw "syntax error";
                }
                data.push_back(str);
                //if we read " read until " push the strings between in the vector
            } else if (cur == GERESH){
                int counter = 1;
                string str;
                str+=cur;
                j++;
                while (counter != 0 && j < line.length()){
                    str+=line[j];
                    if (line[j] == GERESH && line[j-1] != B_SLASH){
                        counter-- ;
                    }
                    j++;

                }
                j-- ;
                if (counter != 0){
                    throw "syntax error";
                }
                data.push_back(str);
                //if we saw { || } push to the vactor
            } else if ((cur== F_CL_BRACKET)||(cur == F_OP_BRACKET)||cur==COMMA){
                string temp;
                temp += cur;
                data.push_back(temp);
            } else if ((cur== TAB)||(cur==SPACE)){
                continue;
            } else {
                token+= cur;
            }
        }
        if (token.length() != 0){
            data.push_back(token);
            token = "";
        }

    }
    return data;
}

vector<string> Lexer::fromConsoleToData(int argc, char **argv) {
    vector<string> data;
    int index = 0;
    for (int i = 1; i < argc; i++){

    }
    return  data;
}

vector<string> Lexer::arithmeticProcess(vector<string> tempData) {
    vector<string> data;
    for(int i =0; i < tempData.size(); i++){

    




    }

}

bool Lexer::isCommand(string str) {

}

bool Lexer::isIp(string str) {

}

bool Lexer::isCmpOperator(string str) {
    return (str[0] == LESS || str[0] == GREATER || str == EQUAL_E || str == LESS_E || str == GREATER_E || str == NOT_E);
}

bool Lexer::isOperator(string str) {
    return (str[0] == PLUS || str[0] == MINUS || str[0] == MULT || str[0] == DIV);

}