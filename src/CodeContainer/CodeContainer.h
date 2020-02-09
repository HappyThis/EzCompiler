//
// Created by freenos on 18-12-11.
//

#ifndef TEMPCODE_CODECONTAINER_H
#define TEMPCODE_CODECONTAINER_H

#include "string"
#include "vector"
#include "string.h"
#include "Type.h"

using namespace std;

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


class CodeContainer {

public:

    CodeContainer();

    ~CodeContainer();


    bool FillInOp(Operator op, int idx = -1);

    bool FillInArg1ParseMethod(ArgParseMethod expValueType, int idx = -1);

    bool FillInArg2ParseMethod(ArgParseMethod expValueType, int idx = -1);

    bool FillInArg3ParseMethod(ArgParseMethod expValueType, int idx = -1);

    bool FillInArg4ParseMethod(ArgParseMethod expValueType, int idx = -1);

    bool FillInArg1(void *in, int size, int idx = -1);

    bool FillInArg2(void *in, int size, int idx = -1);

    bool FillInArg3(void *in, int size, int idx = -1);

    bool FillInArg4(int in, int idx = -1);

    void PushBackCode();

    void PushBackCode(Code *);

    void PushBackCode(CodeContainer *codeContainer);

    Code *At(int idx);

    bool Insert(int idx, CodeContainer *codeContainer, int startPoint, int length);

    bool Insert(int idx, Code *code);

    bool Insert(int idx);

    bool Erase(int idx);

    bool Erase(int idxl, int idxr);

    bool Move(int targetIdx, int sourceIdx);

    int Size();

    void Clear();

    void Debug();

    static CodeContainer *codeContainer;

private:
    vector<Code *> codeArray;
};

#endif //TEMPCODE_CODECONTAINER_H
