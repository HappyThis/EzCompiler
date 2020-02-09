//
// Created by ezos on 19-1-11.
//

#ifndef EZCOMPILER_ACTIVITYRECORD_H
#define EZCOMPILER_ACTIVITYRECORD_H

#include "string.h"

#include "EzVmType.h"


class ActivityRecord {

public:

    struct RetInfo{

        /*返回点*/
        int retPoint;
        /*返回方式*/
        ArgParseMethod retParseMethod;
    };

    /*-----------------------参数与声明变量存放区--------------------------------*/
    /*转换为int*/
    int *ReadToInt_D(int addr);

    /*转换为char*/
    char *ReadToChar_D(int addr);

    /*转换为double*/
    double *ReadToDouble_D(int addr);

    /*转化为bool*/
    bool *ReadToBool_D(int addr);

    /*转化为指针之后再转int*/
    int *ReadToRefToInt_D(int addr);

    /*转化为指针之后再转char*/
    char *ReadToRefToChar_D(int addr);

    /*转化为指针之后再转double*/
    double *ReadToRefToDouble_D(int addr);

    /*转化为指针之后再转bool*/
    bool *ReadToRefToBool_D(int addr);

    /*转化为指针*/
    void *ReadToRef_D(int addr);

    void IntToWrite_D(int value, int addr);

    void CharToWrite_D(char value, int addr);

    void DoubleToWrite_D(double value, int addr);

    void BoolToWrite_D(bool value, int addr);

    void IntRefToWrite_D(int *intAddr, int addr);

    void CharRefToWrite_D(char *charAddr, int addr);

    void DoubleRefToWrite_D(double *doubleAddr, int addr);

    void BoolRefToWrite_D(bool *boolAddr, int addr);

    void RefToWrite_D(void *refAddr, int addr);

    /*-----------------临时变量存放区--------------------------------------*/
    /*转换为int*/
    int *ReadToInt_T(int addr);

    /*转换为char*/
    char *ReadToChar_T(int addr);

    /*转换为double*/
    double *ReadToDouble_T(int addr);

    /*转化为bool*/
    bool *ReadToBool_T(int addr);

    /*转化为指针之后再转int*/
    int *ReadToRefToInt_T(int addr);

    /*转化为指针之后再转char*/
    char *ReadToRefToChar_T(int addr);

    /*转化为指针之后再转double*/
    double *ReadToRefToDouble_T(int addr);

    /*转化为指针之后再转bool*/
    bool *ReadToRefToBool_T(int addr);

    /*转化为指针*/
    void *ReadToRef_T(int addr);

    void IntToWrite_T(int value, int addr);

    void CharToWrite_T(char value, int addr);

    void DoubleToWrite_T(double value, int addr);

    void BoolToWrite_T(bool value, int addr);

    void IntRefToWrite_T(int *intAddr, int addr);

    void CharRefToWrite_T(char *charAddr, int addr);

    void DoubleRefToWrite_T(double *doubleAddr, int addr);

    void BoolRefToWrite_T(bool *boolAddr, int addr);

    void RefToWrite_T(void *refAddr, int addr);

    void RrefToWrite_T(void *rrefAddr, int addr);

    ActivityRecord();

    /*---------------------------------返回值存放区--------------------------------------*/

    /*转换为int*/
    int *ReadToInt_R();

    /*转换为char*/
    char *ReadToChar_R();

    /*转换为double*/
    double *ReadToDouble_R();

    /*转化为bool*/
    bool *ReadToBool_R();

    /*转化为指针之后再转int*/
    int *ReadToRefToInt_R();

    /*转化为指针之后再转char*/
    char *ReadToRefToChar_R();

    /*转化为指针之后再转double*/
    double *ReadToRefToDouble_R();

    /*转化为指针之后再转bool*/
    bool *ReadToRefToBool_R();

    /*转化为指针*/
    void *ReadToRef_R();

    void IntToWrite_R(int value);

    void CharToWrite_R(char value);

    void DoubleToWrite_R(double value);

    void BoolToWrite_R(bool value);

    void IntRefToWrite_R(int *intAddr);

    void CharRefToWrite_R(char *charAddr);

    void DoubleRefToWrite_R(double *doubleAddr);

    void BoolRefToWrite_R(bool *boolAddr);

    void RefToWrite_R(void *refAddr);

    void SetCallPoint(int callPoint);

    int GetCallPoint();

    void SetRetInfo(int retPoint,ArgParseMethod retParseMethod);

    RetInfo GetRetInfo();

    int GetParamOffset(int sizeOfParam);


private:


    /*临时变量存放区域*/

    unsigned char tempVar[1024];

    /*参数与声明变量存放区域*/

    unsigned char decVar[1024];

    /*返回值存放区*/

    unsigned char retVar[8];

    /*为了之后的拓展,设置定位器*/

    void *Locator_T(int addr);

    void *Locator_D(int addr);

    /*函数调用点(下一层)*/
    int callPoint;

    RetInfo retInfo;

    int paramOffset;
};


#endif //EZCOMPILER_ACTIVITYRECORD_H
