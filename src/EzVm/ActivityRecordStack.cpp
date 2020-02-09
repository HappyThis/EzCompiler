//
// Created by ezos on 19-1-11.
//

#include "ActivityRecordStack.h"

ActivityRecordStack::ActivityRecordStack() {

}

void ActivityRecordStack::CreateRecord() {
    isNewRecord = true;
    newRecord = ActivityRecord();

}

void ActivityRecordStack::SetNewRecord() {

    isNewRecord = false;
    recordStack.push(newRecord);
}

ActivityRecord &ActivityRecordStack::GetNewRecord() {
    return newRecord;
}

ActivityRecord &ActivityRecordStack::GetTopRecord() {

    return recordStack.top();
}

void ActivityRecordStack::Pop() {

    removedRecord = recordStack.top();

    recordStack.pop();
}

ActivityRecord ActivityRecordStack::GetRemovedRecord() {
    return removedRecord;
}

bool ActivityRecordStack::IsNewRecord() {
    return isNewRecord;
}
