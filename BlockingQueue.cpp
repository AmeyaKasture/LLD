#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;

class BlockingQueue{
    private:
    queue<int> q;
    mutex mtx;
    condition_variable not_full;
    condition_variable not_empty;
    bool shutdown=false;
    int capacity;
    
    public:
    explicit BlockingQueue(int capacity):capacity(capacity){}

    void push(int val){
        unique_lock<mutex> lock(mtx);
        not_full.wait(lock,[&]{
            return q.size()<capacity || shutdown;
        });
        if(shutdown)return; // In the case of shutdown there wont be any push op
        q.push(val);
        not_empty.notify_one();
    }

    bool pop(int & result){
        unique_lock<mutex> lock(mtx);
        not_empty.wait(lock,[&]{
            return !q.empty() || shutdown;
        });
        if(shutdown)return false;
        result=q.front();
        q.pop();
    }
    void stop(){
        lock_guard<mutex> lock(mtx);
        shutdown=true;
        not_empty.notify_all();
        not_full.notify_all();
    }
};