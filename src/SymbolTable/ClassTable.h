//
// Created by freenos on 18-12-2.
//

#ifndef TEMPCODE_CLASSTABLE_H
#define TEMPCODE_CLASSTABLE_H

#include "string"

#include "map"

#include "vector"

#include "JudgeTypeSize.h"

using namespace std;

namespace  SymbolTable{

    class ClassTableItem {

        friend class ClassTable;

    public:
        enum Range {
            Field,
            Static
        };
        enum Auth {
            Public,
            Private
        };

        Range GetRange();
        Auth GetAuth();
        /*var*/
        int GetSize();
        /*var*/
        int GetOffset();
        /*var*/
        string GetVarType();

        /*fun*/
        int GetEntryPoint();
        /*fun*/
        string GetReturnType();
        /*fun*/
        void AddArg(string);
        /*fun*/
        int GetArgc();

        string GetArg(int idx);

    private:
        Range range;
        Auth auth;
        int size;
        int offset;
        string type;
        vector<string> argv;
        void SetOffset(int);
        void SetEntryPoint(int);
        void SetSize(int);
        explicit ClassTableItem(ClassTableItem::Range, ClassTableItem::Auth, string);
    };


    class ClassTable {

    public:
        ClassTableItem *InsertIntoVarTable(string, ClassTableItem::Range,  string);
        ClassTableItem *InsertIntoFunTable(string, ClassTableItem::Range,  string, int);
        ClassTableItem *FindFromVarTable(string);
        ClassTableItem *FindFromFunTable(string);
        int GetSize();
        ClassTable();
        void Debug();
    private:
        map<string, ClassTableItem *> varTable;
        map<string, ClassTableItem *> funTable;
        int varOffset;
        int classSize;
    };

}
#endif //TEMPCODE_CLASSTABLE_H
