//
// Created by ezos on 19-1-11.
//

#include "ActivityRecord.h"

int *ActivityRecord::ReadToInt_D(int addr) {

    return (int *) Locator_D(addr);
}

char *ActivityRecord::ReadToChar_D(int addr) {
    return (char *) Locator_D(addr);
}

double *ActivityRecord::ReadToDouble_D(int addr) {
    return (double *) Locator_D(addr);
}

bool *ActivityRecord::ReadToBool_D(int addr) {
    return (bool *) Locator_D(addr);
}

int *ActivityRecord::ReadToRefToInt_D(int addr) {

    int *refToInt;
    memcpy(&refToInt, Locator_D(addr), sizeof(int *));

    return refToInt;
}

char *ActivityRecord::ReadToRefToChar_D(int addr) {
    char *refToChar;

    memcpy(&refToChar, Locator_D(addr), sizeof(char *));

    return refToChar;
}

double *ActivityRecord::ReadToRefToDouble_D(int addr) {

    double *refToDouble;

    memcpy(&refToDouble, Locator_D(addr), sizeof(double *));

    return refToDouble;
}

bool *ActivityRecord::ReadToRefToBool_D(int addr) {

    bool *refToBool;

    memcpy(&refToBool, Locator_D(addr), sizeof(bool *));

    return refToBool;
}

void *ActivityRecord::ReadToRef_D(int addr) {
    void *ref;

    memcpy(&ref, Locator_D(addr), sizeof(void *));

    return ref;
}

int *ActivityRecord::ReadToInt_T(int addr) {
    return (int *) Locator_T(addr);
}

char *ActivityRecord::ReadToChar_T(int addr) {
    return (char *) Locator_T(addr);
}

double *ActivityRecord::ReadToDouble_T(int addr) {
    return (double *) Locator_T(addr);
}

bool *ActivityRecord::ReadToBool_T(int addr) {
    return (bool *) Locator_T(addr);
}

int *ActivityRecord::ReadToRefToInt_T(int addr) {
    int *refToInt;

    memcpy(&refToInt, Locator_T(addr), sizeof(int *));

    return refToInt;
}

char *ActivityRecord::ReadToRefToChar_T(int addr) {
    char *refToChar;

    memcpy(&refToChar, Locator_T(addr), sizeof(char *));

    return refToChar;
}

double *ActivityRecord::ReadToRefToDouble_T(int addr) {
    double *refToDouble;

    memcpy(&refToDouble, Locator_T(addr), sizeof(double *));

    return refToDouble;
}

bool *ActivityRecord::ReadToRefToBool_T(int addr) {

    bool *refToBool;

    memcpy(&refToBool, Locator_T(addr), sizeof(bool *));

    return refToBool;
}

void *ActivityRecord::ReadToRef_T(int addr) {

    void *refToBool;

    memcpy(&refToBool, Locator_T(addr), sizeof(void *));

    return refToBool;
}

void ActivityRecord::IntToWrite_D(int value, int addr) {
    memcpy(Locator_D(addr), &value, sizeof(int));
}

void ActivityRecord::CharToWrite_D(char value, int addr) {
    memcpy(Locator_D(addr), &value, sizeof(char));
}

void ActivityRecord::DoubleToWrite_D(double value, int addr) {
    memcpy(Locator_D(addr), &value, sizeof(double));
}

void ActivityRecord::BoolToWrite_D(bool value, int addr) {
    memcpy(Locator_D(addr), &value, sizeof(bool));
}

void ActivityRecord::IntRefToWrite_D(int *intAddr, int addr) {
    memcpy(Locator_D(addr), &intAddr, sizeof(int *));
}

void ActivityRecord::CharRefToWrite_D(char *charAddr, int addr) {
    memcpy(Locator_D(addr), &charAddr, sizeof(char *));
}

void ActivityRecord::DoubleRefToWrite_D(double *doubleAddr, int addr) {
    memcpy(Locator_D(addr), &doubleAddr, sizeof(double *));
}

void ActivityRecord::BoolRefToWrite_D(bool *boolAddr, int addr) {
    memcpy(Locator_D(addr), &boolAddr, sizeof(bool *));
}

void ActivityRecord::RefToWrite_D(void *refAddr, int addr) {
    memcpy(Locator_D(addr), &refAddr, sizeof(void *));
}

void ActivityRecord::IntToWrite_T(int value, int addr) {
    memcpy(Locator_T(addr), &value, sizeof(int));
}

void ActivityRecord::CharToWrite_T(char value, int addr) {
    memcpy(Locator_T(addr), &value, sizeof(char));
}

void ActivityRecord::DoubleToWrite_T(double value, int addr) {
    memcpy(Locator_T(addr), &value, sizeof(double));
}

void ActivityRecord::BoolToWrite_T(bool value, int addr) {
    memcpy(Locator_T(addr), &value, sizeof(bool));
}

void ActivityRecord::IntRefToWrite_T(int *intAddr, int addr) {
    memcpy(Locator_T(addr), &intAddr, sizeof(int *));
}

void ActivityRecord::CharRefToWrite_T(char *charAddr, int addr) {
    memcpy(Locator_T(addr), &charAddr, sizeof(char *));
}

void ActivityRecord::DoubleRefToWrite_T(double *doubleAddr, int addr) {
    memcpy(Locator_T(addr), &doubleAddr, sizeof(double *));
}

void ActivityRecord::BoolRefToWrite_T(bool *boolAddr, int addr) {
    memcpy(Locator_T(addr), &boolAddr, sizeof(bool *));
}

void ActivityRecord::RefToWrite_T(void *refAddr, int addr) {
    memcpy(Locator_T(addr), &refAddr, sizeof(void *));
}

void ActivityRecord::RrefToWrite_T(void *rref, int addr) {
    void **rrefConvert = (void **) rref;
    void *refAddr = *rrefConvert;
    memcpy(Locator_T(addr), &refAddr, sizeof(void *));
}

int *ActivityRecord::ReadToInt_R() {
    return (int *) retVar;
}

char *ActivityRecord::ReadToChar_R() {
    return (char *) retVar;
}

double *ActivityRecord::ReadToDouble_R() {
    return (double *) retVar;
}

bool *ActivityRecord::ReadToBool_R() {
    return (bool *) retVar;
}

int *ActivityRecord::ReadToRefToInt_R() {
    int *refToInt;
    memcpy(&refToInt, retVar, sizeof(int *));
    return refToInt;
}

char *ActivityRecord::ReadToRefToChar_R() {
    char *refToChar;
    memcpy(&refToChar, retVar, sizeof(char *));
    return refToChar;
}

double *ActivityRecord::ReadToRefToDouble_R() {
    double *refToDouble;
    memcpy(&refToDouble, retVar, sizeof(double *));
    return refToDouble;
}

bool *ActivityRecord::ReadToRefToBool_R() {
    bool *refToBool;
    memcpy(&refToBool, retVar, sizeof(bool *));
    return refToBool;
}

void *ActivityRecord::ReadToRef_R() {
    double *refToDouble;
    memcpy(&refToDouble, retVar, sizeof(double *));
    return refToDouble;
}

void ActivityRecord::IntToWrite_R(int value) {
    memcpy(retVar, &value, sizeof(int));
}

void ActivityRecord::CharToWrite_R(char value) {
    memcpy(retVar, &value, sizeof(char));
}

void ActivityRecord::DoubleToWrite_R(double value) {
    memcpy(retVar, &value, sizeof(double));
}

void ActivityRecord::BoolToWrite_R(bool value) {
    memcpy(retVar, &value, sizeof(bool));
}

void ActivityRecord::IntRefToWrite_R(int *intAddr) {
    memcpy(retVar, &intAddr, sizeof(int*));
}

void ActivityRecord::CharRefToWrite_R(char *charAddr) {
    memcpy(retVar, &charAddr, sizeof(char*));
}

void ActivityRecord::DoubleRefToWrite_R(double *doubleAddr) {
    memcpy(retVar, &doubleAddr, sizeof(double *));
}

void ActivityRecord::BoolRefToWrite_R(bool *boolAddr) {
    memcpy(retVar, &boolAddr, sizeof(bool*));
}

void ActivityRecord::RefToWrite_R(void *refAddr) {
    memcpy(retVar, &refAddr, sizeof(void*));
}

void *ActivityRecord::Locator_T(int addr) {
    return (void *) tempVar+addr;
}

void *ActivityRecord::Locator_D(int addr) {
    return (void *) decVar+addr;
}

void ActivityRecord::SetCallPoint(int callPoint) {
    this->callPoint=callPoint;
}

int ActivityRecord::GetCallPoint() {
    return callPoint;
}

void ActivityRecord::SetRetInfo(int retPoint, ArgParseMethod retParseMethod) {

    retInfo.retPoint=retPoint;
    retInfo.retParseMethod=retParseMethod;

}

ActivityRecord::RetInfo ActivityRecord::GetRetInfo() {
    return retInfo;
}

int ActivityRecord::GetParamOffset(int sizeOfParam) {
    int tempSizeOfParam=paramOffset;
    paramOffset+=sizeOfParam;
    return tempSizeOfParam;
}

ActivityRecord::ActivityRecord() {

    paramOffset=4;

}

