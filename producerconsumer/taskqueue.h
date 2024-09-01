#include"common.h"
#include"task.h"

class TaskQueue{
    private:
    static TaskQueue *instance;
    
    public:
    queue<Task> taskList;
    static TaskQueue* getInstance();
};