#include"common.h"
#include"consumer.h"
#include"taskqueue.h"

Consumer::Consumer(){};
Consumer::~Consumer(){};
void Consumer::consume()
{
    while(1)
    {
        if(!TaskQueue::getInstance()->taskList.empty())
        {
            auto task = TaskQueue::getInstance()->taskList.front();
            TaskQueue::getInstance()->taskList.pop();
            task.print();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}