//
// Created by ezos on 19-1-8.
//

#include "EzVm.h"

bool EzVm::ReadSourceFile(string filePath) {
    ifstream inputFile;
    inputFile.open(filePath, ios::in | ios::binary);
    Code item;
    /*加载代码*/
    if (inputFile) {
        inputFile.read((char *) &header, sizeof(Header));
        int magicNumber = ~'E' + 'z' - 'C' * 'o' / 'm' ^ 'p' | 'i' & 'l' % 'e' + 'r';
        if (header.magicNumber != magicNumber) {
            cout << "File format is incorrect." << endl;
            return false;
        }
        AnalyzerInit();
        while (!inputFile.eof()) {
            inputFile.read((char *) &item, sizeof(Code));
            if (inputFile.gcount() > 0) {
                codeArray.push_back(item);
            }
        }
        /*调用分析器*/
        Analyzer();
    } else {
        cout << "Fail to open the file.";
        return false;
    }
    return true;
}

void EzVm::Analyzer() {
    int offset;
    for (; csip < codeArray.size(); csip++) {
        Code code = codeArray.at(csip);
        switch (code.op) {
            case ADD:
            case SUB:
            case MUL:
            case DIV:
                AnalyzerArith(code);
                break;
            case LNE:
            case LEQ:
            case LGT:
            case LGE:
            case LLT:
            case LLE:
            case LAND:
            case LOR:
            case AND:
            case XOR:
            case MOD:
            case OR:
                AnalyzerBoolArith(code);
                break;
            case NOT:
            case NEG:
                AnalyzerNegAndNot(code);
                break;
            case JMP:
                memcpy(&offset, code.arg3, sizeof(int));
                csip = offset - 1;
                break;
            case JEQ:
            case JNE:
            case JGT:
            case JLT:
            case JGE:
            case JLE:
                AnalyzerJmp(code);
                break;
            case ASG:
                AnalyzerAssign(code);
                break;
            case NEW:
                AnalyzerNew(code);
                break;
            case PARAM:
                AnalyzerParam(code);
                break;
            case CALL:
                AnalyzerCall(code, csip);
                break;
            case RET:
                AnalyzerRet(code);
                break;
        }
    }
}

EzVm *EzVm::ezVm = new EzVm();

void EzVm::AnalyzerRet(Code code) {
    recordStack.Pop();
    if (recordStack.GetRemovedRecord().GetCallPoint() < 0) {
        cout << "Process finished" << endl;
        return;
    }
    int addr;
    int intValue;
    bool boolValue;
    char charValue;
    double doubleValue;
    void *refValue;

    switch (code.arg1ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg1, sizeof(bool));
            break;
        case ToChar:
            memcpy(&charValue, code.arg1, sizeof(char));
            break;
        case ToInt:
            memcpy(&intValue, code.arg1, sizeof(int));
            break;
        case ToDouble:
            memcpy(&doubleValue, code.arg1, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetRemovedRecord().ReadToBool_D(addr);
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetRemovedRecord().ReadToBool_T(addr);
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetRemovedRecord().ReadToChar_D(addr);
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetRemovedRecord().ReadToChar_T(addr);
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetRemovedRecord().ReadToInt_D(addr);
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetRemovedRecord().ReadToInt_T(addr);
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetRemovedRecord().ReadToDouble_D(addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetRemovedRecord().ReadToDouble_T(addr);
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue = recordStack.GetRemovedRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue = recordStack.GetRemovedRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetRemovedRecord().ReadToRefToBool_T(addr);
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetRemovedRecord().ReadToRefToChar_T(addr);
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetRemovedRecord().ReadToRefToInt_T(addr);
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetRemovedRecord().ReadToRefToDouble_T(addr);
            break;
        case NoMethod:
            break;
    }


    ActivityRecord removeRecord = recordStack.GetRemovedRecord();
    switch (removeRecord.GetRetInfo().retParseMethod) {

        case StackToBool_T:
            recordStack.GetTopRecord().BoolToWrite_T(boolValue, removeRecord.GetRetInfo().retPoint);
            break;

        case StackToChar_T:
            recordStack.GetTopRecord().CharToWrite_T(charValue, removeRecord.GetRetInfo().retPoint);
            break;

        case StackToInt_T:
            recordStack.GetTopRecord().IntToWrite_T(intValue, removeRecord.GetRetInfo().retPoint);
            break;

        case StackToDouble_T:
            recordStack.GetTopRecord().DoubleToWrite_T(doubleValue, removeRecord.GetRetInfo().retPoint);
            break;

        case StackToRef_T:
            recordStack.GetTopRecord().RefToWrite_T(refValue, removeRecord.GetRetInfo().retPoint);
            break;

        case NoMethod:
            break;
    }
    csip = recordStack.GetRemovedRecord().GetCallPoint();

}

void EzVm::AnalyzerCall(Code code, int callPoint) {
    if (!recordStack.IsNewRecord())
        recordStack.CreateRecord();

    recordStack.GetNewRecord().SetCallPoint(callPoint);
    /*关联实例填写*/
    void *bindInstance;
    switch (code.Bind) {
        case StackToRef:
            bindInstance = recordStack.GetTopRecord().ReadToRef_D(code.arg4);
            break;
        case StackToRef_T:
            bindInstance = recordStack.GetTopRecord().ReadToRef_T(code.arg4);
            break;
    }
    recordStack.GetNewRecord().RefToWrite_D(bindInstance, 0);
    /*填写返回点*/
    int retPoint;
    memcpy(&retPoint, code.arg3, sizeof(int));
    recordStack.GetNewRecord().SetRetInfo(retPoint, code.arg3ParseMethod);
    recordStack.SetNewRecord();

    int entryPoint;
    memcpy(&entryPoint, code.arg1, sizeof(int));
    csip = entryPoint - 1;

}

void EzVm::AnalyzerInit() {

    csip = header.entryPoint;
    void *mainClassInstance = new unsigned char[header.mainClassSize > 0 ? header.mainClassSize : 4];
    recordStack.CreateRecord();
    /*调用点为-1的main返回时直接结束程序*/
    recordStack.GetNewRecord().SetCallPoint(-1);
    /*实例化main所在的类*/
    recordStack.GetNewRecord().RefToWrite_D(mainClassInstance, 0);

    recordStack.SetNewRecord();


}

void EzVm::AnalyzerParam(Code code) {
    if (!recordStack.IsNewRecord())
        recordStack.CreateRecord();
    int intValue = 0;
    char charValue = '\0';
    bool boolValue = false;
    double doubleValue = 0;
    void *refValue = nullptr;
    int addr;
    switch (code.arg1ParseMethod) {
        case ToBool:
            memcpy(&boolValue, code.arg1, sizeof(bool));
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    break;
                case CallToChar:
                    charValue = boolValue;
                    break;
                case CallToInt:
                    intValue = boolValue;
                    break;
                case CallToDouble:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case ToChar:
            memcpy(&charValue, code.arg1, sizeof(char));
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = charValue;
                    break;
                case CallToChar:
                    break;
                case CallToInt:
                    intValue = charValue;
                    break;
                case CallToDouble:
                    doubleValue = charValue;
                    break;
            }
            break;
        case ToInt:
            memcpy(&intValue, code.arg1, sizeof(int));
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(intValue);
                    break;
                case CallToInt:
                    break;
                case CallToDouble:
                    doubleValue = intValue;
                    break;
            }
            break;
        case ToDouble:
            memcpy(&doubleValue, code.arg1, sizeof(double));
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case CallToInt:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case CallToDouble:
                    break;
            }
            break;
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    break;
                case CallToChar:
                    charValue = boolValue;
                    break;
                case CallToInt:
                    intValue = boolValue;
                    break;
                case CallToDouble:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    break;
                case CallToChar:
                    charValue = boolValue;
                    break;
                case CallToInt:
                    intValue = boolValue;
                    break;
                case CallToDouble:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = charValue;
                    break;
                case CallToChar:
                    break;
                case CallToInt:
                    intValue = charValue;
                    break;
                case CallToDouble:
                    doubleValue = charValue;
                    break;
            }
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = charValue;
                    break;
                case CallToChar:
                    break;
                case CallToInt:
                    intValue = charValue;
                    break;
                case CallToDouble:
                    doubleValue = charValue;
                    break;
            }
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(intValue);
                    break;
                case CallToInt:
                    break;
                case CallToDouble:
                    doubleValue = intValue;
                    break;
            }
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(intValue);
                    break;
                case CallToInt:
                    break;
                case CallToDouble:
                    doubleValue = intValue;
                    break;
            }
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case CallToInt:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case CallToDouble:
                    break;
            }
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case CallToInt:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case CallToDouble:
                    break;
            }
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    break;
                case CallToChar:
                    charValue = boolValue;
                    break;
                case CallToInt:
                    intValue = boolValue;
                    break;
                case CallToDouble:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = charValue;
                    break;
                case CallToChar:
                    break;
                case CallToInt:
                    intValue = charValue;
                    break;
                case CallToDouble:
                    doubleValue = charValue;
                    break;
            }
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(intValue);
                    break;
                case CallToInt:
                    break;
                case CallToDouble:
                    doubleValue = intValue;
                    break;
            }
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToRefToDouble_D(addr);
            switch (code.arg2ParseMethod) {
                case CallToBool:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case CallToChar:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case CallToInt:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case CallToDouble:
                    break;
            }
            break;
        case ToString:
            break;
        case HeapToRef_T:
            break;
        case NoMethod:
            break;
    }
    switch (code.arg2ParseMethod) {
        case CallToBool:
            recordStack.GetNewRecord().BoolToWrite_D(boolValue,
                                                     recordStack.GetNewRecord().GetParamOffset(sizeof(bool)));
            break;
        case CallToChar:
            recordStack.GetNewRecord().CharToWrite_D(charValue,
                                                     recordStack.GetNewRecord().GetParamOffset(sizeof(char)));
            break;
        case CallToInt:
            recordStack.GetNewRecord().IntToWrite_D(intValue,
                                                    recordStack.GetNewRecord().GetParamOffset(sizeof(int)));
            break;
        case CallToDouble:
            recordStack.GetNewRecord().DoubleToWrite_D(doubleValue,
                                                       recordStack.GetNewRecord().GetParamOffset(sizeof(double)));
            break;
        case CallToRef:
            recordStack.GetNewRecord().RefToWrite_D(refValue,
                                                    recordStack.GetNewRecord().GetParamOffset(sizeof(void *)));
            break;
    }
}

EzVm::EzVm() {

    memory = new unsigned char[1 * 1024 * 1024];

}

void *EzVm::Allocator(int sz) {
    int result = sz;
    currentMemIdx += sz;
    return memory + result;
}

void EzVm::AnalyzerNew(Code code) {

    int sz;

    memcpy(&sz, code.arg1, sizeof(int));

    int addr;

    memcpy(&addr, code.arg2, sizeof(int));

    recordStack.GetTopRecord().RefToWrite_T(Allocator(sz), addr);

}

void EzVm::AnalyzerAssign(Code code) {

    int intValue = 0;
    char charValue = '\0';
    bool boolValue = false;
    double doubleValue = 0;
    void *refValue = nullptr;
    int addr;

    switch (code.arg2ParseMethod) {
        case ToBool:
            memcpy(&boolValue, code.arg2, sizeof(bool));
            break;
        case ToChar:
            memcpy(&charValue, code.arg2, sizeof(char));
            break;
        case ToInt:
            memcpy(&intValue, code.arg2, sizeof(int));
            break;
        case ToDouble:
            memcpy(&doubleValue, code.arg2, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = boolValue;
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = boolValue;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = boolValue;
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = boolValue;
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case StackToChar:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = charValue;
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = charValue;
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = charValue;
                    break;
            }
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            switch (code.arg1ParseMethod) {
                doubleValue = intValue;
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = charValue;
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = charValue;
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = charValue;
                    break;
            }
            break;
        case StackToInt:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(intValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = intValue;
                    break;
            }
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(intValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = intValue;
                    break;
            }
            break;
        case StackToDouble:
            memcpy(&addr, code.arg2, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    break;
            }
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    break;
            }
            break;
        case StackToRef:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = boolValue;
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = boolValue;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = boolValue;
                    break;
            }
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = charValue;
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = charValue;
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = charValue;
                    break;
            }
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_D(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(intValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(intValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    doubleValue = intValue;
                    break;
            }
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            switch (code.arg1ParseMethod) {
                case StackToBool:
                case HeapToBool_T:
                case StackToBool_T:
                    boolValue = static_cast<bool>(doubleValue);
                    break;
                case StackToChar:
                case StackToChar_T:
                case HeapToChar_T:
                    charValue = static_cast<char>(doubleValue);
                    break;
                case StackToInt:
                case StackToInt_T:
                case HeapToInt_T:
                    intValue = static_cast<int>(doubleValue);
                    break;
                case StackToDouble:
                case StackToDouble_T:
                case HeapToDouble_T:
                    break;
            }
            break;
        case HeapToRef_T:
            break;
        case ToString:
            break;
        case NoMethod:
            break;
    }
    int *pInt;
    double *pDouble;
    char *pChar;
    bool *pBool;
    void *pRef;


    switch (code.arg1ParseMethod) {
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            pBool = recordStack.GetTopRecord().ReadToBool_D(addr);
            (*pBool) = boolValue;
            /*存放表达式产生值*/
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(boolValue, addr);
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pBool = recordStack.GetTopRecord().ReadToBool_T(addr);
            (*pBool) = boolValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(boolValue, addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pBool = recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            (*pBool) = boolValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(boolValue, addr);
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            pChar = recordStack.GetTopRecord().ReadToChar_D(addr);
            (*pChar) = charValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().CharToWrite_T(charValue, addr);
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pChar = recordStack.GetTopRecord().ReadToChar_T(addr);
            (*pChar) = charValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().CharToWrite_T(charValue, addr);
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pChar = recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            (*pChar) = charValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().CharToWrite_T(charValue, addr);
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            pInt = recordStack.GetTopRecord().ReadToInt_D(addr);
            (*pInt) = intValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(intValue, addr);
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pInt = recordStack.GetTopRecord().ReadToInt_T(addr);
            (*pInt) = intValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(intValue, addr);
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pInt = recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            (*pInt) = intValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(intValue, addr);
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            pDouble = recordStack.GetTopRecord().ReadToDouble_D(addr);
            (*pDouble) = doubleValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(doubleValue, addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pDouble = recordStack.GetTopRecord().ReadToDouble_T(addr);
            (*pDouble) = doubleValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(doubleValue, addr);
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pDouble = recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            (*pDouble) = doubleValue;
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(doubleValue, addr);
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            recordStack.GetTopRecord().RefToWrite_D(refValue, addr);
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().RefToWrite_T(refValue, addr);
            break;
        case StackToRef_T:
            /*设计失误-暂不支持*/
            //  memcpy(&addr, code.arg1, sizeof(int));
            //  pRef=recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
    }
}

int EzVm::SearchSize(void *key) {

    return refSize[key];
}

void EzVm::AnalyzerJmp(Code code) {
    /*全部转换为浮点数进行运算*/
    double arg1;
    double arg2;
    int intValue;
    char charValue;
    bool boolValue;
    void *refValue1;
    void *refValue2;
    int addr;
    switch (code.arg1ParseMethod) {
        case ToBool:
            memcpy(&boolValue, code.arg1, sizeof(bool));
            arg1 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg1, sizeof(char));
            arg1 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg1, sizeof(int));
            arg1 = intValue;
            break;
        case ToDouble:
            memcpy(&arg1, code.arg1, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg1 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg1 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg1 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg1 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg1 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg1 = intValue;
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue1 = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue1 = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg1 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg1 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg1 = intValue;
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            break;
    }

    switch (code.arg2ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg2, sizeof(bool));
            arg2 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg2, sizeof(char));
            arg2 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg2, sizeof(int));
            arg2 = intValue;
            break;
        case ToDouble:
            memcpy(&arg1, code.arg2, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg2 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg2 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg2 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg2 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg2 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg2 = intValue;
            break;
        case StackToDouble:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            break;
        case StackToRef:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue2 = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue2 = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg2 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg2 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg2 = intValue;
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            break;
    }

    switch (code.op) {
        case JEQ:
            if(code.arg1ParseMethod==StackToRef||code.arg1ParseMethod==StackToRef_T){
                if (refValue1 == refValue2) {
                    memcpy(&csip, code.arg3, sizeof(int));
                    csip--;
                }
            }else{
                if (arg1 == arg2) {
                    memcpy(&csip, code.arg3, sizeof(int));
                    csip--;
                }
            }
            break;
        case JNE:
            if(code.arg1ParseMethod==StackToRef||code.arg1ParseMethod==StackToRef_T){
                if (refValue1 != refValue2) {
                    memcpy(&csip, code.arg3, sizeof(int));
                    csip--;
                }
            }else{
                if (arg1 != arg2) {
                    memcpy(&csip, code.arg3, sizeof(int));
                    csip--;
                }
            }
            break;
        case JGT:
            if (arg1 > arg2) {
                memcpy(&csip, code.arg3, sizeof(int));
                csip--;
            }
            break;
        case JLT:
            if (arg1 < arg2) {
                memcpy(&csip, code.arg3, sizeof(int));
                csip--;
            }
            break;
        case JGE:
            if (arg1 >= arg2) {
                memcpy(&csip, code.arg3, sizeof(int));
                csip--;
            }
            break;
        case JLE:
            if (arg1 <= arg2) {
                memcpy(&csip, code.arg3, sizeof(int));
                csip--;
            }
            break;
    }
}

void EzVm::AnalyzerArith(Code code) {
    /*全部转换为浮点数进行运算*/
    double arg1;
    double arg2;
    int intValue;
    char charValue;
    bool boolValue;
    void *pRef;
    int addr;
    switch (code.arg1ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg1, sizeof(bool));
            arg1 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg1, sizeof(char));
            arg1 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg1, sizeof(int));
            arg1 = intValue;
            break;
        case ToDouble:
            memcpy(&arg1, code.arg1, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg1 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg1 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg1 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg1 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg1 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg1 = intValue;
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            pRef = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg1, sizeof(int));
            pRef = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg1 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg1 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg1 = intValue;
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            arg1 = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            break;
    }

    switch (code.arg2ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg2, sizeof(bool));
            arg2 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg2, sizeof(char));
            arg2 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg2, sizeof(int));
            arg2 = intValue;
            break;
        case ToDouble:
            memcpy(&arg1, code.arg2, sizeof(double));
            break;
        case StackToBool:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg2 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg2 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg2 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg2 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg2 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg2 = intValue;
            break;
        case StackToDouble:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            break;
        case StackToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg2 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg2 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg2 = intValue;
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg2, sizeof(int));
            arg2 = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            break;
    }

    switch (code.op) {

        case ADD:
            /*visit表达式相关*/
            if (code.arg1ParseMethod == StackToRef || code.arg1ParseMethod == StackToRef_T) {
                switch (code.arg3ParseMethod) {
                    case HeapToBool_T:
                        pRef = pRef + intValue;
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().BoolRefToWrite_T((bool *) pRef, addr);
                        break;
                    case HeapToChar_T:
                        pRef = pRef + intValue;
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().CharRefToWrite_T((char *) pRef, addr);
                        break;
                    case HeapToInt_T:
                        pRef = pRef + intValue;
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().IntRefToWrite_T((int *) pRef, addr);
                        break;
                    case HeapToDouble_T:
                        pRef = pRef + intValue;
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().DoubleRefToWrite_T((double *) pRef, addr);
                        break;
                    case HeapToRef_T:
                        pRef = pRef + intValue;
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().RefToWrite_T(pRef, addr);
                        break;
                }
            } else {
                switch (code.arg3ParseMethod) {
                    case StackToBool_T:
                    case StackToChar_T:
                    case StackToInt_T:
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().IntToWrite_T(static_cast<int>(arg1 + arg2), addr);
                        break;
                    case StackToDouble_T:
                        memcpy(&addr, code.arg3, sizeof(int));
                        recordStack.GetTopRecord().DoubleToWrite_T(arg1 + arg2, addr);
                        break;
                }
            }

            break;
        case SUB:
            switch (code.arg3ParseMethod) {
                case StackToBool_T:
                case StackToChar_T:
                case StackToInt_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().IntToWrite_T(static_cast<int>(arg1 - arg2), addr);
                    break;
                case StackToDouble_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().DoubleToWrite_T(arg1 - arg2, addr);
                    break;
            }
            break;
        case MUL:
            switch (code.arg3ParseMethod) {
                case StackToBool_T:
                case StackToChar_T:
                case StackToInt_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().IntToWrite_T(static_cast<int>(arg1 * arg2), addr);
                    break;
                case StackToDouble_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().DoubleToWrite_T(arg1 * arg2, addr);
                    break;
            }
            break;
        case DIV:
            switch (code.arg3ParseMethod) {
                case StackToBool_T:
                case StackToChar_T:
                case StackToInt_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().IntToWrite_T(static_cast<int>(arg1 / arg2), addr);
                    break;
                case StackToDouble_T:
                    memcpy(&addr, code.arg3, sizeof(int));
                    recordStack.GetTopRecord().DoubleToWrite_T(arg1 / arg2, addr);
                    break;
            }
            break;

    }
}

void EzVm::AnalyzerBoolArith(Code code) {
    /*全部转换为浮点数进行运算*/
    int arg1;
    int arg2;
    int intValue;
    char charValue;
    bool boolValue;
    void *refValue1;
    void *refValue2;
    int addr;
    switch (code.arg1ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg1, sizeof(bool));
            arg1 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg1, sizeof(char));
            arg1 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg1, sizeof(int));
            arg1 = intValue;
            break;
        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg1 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg1 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg1 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg1 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg1 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg1 = intValue;
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg1 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg1 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg1 = intValue;
            break;
        case StackToRef:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue1 = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg1, sizeof(int));
            refValue1 = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
    }

    switch (code.arg2ParseMethod) {

        case ToBool:
            memcpy(&boolValue, code.arg2, sizeof(bool));
            arg2 = boolValue;
            break;
        case ToChar:
            memcpy(&charValue, code.arg2, sizeof(char));
            arg2 = charValue;
            break;
        case ToInt:
            memcpy(&intValue, code.arg2, sizeof(int));
            arg2 = intValue;
            break;
        case StackToBool:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            arg2 = boolValue;
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            arg2 = boolValue;
            break;
        case StackToChar:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            arg2 = charValue;
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            arg2 = charValue;
            break;
        case StackToInt:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            arg2 = intValue;
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            arg2 = intValue;
            break;
        case HeapToBool_T:
            memcpy(&addr, code.arg2, sizeof(int));
            boolValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            arg2 = boolValue;
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg2, sizeof(int));
            charValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            arg2 = charValue;
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg2, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            arg2 = intValue;
            break;
        case StackToRef:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue2 = recordStack.GetTopRecord().ReadToRef_D(addr);
            break;
        case StackToRef_T:
            memcpy(&addr, code.arg2, sizeof(int));
            refValue2 = recordStack.GetTopRecord().ReadToRef_T(addr);
            break;
    }

    switch (code.op) {

        case AND:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(arg1 & arg2, addr);
            break;
        case XOR:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(arg1 ^ arg2, addr);
            break;
        case MOD:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(arg1 % arg2, addr);
            break;
        case OR:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(arg1 | arg2, addr);
            break;
        case LNE:
            memcpy(&addr, code.arg3, sizeof(int));
            if (code.arg1ParseMethod == StackToRef_T || code.arg1ParseMethod == StackToRef) {
                recordStack.GetTopRecord().BoolToWrite_T(refValue1 != refValue2, addr);
            } else {
                recordStack.GetTopRecord().BoolToWrite_T(arg1 != arg2, addr);
            }
            break;
        case LEQ:
            memcpy(&addr, code.arg3, sizeof(int));
            if (code.arg1ParseMethod == StackToRef_T || code.arg1ParseMethod == StackToRef) {
                recordStack.GetTopRecord().BoolToWrite_T(refValue1 == refValue2, addr);
            } else {
                recordStack.GetTopRecord().BoolToWrite_T(arg1 == arg2, addr);
            }
            break;
        case LGT:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 > arg2, addr);
            break;
        case LGE:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 >= arg2, addr);
            break;
        case LLT:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 < arg2, addr);
            break;
        case LLE:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 <= arg2, addr);
            break;
        case LAND:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 && arg2, addr);
            break;
        case LOR:
            memcpy(&addr, code.arg3, sizeof(int));
            recordStack.GetTopRecord().BoolToWrite_T(arg1 || arg2, addr);
            break;
    }
}

void EzVm::AnalyzerNegAndNot(Code code) {

    double doubleValue;
    int intValue;
    int addr;

    switch (code.arg1ParseMethod) {

        case StackToBool:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToBool_D(addr);
            break;
        case StackToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToBool_T(addr);
            break;
        case StackToChar:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToChar_D(addr);
            break;
        case StackToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToChar_T(addr);
            break;
        case StackToInt:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_D(addr);
            break;
        case StackToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToInt_T(addr);
            break;
        case StackToDouble:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_D(addr);
            memcpy(&addr, code.arg2, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(-doubleValue, addr);
            return;
        case StackToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToDouble_T(addr);
            memcpy(&addr, code.arg2, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(-doubleValue, addr);
            return;
        case HeapToBool_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToBool_T(addr);
            break;
        case HeapToChar_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToChar_T(addr);
            break;
        case HeapToInt_T:
            memcpy(&addr, code.arg1, sizeof(int));
            intValue = *recordStack.GetTopRecord().ReadToRefToInt_T(addr);
            break;
        case HeapToDouble_T:
            memcpy(&addr, code.arg1, sizeof(int));
            doubleValue = *recordStack.GetTopRecord().ReadToRefToDouble_T(addr);
            memcpy(&addr, code.arg2, sizeof(int));
            recordStack.GetTopRecord().DoubleToWrite_T(-doubleValue, addr);
            return;
    }

    switch (code.op) {
        case NOT:
            memcpy(&addr, code.arg2, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(~intValue, addr);
            break;
        case NEG:
            memcpy(&addr, code.arg2, sizeof(int));
            recordStack.GetTopRecord().IntToWrite_T(-intValue, addr);
            break;
    }

}
