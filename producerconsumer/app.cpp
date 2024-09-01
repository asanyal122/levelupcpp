#include<bits/stdc++.h>
#include"consumer.h"
#include"producer.h"
using namespace std;




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




int main(void)
{
    
    
    thread producerThread([](){Producer producer; producer.produce();});
    thread consumerThread([](){Consumer consumer; consumer.consume();});
    
    //producerThread.start();
    //consumerThread.start();
    
    producerThread.join();
    consumerThread.join();

}