#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class LRUCache{
private:
    struct CacheNode{
        int key;
        int value;
        CacheNode(int k, int v):key(k),value(v){}
    };
public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key){
        if(cacheMap.find(key) == cacheMap.end()) return -1;

        //把当前访问的节点移到链表头部，并且更新map中该节点的地址
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }

    void set(int key, int value){
        if(cacheMap.find(key) == cacheMap.end()){
            if(cacheList.size()==capacity){
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }else{
            //更新节点的值，把当前访问的节点移植到链表头部，并且更新map中该节点的地址
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(),cacheList,cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
    
private:
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
};

int main()
{
    return 0;
}
