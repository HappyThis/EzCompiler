//
// Created by freenos on 18-12-11.
//

#include "CodeContainer.h"


Code *CodeContainer::At(int idx) {

    if (idx >= codeArray.size()) {
        cout << "Index out of range" << endl;
        return nullptr;
    }

    return codeArray.at(idx);


}

bool CodeContainer::Insert(int idx, Code *code) {

    if (idx > codeArray.size()) {
        cout << "Index out of range" << endl;
        return false;
    }
    //   code->referenceCount++;
    if (idx == codeArray.size()) {
        codeArray.push_back(code);
    } else {
        codeArray.insert(codeArray.begin() + idx, code);
    }

    return true;
}

bool CodeContainer::Insert(int idx) {
    if (idx > codeArray.size()) {
        cout << "Index out of range" << endl;
        return false;
    }
    Code *code = new Code;
//    code->referenceCount++;
    if (idx == codeArray.size()) {
        codeArray.push_back(code);
    } else {
        codeArray.insert(codeArray.begin() + idx, code);
    }


    return true;
}

bool CodeContainer::Insert(int idx, CodeContainer *codeContainer, int startPoint, int length) {

    if (idx > codeArray.size()) {
        cout << "Insert:Index out of range" << endl;
        return false;
    }

    if (startPoint + length > codeContainer->Size()) {
        cout << "Insert:Index out of range" << endl;
        return false;
    }
    int sz = codeArray.size();
    for (int i = startPoint; i < startPoint + length; i++) {
        if (idx == sz) {
            codeArray.push_back(codeContainer->At(i));
        } else {
            codeArray.insert(codeArray.begin() + idx + i - startPoint, codeContainer->At(i));
        }
    }


    return true;
}


bool CodeContainer::Erase(int idx) {

    if (codeArray.empty()) {
        return true;
    }

    if (idx >= codeArray.size()) {
        cout << "Erase:Index out of range" << endl;
        return false;
    }
    codeArray.erase(codeArray.begin() + idx);

    return false;
}

bool CodeContainer::Erase(int idxl, int idxr) {
    if (codeArray.empty()||idxl==idxr) {
        return true;
    }

    if (idxl >= codeArray.size() || idxr > codeArray.size()) {
        cout << "Earse:Index out of range" << endl;
        return false;
    }

    for (int i = idxl; i <= idxr; i++) {
        //       codeArray.at(i)->referenceCount--;
    }

    codeArray.erase(codeArray.begin() + idxl, codeArray.begin() + idxr);

    return true;
}

bool CodeContainer::Move(int targetIdx, int sourceIdx) {

    codeArray.insert(codeArray.begin() + targetIdx, codeArray.at(sourceIdx));

    if (sourceIdx >= targetIdx) {
        codeArray.erase(codeArray.begin() + sourceIdx + 1);
    } else {
        codeArray.erase(codeArray.begin() + sourceIdx);
    }
}

int CodeContainer::Size() {

    return codeArray.size();
}

CodeContainer::CodeContainer() {
    // codeArray.push_back(new Code);
}

CodeContainer::~CodeContainer() {

}

void CodeContainer::PushBackCode() {

    Code *code = new Code;
//    code->referenceCount++;
    codeArray.push_back(code);
}

void CodeContainer::PushBackCode(Code *code) {
    //   code->referenceCount++;
    codeArray.push_back(code);
}

void CodeContainer::PushBackCode(CodeContainer *codeContainer) {

    for (int i = 0; i < codeContainer->Size(); i++) {

//        codeContainer->At(i)->referenceCount++;
        PushBackCode(codeContainer->At(i));

    }
}

void CodeContainer::Debug() {


    int argInt;
    char argChar;
    double argDouble;
    bool argBool;
    int idx;

    for (int i = 0; i < codeArray.size(); i++) {
	printf("%d:",i);
        switch (codeArray.at(i)->op) {
            case ADD:
                printf("(+");
                break;
            case SUB:
                printf("(-");
                break;
            case MUL:
                printf("(*");
                break;
            case DIV:
                printf("(/");
                break;
            case NOT:
                printf("(~");
                break;
            case NEG:
                printf("(-");
                break;
            case AND:
                printf("(&");
                break;
            case XOR:
                printf("(^");
                break;
            case MOD:
                printf("(%%");
                break;
            case OR:
                printf("(|");
                break;
            case LNE:
                printf("(!=");
                break;
            case LEQ:
                printf("(==");
                break;
            case LGT:
                printf("(>");
                break;
            case LGE:
                printf("(>=");
                break;
            case LLT:
                printf("(<");
                break;
            case LLE:
                printf("(<=");
                break;
            case LAND:
                printf("(&&");
                break;
            case LOR:
                printf("(||");
                break;
            case ASG:
                printf("(=");
                break;
            case CALL:
                printf("(CALL");
                break;
            case PARAM:
                printf("(PARAM");
                break;
            case RET:
                printf("(RET");
                break;
            case NEW:
                printf("(NEW");
                break;
            case JMP:
                printf("(JMP");
                break;
            case JLT:
                printf("(J<");
                break;
            case JLE:
                printf("(J<=");
                break;
            case JNE:
                printf("(J!=");
                break;
            case JEQ:
                printf("(J==");
                break;
            case JGT:
                printf("(J>");
                break;
            case JGE:
                printf("(J>=");
                break;
            default:;
        }
        switch (codeArray.at(i)->arg1ParseMethod) {
            case StackToBool:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", idx, "StackToBool");
                break;
            case StackToBool_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "StackToBool");
                break;
            case StackToChar:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", idx, "StackToChar");
                break;
            case StackToChar_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "StackToChar");
                break;
            case StackToInt:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", idx, "StackToInt");
                break;
            case StackToInt_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "StackToInt");
                break;
            case StackToDouble:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", idx, "StackToDouble");
                break;
            case StackToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "StackToDouble");
                break;
            case StackToRef:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", idx, "StackToRef");
                break;
            case StackToRef_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "StackToRef");
                break;
            case HeapToBool_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToBool");
                break;
            case HeapToInt_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToInt");
                break;
            case HeapToChar_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToChar");
                break;
            case HeapToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToDouble");
                break;
            case HeapToRef_T:
                memcpy(&idx, codeArray.at(i)->arg1, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToRef");
                break;
            case ToBool:
                memcpy(&argBool, codeArray.at(i)->arg1, sizeof(bool));
                if (argBool) {
                    printf(",true:%s", "ToBool");
                } else {
                    printf(",false:%s", "ToBool");
                }
                break;
            case ToChar:
                memcpy(&argChar, codeArray.at(i)->arg1, sizeof(char));
                printf(",\'%c\':%s", argChar, "ToChar");
                break;
            case ToInt:
                memcpy(&argInt, codeArray.at(i)->arg1, sizeof(int));
                printf(",%d:%s", argInt, "ToInt");
                break;
            case ToDouble:
                memcpy(&argDouble, codeArray.at(i)->arg1, sizeof(double));
                printf(",%f:%s", argDouble, "ToDouble");
                break;
            case ToString:
                printf(",\"%s\":%s", codeArray.at(i)->arg1, "ToString");
                break;
            case NoMethod:
                printf(",_");
                break;
            default:;
        }

        switch (codeArray.at(i)->arg2ParseMethod) {
            case StackToBool:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", idx, "StackToBool");
                break;
            case StackToBool_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "StackToBool");
                break;
            case StackToChar:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", idx, "StackToChar");
                break;
            case StackToChar_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "StackToChar");
                break;
            case StackToInt:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", idx, "StackToInt");
                break;
            case StackToInt_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "StackToInt");
                break;
            case StackToDouble:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", idx, "StackToDouble");
                break;
            case StackToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "StackToDouble");
                break;
            case StackToRef:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", idx, "StackToRef");
                break;
            case StackToRef_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "StackToRef");
                break;
            case HeapToBool_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToBool");
                break;
            case HeapToInt_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToInt");
                break;
            case HeapToChar_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToChar");
                break;
            case HeapToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToDouble");
                break;
            case HeapToRef_T:
                memcpy(&idx, codeArray.at(i)->arg2, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToRef");
                break;
            case ToBool:
                memcpy(&argBool, codeArray.at(i)->arg2, sizeof(bool));
                if (argBool) {
                    printf(",true:%s", "ToBool");
                } else {
                    printf(",false:%s", "ToBool");
                }
                break;
            case ToChar:
                memcpy(&argChar, codeArray.at(i)->arg2, sizeof(char));
                printf(",\'%c\':%s", argChar, "ToChar");
                break;
            case ToInt:
                memcpy(&argInt, codeArray.at(i)->arg2, sizeof(int));
                printf(",%d:%s", argInt, "ToInt");
                break;
            case ToDouble:
                memcpy(&argDouble, codeArray.at(i)->arg2, sizeof(double));
                printf(",%f:%s", argDouble, "ToDouble");
                break;
            case ToString:
                printf(",\"%s\":%s", codeArray.at(i)->arg2, "ToString");
                break;
            case CallToDouble:
                printf(",%s,_", "CallToDouble");
                break;
            case CallToInt:
                printf(",%s,_", "CallToInt");
                break;
            case CallToChar:
                printf(",%s,_", "CallToChar");
                break;
            case CallToBool:
                printf(",%s,_", "CallToBool");
                break;
            case CallToRef:
                printf(",%s,_", "CallToRef");
                break;
            case NoMethod:
                printf(",_");
                break;
            default:;
        }

        switch (codeArray.at(i)->arg3ParseMethod) {
            case StackToBool:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", idx, "StackToBool");
                break;
            case StackToBool_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "StackToBool");
                break;
            case StackToChar:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", idx, "StackToChar");
                break;
            case StackToChar_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "StackToChar");
                break;
            case StackToInt:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", idx, "StackToInt");
                break;
            case StackToInt_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "StackToInt");
                break;
            case StackToDouble:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", idx, "StackToDouble");
                break;
            case StackToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "StackToDouble");
                break;
            case StackToRef:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", idx, "StackToRef");
                break;
            case StackToRef_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "StackToRef");
                break;
            case HeapToBool_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToBool");
                break;
            case HeapToInt_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToInt");
                break;
            case HeapToChar_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToChar");
                break;
            case HeapToDouble_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToDouble");
                break;
            case HeapToRef_T:
                memcpy(&idx, codeArray.at(i)->arg3, sizeof(int));
                printf(",[%d]:%s", idx, "HeapToRef");
                break;
            case ToBool:
                memcpy(&argBool, codeArray.at(i)->arg3, sizeof(bool));
                if (argBool) {
                    printf(",true:%s", "ToBool");
                } else {
                    printf(",false:%s", "ToBool");
                }
                break;
            case ToChar:
                memcpy(&argChar, codeArray.at(i)->arg3, sizeof(char));
                printf(",\'%c\':%s", argChar, "ToChar");
                break;
            case ToInt:
                memcpy(&argInt, codeArray.at(i)->arg3, sizeof(int));
                printf(",%d:%s", argInt, "ToInt");
                break;
            case ToDouble:
                memcpy(&argDouble, codeArray.at(i)->arg3, sizeof(double));
                printf(",%f:%s", argDouble, "ToDouble");
                break;
            case ToString:
                printf(",\"%s\":%s", codeArray.at(i)->arg3, "ToString");
                break;
            case NoMethod:
                printf(",_");
                break;
            default:;
        }
        switch (codeArray.at(i)->Bind) {
            case StackToRef_T:
                printf(",[%d]:%s)\n", codeArray.at(i)->arg4, "StackToRef");
                break;
            case StackToRef:
                printf(",%d:%s)\n", codeArray.at(i)->arg4, "StackToRef");
                break;
            case NoMethod:
                printf(",_)\n");
                break;
            default:;
        }
    }

}

bool CodeContainer::FillInOp(Operator op, int idx) {
    Code *code;
    if (idx < 0) {

        idx = codeArray.size() - 1;
    }
    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    code->op = op;

    return true;
}

bool CodeContainer::FillInArg1(void *in, int size, int idx) {
    Code *code;
    if (idx < 0) {

        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    memcpy(code->arg1, in, size);
    return true;
}

bool CodeContainer::FillInArg2(void *in, int size, int idx) {
    Code *code;
    if (idx < 0) {

        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    memcpy(code->arg2, in, size);
    return true;
}

bool CodeContainer::FillInArg3(void *in, int size, int idx) {
    Code *code;
    if (idx < 0) {

        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    memcpy(code->arg3, in, size);
    return true;
}

bool CodeContainer::FillInArg1ParseMethod(ArgParseMethod argParseMethod, int idx) {
    Code *code;
    if (idx < 0) {
        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);

    code->arg1ParseMethod = argParseMethod;

    return true;
}

bool CodeContainer::FillInArg2ParseMethod(ArgParseMethod argParseMethod, int idx) {
    Code *code;
    if (idx < 0) {
        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    code->arg2ParseMethod = argParseMethod;

    return true;
}

bool CodeContainer::FillInArg3ParseMethod(ArgParseMethod argParseMethod, int idx) {
    Code *code;
    if (idx < 0) {
        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    code->arg3ParseMethod = argParseMethod;

    return true;
}

CodeContainer *CodeContainer::codeContainer = new CodeContainer();

bool CodeContainer::FillInArg4(int in, int idx) {
    Code *code;
    if (idx < 0) {

        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    code->arg4 = in;
    return true;
}

bool CodeContainer::FillInArg4ParseMethod(ArgParseMethod argParseMethod, int idx) {
    Code *code;
    if (idx < 0) {
        idx = codeArray.size() - 1;
    }

    if (idx >= codeArray.size() && idx < 0) {
        cout << "Index out of range" << endl;
        return false;
    }
    code = codeArray.at(idx);
    code->Bind = argParseMethod;

    return true;
}

void CodeContainer::Clear() {
    codeArray.clear();

}
