//
// Created by freenos on 18-12-10.
//

#ifndef TEMPCODE_TYPE_H
#define TEMPCODE_TYPE_H

typedef char String[60];

#include "ClassTable.h"
#include "DomainTable.h"
#include "list"
#include "stack"

using namespace std;


enum ExpType {
    EUNKNOW,//未知表达式
    EVISIT,//访问表达式
    ECALL,//调用表达式
    EVALUE,//纯数值表达式
    EARITH,//算术表达式
    EASSIGN,//赋值表达式
    ENEW,//new表达式
    ETRANSIT//过渡表达式
};

enum ExpValueType {
    BoolInStack,
    CharInStack,
    IntInStack,
    DoubleInStack,
    RefInStack,
    BoolInHeap,
    CharInHeap,
    IntInHeap,
    DoubleInHeap,
    BoolValue,
    CharValue,
    IntValue,
    DoubleValue,
    StringValue,
    Void,
    ENULL
};
enum ArgParseMethod {
    ToBool,
    ToChar,
    ToInt,
    ToDouble,
    ToString,
    StackToBool,
    StackToBool_T,
    StackToChar,
    StackToChar_T,
    StackToInt,
    StackToInt_T,
    StackToDouble,
    StackToDouble_T,
    StackToRef,
    StackToRef_T,
    HeapToBool_T,
    HeapToChar_T,
    HeapToInt_T,
    HeapToDouble_T,
    HeapToRef_T,
    CallToBool,
    CallToChar,
    CallToInt,
    CallToDouble,
    CallToRef,
    NoMethod

};

enum Operator {
    ADD, // +
    SUB, // -
    MUL, // *
    DIV, // /
    NOT, // ~
    NEG, // -
    AND, // &
    XOR, // ^
    MOD,
    OR,  // |
    LNE, // !=
    LEQ, // ==
    LGT, // >
    LGE, // >=
    LLT, // <
    LLE, // <=
    LAND,// &&
    LOR, // ||
    ASG,
    CALL,
    PARAM,
    NEW,
    JMP, // jmp not if
    JEQ, // jmp if ==
    JNE, // jmp if !=
    JGT, // jmp if >
    JLT, // jmp if <
    JGE, // jmp if >=
    JLE, // jmp if <=
    RET

};

struct Map {
    /*真实容器中回填代码的起始点*/
    int startPointInReal;
    /*备份容器中的起始点*/
    int startPointInBackup;
    /*真实容器中回填代码翻译长度*/
    int lengthInReal;
    /*备份容器中翻译长度*/
    int lengthInBackup;

    Map() {
        startPointInBackup = -1;
        startPointInReal = -1;
        lengthInReal = 0;
        lengthInBackup = 0;
    };
};

struct BoolExpInfo {
    /*真链*/
    list<int> tList;
    /*假链*/
    list<int> fList;
    /*映射栈*/
    stack<Map> mapStack;
};

struct ExpInfo {

    ExpType expType;/**/
    ExpValueType expValueType;/**/
    ArgParseMethod agrParseMethod;/**/

    SymbolTable::ClassTableItem *classTableItem;
    SymbolTable::DomainTableItem *domainTableItem;/**/

    int intValue;
    double doubleValue;
    char charValue;
    bool boolValue;
    String stringValue;
    /**/
    BoolExpInfo *boolExpInfo;
    /*表达式起始点*/
    int startPoint;
    /*表达式长度*/
    int length;


};
struct ExpInfoArray {
    ExpInfo expInfos[60];
    int size;
};
struct StringArray {

    String strings[60];
    int size;
};
struct Header {

    /*程序入口点*/
    int entryPoint;
    /*主类大小*/
    int mainClassSize;
    /*魔数*/
    int magicNumber;

};

#endif //TEMPCODE_TYPE_H


