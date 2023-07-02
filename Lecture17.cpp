#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* p = head;
        Node* nxt = NULL;

        // Inserting duplicate nodes
        while (p != NULL) {
            nxt = p->next;
            Node* newNode = new Node(p->val);
            p->next = newNode;
            newNode->next = nxt;
            p = nxt;
        }

        // Copying random pointers
        p = head;
        while (p != NULL) {
            if (p->random != NULL) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        // Segregate odd and even indexed Linked Lists
        p = head;
        Node* clone = head->next;
        Node* cloneStart = clone;

        while (p != NULL && p->next != NULL) {
            nxt = p->next;
            p->next = nxt->next;
            p = nxt;
        }

        return cloneStart;
    }
};

// solution 2: using map
class Node {
public:
    int val;
    Node* next, random;
};

Node *copy(Node *head){
    unordered_map<Node*,Node*> hash;
    Node *ptr=head;
    while(ptr!=NULL){
        Node *copiedNode=new Node(ptr->val);
        hash[ptr]=copiedNode;
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL){
        
        Node *copied=hash[ptr];
        copied->next=hash[ptr->next];
        copied->random=hash[ptr->random];
        ptr=ptr->next;
    }
    return hash[head];
}