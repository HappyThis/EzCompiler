//
// Created by freenos on 18-12-2.
//

#include "SymbolTable.h"

namespace SymbolTable {

    DomainTable *SymbolTable::TopDomainTableStack() {
        if (!domainTableStack.empty())
            return domainTableStack.top();
        return nullptr;
    }


    void SymbolTable::PushDomainTableStack(DomainTable *item) {
        domainTableStack.push(item);
    }


    DomainTableItem *SymbolTable::InsertIntoCurrentDomainTable(string varName, string varType) {

        int varSizeInHeap = 0, varSizeInStack = 0;
        varSizeInStack = JudgeTypeSize(varType);

        map<string, ClassTable *>::iterator it = classTable.find(varType);

        if (varSizeInStack == -1) {
            if (it != classTable.end()) {
                varSizeInStack = sizeof(void *);
                varSizeInHeap = classTable[varType]->GetSize();
            } else {
                return nullptr;
            }
        }
        return TopDomainTableStack()->Insert(varName, varType, varSizeInStack, varSizeInHeap);

    }

    ClassTableItem *
    SymbolTable::InsertIntoCurrentVarTable(string varName, ClassTableItem::Range range, string varType) {

        if (varType == "double" || varType == "bool" || varType == "char" || varType == "int" || varType == "void") {
            return currentClassTable->InsertIntoVarTable(varName, range, varType);
        }
        map<string, ClassTable *>::iterator it = classTable.find(varType);

        if (it == classTable.end())
            return nullptr;

        return currentClassTable->InsertIntoVarTable(varName, range, varType);
    }

    ClassTableItem *
    SymbolTable::InsertIntoCurrentFunTable(string funName, ClassTableItem::Range range, string returnType,
                                           int entryPoint) {

        if (returnType == "double" || returnType == "bool" || returnType == "char" || returnType == "int" ||
            returnType == "void") {
            return currentClassTable->InsertIntoFunTable(funName, range, returnType, entryPoint);
        }
        map<string, ClassTable *>::iterator it = classTable.find(returnType);

        if (it == classTable.end())
            return nullptr;
        return currentClassTable->InsertIntoFunTable(funName, range, returnType, entryPoint);
    }

    void SymbolTable::CreateDomainTable() {


        if (!domainTableStack.empty()) {

            PushDomainTableStack(new DomainTable(TopDomainTableStack(), TopDomainTableStack()->GetVarOffsetInStack()));

        } else {

            PushDomainTableStack(new DomainTable(nullptr));
        }

        return;
    }

    bool SymbolTable::CreateClassTable(string className) {

        if (classTable.find(className) == classTable.end()) {

            currentClassTable = new ClassTable();

            classTable[className] = currentClassTable;

            currentClassTableName = className;

            return true;
        }
        return false;
    }


    void SymbolTable::PopDomainTableStack() {

        if (TopDomainTableStack() == nullptr)
            return;

        delete TopDomainTableStack();

        domainTableStack.pop();
    }

    DomainTableItem *SymbolTable::FindVarFromCurrentDomainTable(string VarName) {

        if (TopDomainTableStack() == nullptr)
            return nullptr;

        return TopDomainTableStack()->Find(VarName);

    }

    SymbolTable::~SymbolTable() {

        map<string, ClassTable *>::iterator it;

        for (it = classTable.begin(); it != classTable.end(); it++) {
            delete it->second;
        }

        while (!domainTableStack.empty()) {
            delete domainTableStack.top();
            domainTableStack.pop();
        }

    }


    ClassTableItem *SymbolTable::FindVarFromClassTable(string VarName, string ClassName) {

        if (classTable.find(ClassName) != classTable.end()) {

            return classTable[ClassName]->FindFromVarTable(VarName);
        }
        return nullptr;
    }

    ClassTableItem *SymbolTable::FindFunFromClassTable(string FunName, string ClassName) {

        if (classTable.find(ClassName) != classTable.end()) {

            return classTable[ClassName]->FindFromFunTable(FunName);
        }
        return nullptr;
    }

    DomainTableItem *SymbolTable::CreateTempVar(string varType, ExpInfo *expInfo) {
        if (TopDomainTableStack() == nullptr)
            return nullptr;
        if (expInfo != nullptr) {
            if (varType == "bool") {
                expInfo->expValueType = BoolInStack;
                expInfo->agrParseMethod = StackToBool_T;
            } else if (varType == "char") {
                expInfo->expValueType = CharInStack;
                expInfo->agrParseMethod = StackToChar_T;
            } else if (varType == "int") {
                expInfo->expValueType = IntInStack;
                expInfo->agrParseMethod = StackToInt_T;
            } else if (varType == "double") {
                expInfo->expValueType = DoubleInStack;
                expInfo->agrParseMethod = StackToDouble_T;
            } else if (varType == "void") {
                expInfo->agrParseMethod = NoMethod;
                expInfo->expValueType = Void;
            } else if (varType == "@r-bool") {
                expInfo->expValueType = BoolInHeap;
                expInfo->agrParseMethod = HeapToBool_T;
            } else if (varType == "@r-char") {
                expInfo->expValueType = CharInHeap;
                expInfo->agrParseMethod = HeapToChar_T;
            } else if (varType == "@r-int") {
                expInfo->expValueType = IntInHeap;
                expInfo->agrParseMethod = HeapToInt_T;
            } else if (varType == "@r-double") {
                expInfo->expValueType = DoubleInHeap;
                expInfo->agrParseMethod = HeapToDouble_T;
            } else {
                expInfo->expValueType = RefInStack;
                expInfo->agrParseMethod = StackToRef_T;
            }
        }
        int varSizeInHeap = 0, varSizeInStack = 0;
        varSizeInStack = JudgeTypeSize(varType);

        map<string, ClassTable *>::iterator it = classTable.find(varType);

        if (varSizeInStack == -1) {
            if (it != classTable.end()) {
                varSizeInStack = sizeof(void *);
                varSizeInHeap = classTable[varType]->GetSize();
            } else {
                return nullptr;
            }
        }

        return TopDomainTableStack()->CreateTempVar(varType, varSizeInStack, varSizeInHeap);
    }

    int SymbolTable::GetClassSize(string ClassName) {

        if (classTable.find(ClassName) != classTable.end()) {

            return classTable[ClassName]->GetSize();
        }

        return -1;
    }

    int SymbolTable::GetClassSize() {
        if (currentClassTable != nullptr)
            return currentClassTable->GetSize();
        return -1;
    }

    SymbolTable::SymbolTable() : currentClassTable(nullptr), isSaveExpItemValid(false) {

    }

    ClassTableItem *SymbolTable::FindVarFromClassTable(string VarName) {
        if (currentClassTable != nullptr)
            return currentClassTable->FindFromVarTable(VarName);
        return nullptr;
    }

    ClassTableItem *SymbolTable::FindFunFromClassTable(string FunName) {
        if (currentClassTable != nullptr)
            return currentClassTable->FindFromFunTable(FunName);
        return nullptr;
    }

    void SymbolTable::CurrentDomainTableDebug() {
        if (TopDomainTableStack() == nullptr)
            return;
        TopDomainTableStack()->Debug();
    }

    void SymbolTable::ClassTableDebug() {
        if (currentClassTable != nullptr) {
            cout << "Class Name:" << currentClassTableName << endl << "Class Size:" << currentClassTable->GetSize()
                 << endl;
            currentClassTable->Debug();
            cout << endl << endl;
        }

    }

    void SymbolTable::ClassTableDebug(string ClassName) {

        if (classTable.find(ClassName) != classTable.end()) {
            cout << "Class Name:" << ClassName << endl << "Class Size:" << classTable[ClassName]->GetSize() << endl;
            classTable[ClassName]->Debug();
            cout << endl << endl;
        }
    }

    bool SymbolTable::InDomain() {
        return TopDomainTableStack() != nullptr;
    }

    bool SymbolTable::SearchVarInDomainAndClassTable(string name, ExpInfo *expInfo) {

        ClassTableItem *classTableItem;
        DomainTableItem *domainTableItem;

        domainTableItem = FindVarFromCurrentDomainTable(name);

        if (domainTableItem == nullptr) {

            classTableItem = FindVarFromClassTable(name);

            if (classTableItem == nullptr) {
                expInfo->domainTableItem = nullptr;
                expInfo->classTableItem = nullptr;
                return false;
            } else {
                /*添加一条代码*/
                CodeContainer::codeContainer->PushBackCode();
                /*设置op类欣*/
                CodeContainer::codeContainer->FillInOp(ADD);
                /*设置参数1解析方式*/
                CodeContainer::codeContainer->FillInArg1ParseMethod(StackToRef);
                /*设置参数1*/
                int offset = 0;
                CodeContainer::codeContainer->FillInArg1(&offset, sizeof(void *));
                /*设置参数2的解析方式*/
                CodeContainer::codeContainer->FillInArg2ParseMethod(ToInt);
                offset = classTableItem->GetOffset();
                CodeContainer::codeContainer->FillInArg2(&offset, sizeof(int));
                /*下面的过程用来设置参数3以及其解析方法*/
                expInfo->classTableItem = classTableItem;
                if (classTableItem->GetVarType() == "int") {
                    expInfo->domainTableItem = CreateTempVar("@r-int", expInfo);
                    //填充参数3以及解析方法
                    CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToInt_T);
                    offset = expInfo->domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                } else if (classTableItem->GetVarType() == "double") {
                    expInfo->domainTableItem = CreateTempVar("@r-double", expInfo);
                    //填充参数3以及解析方法
                    CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToDouble_T);
                    offset = expInfo->domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                } else if (classTableItem->GetVarType() == "char") {
                    expInfo->domainTableItem = CreateTempVar("@r-char", expInfo);
                    //填充参数3以及解析方法
                    CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToChar_T);
                    offset = expInfo->domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                } else if (classTableItem->GetVarType() == "bool") {
                    expInfo->domainTableItem = CreateTempVar("@r-bool", expInfo);
                    //填充参数3以及解析方法
                    CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToBool_T);
                    offset = expInfo->domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                } else {
                    expInfo->domainTableItem = CreateTempVar(classTableItem->GetVarType(), expInfo);
                    //填充参数3以及解析方法
                    CodeContainer::codeContainer->FillInArg3ParseMethod(HeapToRef_T);
                    offset = expInfo->domainTableItem->GetOffsetInStack();
                    CodeContainer::codeContainer->FillInArg3(&offset, sizeof(void *));
                }
            }

        } else {
            expInfo->domainTableItem = domainTableItem;
            if (domainTableItem->GetType() == "int") {
                expInfo->expValueType = IntInStack;
                expInfo->agrParseMethod = StackToInt;
            } else if (domainTableItem->GetType() == "double") {
                expInfo->expValueType = DoubleInStack;
                expInfo->agrParseMethod = StackToDouble;
            } else if (domainTableItem->GetType() == "char") {
                expInfo->expValueType = CharInStack;
                expInfo->agrParseMethod = StackToChar;
            } else if (domainTableItem->GetType() == "bool") {
                expInfo->expValueType = BoolInStack;
                expInfo->agrParseMethod = StackToBool;
            } else {
                expInfo->expValueType = RefInStack;
                expInfo->agrParseMethod = StackToRef;
            }
        }
        return true;
    }

    void SymbolTable::ClearTempVarTable() {
        if (TopDomainTableStack() != nullptr)
            TopDomainTableStack()->ClearTempVarTable();
    }

    bool SymbolTable::TestClass(string ClassName) {
        return classTable.find(ClassName) != classTable.end();
    }


    ExpInfo SymbolTable::GetExpItem() {
        if (isSaveExpItemValid) {
            ExpInfo item = saveExpItem;
            return item;
        }
        ExpInfo expInfo;
        expInfo.length = -1;
        return expInfo;

    }

    void SymbolTable::SetExpItem(ExpInfo expInfo) {

        saveExpItem = expInfo;
        isSaveExpItemValid = true;

    }

    ExpInfo SymbolTable::GetExpItemAndClear() {
        ExpInfo item = saveExpItem;
        isSaveExpItemValid = false;
        return item;
    }


}
