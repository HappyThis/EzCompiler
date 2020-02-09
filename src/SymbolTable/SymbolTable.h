//
// Created by freenos on 18-12-2.
//

#ifndef TEMPCODE_SYMBOLTABLE_H
#define TEMPCODE_SYMBOLTABLE_H

#include "string"
#include "stack"
#include "map"
#include "ClassTable.h"
#include "DomainTable.h"
#include "Type.h"
#include "CodeContainer.h"
using namespace std;

namespace SymbolTable {


    class SymbolTable {

    public:


        SymbolTable();

        bool InDomain();

        void PopDomainTableStack();


        DomainTableItem *InsertIntoCurrentDomainTable(string, string);

        ClassTableItem *InsertIntoCurrentVarTable(string VarName, ClassTableItem::Range VarRange, string VarType);

        ClassTableItem *InsertIntoCurrentFunTable(string FunName, ClassTableItem::Range FunRange, string FunReturnType, int FunEntryPoint);

        void CreateDomainTable();

        bool CreateClassTable(string ClassName);

        DomainTableItem *FindVarFromCurrentDomainTable(string VarName);

        ClassTableItem *FindVarFromClassTable(string VarName, string ClassName);

        ClassTableItem *FindVarFromClassTable(string VarName);

        ClassTableItem *FindFunFromClassTable(string FunName, string ClassName);

        ClassTableItem *FindFunFromClassTable(string FunName);

        DomainTableItem *CreateTempVar(string VarType,ExpInfo* expInfo= nullptr);

        void ClearTempVarTable();

        int GetClassSize(string ClassName);

        int GetClassSize();

        void ClassTableDebug(string ClassName);

        void ClassTableDebug();

        void CurrentDomainTableDebug();

        bool SearchVarInDomainAndClassTable(string VarName,ExpInfo* expInfo);

        bool TestClass(string ClassName);

        ExpInfo GetExpItem();
        ExpInfo GetExpItemAndClear();

        void SetExpItem(ExpInfo expInfo);

        ~SymbolTable();

    private:

        map<string, ClassTable *> classTable;

        ClassTable *currentClassTable;

        string currentClassTableName;

        stack<DomainTable *> domainTableStack;

        void PushDomainTableStack(DomainTable *);

        DomainTable *TopDomainTableStack();

        ExpInfo saveExpItem;

        bool isSaveExpItemValid;

    };
}


#endif //TEMPCODE_SYMBOLTABLE_H
