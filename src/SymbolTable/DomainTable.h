//
// Created by freenos on 18-12-2.
//

#ifndef TEMPCODE_DOMAINTABLE_H
#define TEMPCODE_DOMAINTABLE_H

#include "map"
#include "string"
#include "JudgeTypeSize.h"

using namespace std;

namespace SymbolTable {

    class DomainTableItem {

        friend class DomainTable;

    public:
        string GetType();

        int GetOffsetInStack();

        int GetSizeInStack();

        int GetSizeInHeap();

    private:
        string type;

        int offsetInStack;

        int sizeInStack;

        int sizeInHeap;

        void SetOffsetInStack(int);

        DomainTableItem(string);

        void SetSizeInStack(int);

        void SetSizeInHeap(int);
    };


    class DomainTable {

    public:
        DomainTable(DomainTable *, int oft = 4);

        ~DomainTable();

        DomainTableItem *Find(string);

        DomainTableItem *Insert(string, string, int, int);

        DomainTableItem *CreateTempVar(string, int, int);

        int GetVarOffsetInStack();

        void ClearTempVarTable();

        void Debug();

    private:
        map<string, DomainTableItem *> varTable;
        map<string, DomainTableItem *> tempVarTable;
        DomainTable *parent;
        int varOffsetInStack;
        int TempVarOffsetInStack;
    };

}
#endif //TEMPCODE_DOMAINTABLE_H
