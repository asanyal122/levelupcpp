#include"common.h"
#include"task.h"
#include"taskqueue.h"
#include"producer.h"

Producer::Producer(){};
Producer::~Producer(){};
void Producer::produce()
{
    while(1)
    {
        Task task("ADD", 5, 6);
        TaskQueue::getInstance()->taskList.emplace(task);
        cout<<"Produced\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}