//
// Created by freenos on 18-12-4.
//

#ifndef TEMPCODE_JUDGETYPESIZE_H
#define TEMPCODE_JUDGETYPESIZE_H

#include "map"
#include "string"
#include "iostream"

using namespace std;

namespace SymbolTable{

    extern map<string,int> judgeMap;


    int JudgeTypeSize(string type);

}

#endif //TEMPCODE_JUDGETYPESIZE_H
