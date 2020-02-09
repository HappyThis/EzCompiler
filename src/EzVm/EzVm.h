//
// Created by ezos on 19-1-8.
//

#ifndef EZCOMPILER_EZVM_H
#define EZCOMPILER_EZVM_H

#include "fstream"

#include "string"

#include "vector"

#include "EzVmType.h"

#include "iostream"

#include "ActivityRecordStack.h"

#include "map"

using namespace std;


class EzVm {

public:
    EzVm();

    bool ReadSourceFile(string filePath);

    static EzVm *ezVm;

private:

    int csip;

    unsigned  char * memory;

    vector<Code> codeArray;

    Header header;

    map<void*,int>refSize;

    ActivityRecordStack recordStack;

    int currentMemIdx;

    int SearchSize(void* key);

    void * Allocator(int sz);

    void Analyzer();

    void AnalyzerInit();

    void AnalyzerRet(Code code);

    void AnalyzerParam(Code code);

    void AnalyzerCall(Code code,int callPoint);

    void AnalyzerNew(Code code);

    void AnalyzerAssign(Code code);

    void AnalyzerJmp(Code code);

    void AnalyzerArith(Code code);

    void AnalyzerBoolArith(Code code);

    void AnalyzerNegAndNot(Code code);

};


#endif //EZCOMPILER_EZVM_H
