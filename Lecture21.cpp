#include <bits/stdc++.h> 
using namespace std;

//! Insert at bottom
void solve(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int>s;
    solve(myStack, x);
    return myStack;
}

//! Implement LRU cache
class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node *next ;
        node *prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int , node*>mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head ->next = tail;
        tail->prev= head;
    }

    void addNode(node* newNode){
        node* temp = head->next;
        newNode ->next = temp;
        newNode ->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delnext = delNode->next;
        delprev ->next = delnext;
        delnext ->prev = delprev;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* resNode = mp[key];
            int res = resNode -> val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* delNode = mp[key];
            mp.erase(key);
            deleteNode(delNode);
        }
        // if the capacity of the lru cache is full 
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key] = head->next;
    }
};