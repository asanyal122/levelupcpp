#include"taskqueue.h"

TaskQueue* TaskQueue::getInstance()
{
    static TaskQueue instance;
    return &instance;
}