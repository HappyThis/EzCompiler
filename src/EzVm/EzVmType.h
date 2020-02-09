//
// Created by ezos on 19-1-8.
//

#ifndef EZCOMPILER_EZVMTYPE_H
#define EZCOMPILER_EZVMTYPE_H

/*操作类型*/
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

/*解析方法*/
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

/*代码的存储格式*/

struct Code {
    /**/
    Operator op;

    ArgParseMethod arg1ParseMethod;
    unsigned char arg1[60];

    ArgParseMethod arg2ParseMethod;
    unsigned char arg2[60];


    ArgParseMethod arg3ParseMethod;
    unsigned char arg3[60];

    ArgParseMethod Bind;
    int arg4;

    Code() {
        Bind = NoMethod;
        arg3ParseMethod = NoMethod;
        arg2ParseMethod = NoMethod;
        arg1ParseMethod = NoMethod;
    }

};

struct Header {

    /*程序入口点*/
    int entryPoint;
    /*主类大小*/
    int mainClassSize;
    /*魔数*/
    int magicNumber;

};

#endif //EZCOMPILER_EZVMTYPE_H
