//
// Created by ezos on 19-1-11.
//

#ifndef EZCOMPILER_ACTIVITYRECORDSTACK_H
#define EZCOMPILER_ACTIVITYRECORDSTACK_H

#include "ActivityRecord.h"

#include "stack"

using namespace std;


class ActivityRecordStack {

public:
    /*加入初始记录*/
    ActivityRecordStack();

    /*创建*/
    void CreateRecord();

    /*激活*/
    void SetNewRecord();

    ActivityRecord &GetNewRecord();

    bool IsNewRecord();

    ActivityRecord &GetTopRecord();

    ActivityRecord GetRemovedRecord();

    void Pop();

private:
    stack<ActivityRecord> recordStack;

    ActivityRecord newRecord;

    ActivityRecord removedRecord;

    bool isNewRecord;
};


#endif //EZCOMPILER_ACTIVITYRECORDSTACK_H
