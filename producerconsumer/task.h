#ifndef TASK_H
#define TASK_H
#include"common.h"
class Task{
    public:
    string taskName;
    int param1, param2;
    Task(string taskName, int param1, int param2);
    ~Task();
    void print();
};
#endif