//
// Created by freenos on 18-12-2.
//

#include "DomainTable.h"

namespace SymbolTable {


    DomainTableItem *DomainTable::Find(string varName) {

        DomainTable *searchTree = this;

        while (searchTree != nullptr) {

            if (searchTree->varTable.find(varName) != searchTree->varTable.end()) {

                return searchTree->varTable[varName];
            }

            searchTree = searchTree->parent;
        }

        return nullptr;
    }


    DomainTable::~DomainTable() {

        map<string, DomainTableItem *>::iterator it = varTable.begin();
        while (it != varTable.end()) {
            delete it->second;
            it++;
        }
    }

    DomainTable::DomainTable(DomainTable *Parent, int oft) {
        parent = Parent;
        varOffsetInStack = oft;
        TempVarOffsetInStack = 0;
    }

    DomainTableItem *DomainTable::CreateTempVar(string type, int varSizeInStack, int varSizeInHeap) {

        string varName = to_string(TempVarOffsetInStack) + "@" + "T";
        DomainTableItem *item = new DomainTableItem(type);
        item->SetOffsetInStack(TempVarOffsetInStack);
        item->SetSizeInStack(varSizeInStack);
        item->SetSizeInHeap(varSizeInHeap);
        TempVarOffsetInStack += item->GetSizeInStack();
        tempVarTable[varName] = item;
        return item;
    }

    DomainTableItem *DomainTable::Insert(string varName, string varType, int varSizeInStack, int varSizeInHeap) {
        if (varTable.find(varName) == varTable.end()) {
            DomainTableItem *item = new DomainTableItem(varType);
            varTable[varName] = item;
            item->SetOffsetInStack(varOffsetInStack);
            item->SetSizeInStack(varSizeInStack);
            item->SetSizeInHeap(varSizeInHeap);
            varOffsetInStack += item->GetSizeInStack();
            return item;
        }
        return nullptr;
    }

    void DomainTable::Debug() {

        cout.setf(ios::left);
        cout
                << "-------------------------------------------------------------------DomainTable-------------------------------------------------------------------------"
                << endl;
        cout.width(151);
        cout.unsetf(ios::left);
        cout << "|" << endl;
        cout.setf(ios::left);
        map<string, DomainTableItem *>::iterator it;
        cout.width(25);
        cout << "Index";
        cout.width(25);
        cout << "varName";
        cout.width(25);
        cout << "varOffsetInStack";
        cout.width(25);
        cout << "VarSizeInStack";
        cout.width(25);
        cout << "VarSizeInHeap";
        cout.width(25);
        cout << "VarType";
        cout.width(25);
        cout << '|' << endl;
        int count = 0;
        for (it = varTable.begin(); it != varTable.end(); it++) {
            cout.width(25);
            cout << count++;
            cout.width(25);
            cout << it->first;
            cout.width(25);
            cout << it->second->GetOffsetInStack();
            cout.width(25);
            cout << it->second->GetSizeInStack();
            cout.width(25);
            cout << it->second->GetSizeInHeap();
            cout.width(25);
            cout << it->second->GetType();
            cout.width(25);
            cout << '|' << endl;
        }
        cout
                << "-------------------------------------------------------------------------------------------------------------------------------------------------------"
                << endl << endl;

        cout
                << "-------------------------------------------------------------------TempDomainTable-------------------------------------------------------------------------"
                << endl;
        cout.width(151);
        cout.unsetf(ios::left);
        cout << "|" << endl;
        cout.setf(ios::left);
        cout.width(25);
        cout << "Index";
        cout.width(25);
        cout << "varName";
        cout.width(25);
        cout << "varOffsetInStack";
        cout.width(25);
        cout << "VarSizeInStack";
        cout.width(25);
        cout << "VarSizeInHeap";
        cout.width(25);
        cout << "VarType";
        cout.width(25);
        cout << '|' << endl;
        count = 0;
        for (it = tempVarTable.begin(); it != tempVarTable.end(); it++) {
            cout.width(25);
            cout << count++;
            cout.width(25);
            cout << it->first;
            cout.width(25);
            cout << it->second->GetOffsetInStack();
            cout.width(25);
            cout << it->second->GetSizeInStack();
            cout.width(25);
            cout << it->second->GetSizeInHeap();
            cout.width(25);
            cout << it->second->GetType();
            cout.width(25);
            cout << '|' << endl;
        }
        cout
                << "-------------------------------------------------------------------------------------------------------------------------------------------------------"
                << endl << endl;


    }

    int DomainTable::GetVarOffsetInStack() {
        return varOffsetInStack;
    }

    void DomainTable::ClearTempVarTable() {
        map<string, DomainTableItem *>::iterator it;
        for (it = tempVarTable.begin(); it != tempVarTable.end(); it++) {
            delete it->second;
        }
        tempVarTable.clear();
        TempVarOffsetInStack = 0;
    }


    DomainTableItem::DomainTableItem(string Type) : type(Type) {

    }

    void DomainTableItem::SetOffsetInStack(int offsetInStack) {

        this->offsetInStack = offsetInStack;

    }

    void DomainTableItem::SetSizeInStack(int sizeInStack) {

        this->sizeInStack = sizeInStack;
    }

    void DomainTableItem::SetSizeInHeap(int sizeInHeap) {

        this->sizeInHeap = sizeInHeap;
    }

    string DomainTableItem::GetType() {
        return type;
    }

    int DomainTableItem::GetOffsetInStack() {
        return offsetInStack;
    }

    int DomainTableItem::GetSizeInStack() {
        return sizeInStack;
    }

    int DomainTableItem::GetSizeInHeap() {
        return sizeInHeap;
    }
}
