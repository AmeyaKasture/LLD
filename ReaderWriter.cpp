#include <mutex>
#include <condition_variable>
#include <unordered_map>
using namespace std;

class ConcurrentCache{
    private:
    unordered_map<int,int> cache;
    const int max_readers=10;
    int readers=0;
    int writers=0;
    mutex mtx;
    condition_variable read_allow;
    condition_variable  write_allow;
    
    public:
    bool read(int key,int &val){
        unique_lock<mutex>  lock(mtx);
        read_allow.wait(lock,[&]{
            return readers<max_readers  && writers==0; 
        });
        readers++;
        lock.unlock();
        bool contains=true;
        if(cache.find(key)!=cache.end())val=cache[key];
        else contains=false;
        read_allow.wait(lock,[&]{
            return readers<=max_readers  && writers==0; 
        });
        readers--;
        if(readers==0)write_allow.notify_one();
        return contains;
    }

    void write(int key, int val){
        unique_lock<mutex>  lock(mtx);
        write_allow.wait(lock,[&]{
            return writers==0; 
        });
        writers++;
        cache[key]=val;
        writers--;
        write_allow.notify_one();
        read_allow.notify_all();
    }

};