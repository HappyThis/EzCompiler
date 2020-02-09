//
// Created by freenos on 18-12-5.
//

#include "JudgeTypeSize.h"

namespace SymbolTable{

    map<string,int> judgeMap;


    int JudgeTypeSize(string type){

        if(judgeMap.empty()){
            judgeMap["void"]=0;
            judgeMap["bool"]=1;
            judgeMap["char"]=2;
            judgeMap["int"]=4;
            judgeMap["double"]=8;
            judgeMap["@r-bool"]=4;
            judgeMap["@r-char"]=4;
            judgeMap["@r-int"]=4;
            judgeMap["@r-double"]=4;
        }

        if(judgeMap.find(type)!=judgeMap.end()){
            return judgeMap[type];
        }
        return -1;
    }
}

