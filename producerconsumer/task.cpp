#include"task.h"

Task::Task(string taskName, int param1, int param2)
{
    this->taskName = taskName;
    this->param1 = param1;
    this->param2 = param2;
}
Task::~Task()
{

}

void Task::print(){
    std::cout<<"Produced Task "<<this->taskName<<" "<<this->param1<<this->param2<<endl;
}