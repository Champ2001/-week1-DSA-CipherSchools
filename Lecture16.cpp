#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode *removeDuplicates(ListNode *head)
    {
    unordered_map<int , bool>mp;
    ListNode* cur= head;
    while(cur->next){
        mp[cur->val] = true;
        if(mp[cur->next->val] == true){
            ListNode* next_next = cur->next->next;
            ListNode* todelete = cur->next;
            cur->next = next_next;
            delete(todelete);
        }
        else{
            cur= cur->next;
        }
    }
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
        
        //solving for edge cases
        if(!head || !head->next || k==0){
            return head;
        }
        
        //compute the length of the list
        ListNode *ptr=head;
           int len=1;
           
           while(ptr->next && ++len)
               ptr=ptr->next;
           
           //going till that node from where we have to rotate
           ptr->next=head;
           k=k%len;
           k=len-k;
           while(k--) ptr=ptr->next;
           
           //making the node head and break the link
           head=ptr->next;
           ptr->next=NULL;
           
           return head;
    }