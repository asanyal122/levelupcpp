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
        if(TaskQueue::getInstance()->taskList.size() < 200)
        {
            Task task("ADD", 5, 6);
            TaskQueue::getInstance()->taskList.emplace(task);
            task.print();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        else
        {
            cout<<"Failed to push task\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        }
        
    }
}