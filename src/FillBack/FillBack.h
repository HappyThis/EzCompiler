//
// Created by freenos on 18-12-25.
//

#ifndef TEMPCODE_FILLBACK_H
#define TEMPCODE_FILLBACK_H

#include "list"
#include "stack"
#include "CodeContainer.h"

using namespace std;


class FillBack {

public:


    FillBack();


    void SetBoolTranslateState();

    void ResetBoolTranslateState();

    bool IsTranslating();

    bool IsInterruptedTranslating();

    void SetInterruptState();

    void ResetInterrupt();

    void SetNewTranslateState();

    void ResetNewTranslateState();

    bool IsNewExpTranslating();

    /*临时代码容器,防止bool表达式突变为数值表达式*/
    static CodeContainer *codeContainer;

    static FillBack *fillBack;

    void CreateBreakList();

    bool AddIntoBreakList(int idx);

    void DistoryBreakList(int end);

    void CreateReturnList(SymbolTable::ClassTableItem *classTableItem);

    bool AddIntoReturnList(int idx);

    SymbolTable::ClassTableItem *GetCurrentFuncInfo();

    void DistoryReturnList(int end);

    void CreateContinueList();

    bool AddIntoContinueList(int idx);

    void DistoryContinueList(int head);

    Header* GetHeader();

    void SetHeader(int entryPoint,int size);


private:
    /*是否临时打断bool翻译*/
    bool isInterrupt;
    /*是否开始进行bool翻译*/
    bool boolTranslate;
    /*是否开始进行了new翻译*/
    bool newTranslate;
    /*break回填栈*/
    stack<list<int>> breakFillBackStack;
    /*continue回填栈*/
    stack<list<int>> continueFillBackStack;
    /*return回填栈*/
    stack<list<int>> returnFillBackStack;
    /*return回填辅助栈*/
    stack<SymbolTable::ClassTableItem *> funcInfo;
    /*header*/
    Header *header;
};


#endif //TEMPCODE_FILLBACK_H
