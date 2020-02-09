//
// Created by freenos on 18-12-2.
//

#include "ClassTable.h"

using namespace SymbolTable;

namespace SymbolTable {

    ClassTableItem *
    ClassTable::InsertIntoVarTable(string varName, ClassTableItem::Range range, string varType) {


        if (varTable.find(varName) == varTable.end()) {
            ClassTableItem *item;
            if(varName.size()>=2&&varName[0]=='_'&&varName[1]=='_'){
                item = new ClassTableItem(range,ClassTableItem::Private, varType);
            } else{
                item = new ClassTableItem(range,ClassTableItem::Public, varType);
            }

            varTable[varName] = item;
            item->SetOffset(varOffset);
            int typeSize=JudgeTypeSize(varType);
            if(typeSize==-1)
                typeSize=sizeof(void*);
            varOffset+=typeSize;
            item->SetSize(typeSize);
            classSize+=typeSize;
            return item;
        }
        return nullptr;
    }

    ClassTableItem *
    ClassTable::InsertIntoFunTable(string funName, ClassTableItem::Range range, string returnType, int entryPoint) {

        if (funTable.find(funName) == funTable.end()) {
            ClassTableItem *item;
            if(funName.size()>=2&&funName[0]=='_'&&funName[1]=='_'){
                item = new ClassTableItem(range,ClassTableItem::Private, returnType);
            } else{
                item = new ClassTableItem(range,ClassTableItem::Public, returnType);
            }
            item->SetEntryPoint(entryPoint);
            funTable[funName] = item;
            return item;
        }
        return nullptr;
    }

    ClassTableItem *ClassTable::FindFromFunTable(string funName) {
        if (funTable.find(funName) != funTable.end()) {
            return funTable[funName];
        }
        return nullptr;
    }

    ClassTableItem *ClassTable::FindFromVarTable(string varName) {
        if (varTable.find(varName) != varTable.end()) {
            return varTable[varName];
        }
        return nullptr;
    }

    ClassTable::ClassTable() {
        varOffset = 0;
        classSize=0;
    }

    int ClassTable::GetSize() {
        return classSize;
    }

    void ClassTable::Debug() {
        map<string, ClassTableItem *>::iterator it;

        cout.setf(ios::left);

        cout<<"-------------------------------------------------------------------------------VarTable-----------------------------------------------------------------------------------------"<<endl;
        cout.unsetf(ios::left);
        cout.width(176);
        cout<<'|'<<endl;
        cout.setf(ios::left);
        cout.width(25);
        cout<<"index";
        cout.width(25);
        cout<<"VarName";
        cout.width(25);
        cout<<"VarRange";
        cout.width(25);
        cout<<"VarAuth";
        cout.width(25);
        cout<<"VarSize";
        cout.width(25);
        cout<<"VarOffset";
        cout.width(25);
        cout<<"VarType";
        cout.width(25);
        cout<<'|'<<endl;

        int count=0;

        for(it=varTable.begin();it!=varTable.end();it++){
            cout.width(25);
            cout<<count++;
            cout.width(25);
            cout<<it->first;
            cout.width(25);
            if(it->second->GetRange()==ClassTableItem::Field)
                cout<<"Field";
            else
                cout<<"Static";
            cout.width(25);
            if(it->second->GetAuth()==ClassTableItem::Public)
                cout<<"Public";
            else
                cout<<"Private";
            cout.width(25);
            cout<<it->second->GetSize();
            cout.width(25);
            cout<<it->second->GetOffset();
            cout.width(25);
            cout<<it->second->GetVarType();
            cout.width(25);
            cout<<'|'<<endl;
        }
        cout.unsetf(ios::left);
        cout.width(176);
        cout<<'|'<<endl;
        cout.setf(ios::left);
        cout<<"-------------------------------------------------------------------------------FunTable-----------------------------------------------------------------------------------------"<<endl<<endl;
        cout.width(25);
        cout<<"index";
        cout.width(25);
        cout<<"FunName";
        cout.width(25);
        cout<<"FunRange";
        cout.width(25);
        cout<<"FunAuth";
        cout.width(25);
        cout<<"VarEntryPoint";
        cout.width(25);
        cout<<"ReturnType";
        cout.width(25);
        cout<<"Argv"<<endl;

        count=0;
        for(it=funTable.begin();it!=funTable.end();it++){
            cout.width(25);
            cout<<count++;
            cout.width(25);
            cout<<it->first;
            cout.width(25);
            if(it->second->GetRange()==ClassTableItem::Field)
                cout<<"Field";
            else
                cout<<"Static";
            cout.width(25);
            if(it->second->GetAuth()==ClassTableItem::Public)
                cout<<"Public";
            else
                cout<<"Private";
            cout.width(25);
            cout<<it->second->GetEntryPoint();
            cout.width(25);
            cout<<it->second->GetReturnType();
            cout<<"(";
            for(int i=0;i<it->second->argv.size();i++){
                if(i!=it->second->argv.size())
                    cout<<it->second->argv[i]<<',';
                else
                    cout<<it->second->argv[i];

                }
            cout<<")"<<endl;
            }
        cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    }




    ClassTableItem::ClassTableItem(ClassTableItem::Range range, ClassTableItem::Auth auth, string type) {

        this->range = range;
        this->auth = auth;
        this->type = type;
    }

    int ClassTableItem::GetSize() {

        return size;
    }

    ClassTableItem::Range ClassTableItem::GetRange() {
        return range;
    }

    ClassTableItem::Auth ClassTableItem::GetAuth() {
        return auth;
    }

    void ClassTableItem::SetOffset(int offset) {
        this->offset = offset;
    }

    int ClassTableItem::GetEntryPoint() {
        return offset;
    }

    int ClassTableItem::GetOffset() {
        return offset;
    }

    void ClassTableItem::SetEntryPoint(int entryPoint) {
        this->offset = entryPoint;
    }

    void ClassTableItem::SetSize(int size) {
        this->size = size;
    }


    void ClassTableItem::AddArg(string arg) {
        argv.push_back(arg);
    }


    int ClassTableItem::GetArgc() {
        return argv.size();
    }

    string ClassTableItem::GetVarType() {
        return type;
    }

    string ClassTableItem::GetReturnType() {
        return type;
    }

    string ClassTableItem::GetArg(int idx) {
        if(idx>=argv.size()){
            cout<<"GetArg:Out of range."<<endl;
            return string();
        }
        return argv.at(idx);
    }

}