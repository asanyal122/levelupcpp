#include<bits/stdc++.h>
using namespace std;

class Task;

queue<Task> taskList;

class Task{
    public:
    string taskName;
    int param1, param2;
    Task(string taskName, int param1, int param2)
    {
        this->taskName = taskName;
        this->param1 = param1;
        this->param2 = param2;
    }
    ~Task()
    {

    }

    void print(){
        cout<<"Produced "<<this->taskName<<" "<<this->param1<<this->param2<<endl;
    }
};
// class FunctionManager{
//     private:
//     map<string, function<int(int,int)>> functionMap;
//     public:
//     FunctionManager()
//     {
//         functionMap["ADD"] = [](int x, int y){return x+y;};
//         functionMap["SUB"] = [](int x, int y){return x-y;};
//     }
//     ~FunctionManager()
//     {

//     }
//     function<int(int,int)> getFunction(string key)
//     {
//         if(functionMap.find(key) != functionMap.end())
//         {
//             return functionMap[key];
//         }
//         return functionMap["ADD"];
//     }
// };

class Producer{
    public:
    Producer(){};
    ~Producer(){};
    void produce()
    {
        while(1)
        {
            Task task("ADD", 5, 6);
            taskList.emplace(task);
            cout<<"Produced\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

class Consumer{
    public:
    Consumer(){};
    ~Consumer(){};
    void consume()
    {
        while(1)
        {
            if(!taskList.empty())
            {
                auto task = taskList.front();
                taskList.pop();
                task.print();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
};

int main(void)
{
    
    
    thread producerThread([](){Producer producer; producer.produce();});
    thread consumerThread([](){Consumer consumer; consumer.consume();});
    
    //producerThread.start();
    //consumerThread.start();
    
    producerThread.join();
    consumerThread.join();

}