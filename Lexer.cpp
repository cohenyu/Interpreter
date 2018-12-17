//
// Created by yuval on 16/12/18.
//

#include <fstream>
#include "Lexer.h"
#include <vector>



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
    int i = 0;
    for(string line; getline(inputFile, line);){

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