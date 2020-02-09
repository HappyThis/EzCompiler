//
// Created by freenos on 18-12-25.
//

#include "FillBack.h"


void FillBack::SetBoolTranslateState() {
    boolTranslate = true;
}

void FillBack::ResetBoolTranslateState() {
    boolTranslate = false;
}

bool FillBack::IsTranslating() {
    return boolTranslate;
}

FillBack::FillBack() {
    codeContainer->Erase(0, codeContainer->Size() - 1);
    ResetBoolTranslateState();
    ResetNewTranslateState();
    ResetInterrupt();
}

void FillBack::SetNewTranslateState() {
    newTranslate = true;
}

void FillBack::ResetNewTranslateState() {
    newTranslate = false;
}

bool FillBack::IsNewExpTranslating() {
    return newTranslate;
}

CodeContainer *FillBack::codeContainer = new CodeContainer();

FillBack *FillBack::fillBack = new FillBack();

void FillBack::CreateBreakList() {
    breakFillBackStack.push(list<int>());
}

void FillBack::CreateReturnList(SymbolTable::ClassTableItem *classTableItem) {
    returnFillBackStack.push(list<int>());
    funcInfo.push(classTableItem);
}

void FillBack::CreateContinueList() {
    continueFillBackStack.push(list<int>());
}

bool FillBack::AddIntoBreakList(int idx) {
    if (breakFillBackStack.empty())
        return false;
    breakFillBackStack.top().push_back(idx);
    return true;
}

bool FillBack::AddIntoReturnList(int idx) {
    if (returnFillBackStack.empty())
        return false;
    returnFillBackStack.top().push_back(idx);
    return true;
}

bool FillBack::AddIntoContinueList(int idx) {
    if (continueFillBackStack.empty())
        return false;
    continueFillBackStack.top().push_back(idx);
    return true;
}

void FillBack::DistoryBreakList(int end) {
    if (breakFillBackStack.empty())
        return;;
    for (int idx:breakFillBackStack.top()) {
        CodeContainer::codeContainer->FillInArg3(&end, sizeof(int), idx);
    }
    breakFillBackStack.pop();

}

void FillBack::DistoryReturnList(int end) {
    if (returnFillBackStack.empty())
        return;;
    for (int idx:returnFillBackStack.top()) {
        CodeContainer::codeContainer->FillInArg3(&end, sizeof(int), idx);
    }
    returnFillBackStack.pop();
    funcInfo.pop();
}

void FillBack::DistoryContinueList(int head) {
    if (continueFillBackStack.empty())
        return;;
    for (int idx:continueFillBackStack.top()) {
        CodeContainer::codeContainer->FillInArg3(&head, sizeof(int), idx);
    }
    continueFillBackStack.pop();
}

SymbolTable::ClassTableItem *FillBack::GetCurrentFuncInfo() {
    if (funcInfo.empty())
        return nullptr;
    return funcInfo.top();
}

void FillBack::SetInterruptState() {
    isInterrupt = true;
}

void FillBack::ResetInterrupt() {
    isInterrupt = false;
}

bool FillBack::IsInterruptedTranslating() {
    return isInterrupt;
}

Header *FillBack::GetHeader() {
    return header;
}

void FillBack::SetHeader(int entryPoint, int size) {


    header = new Header();

    header->entryPoint = entryPoint;
    header->mainClassSize = size;
    header->magicNumber = ~'E' + 'z' - 'C' * 'o' / 'm' ^ 'p' | 'i' & 'l' % 'e' + 'r';

}

