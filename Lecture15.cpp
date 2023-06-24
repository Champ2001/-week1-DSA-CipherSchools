#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        ListNode* prev = NULL , *curr = head, *next = NULL;
        while(curr){
            next = curr -> next;
            curr ->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
        return head; //return prev
    }
}

 ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        int count=k;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        //Step 1: Reverse first k nodes
        while(cur != NULL && count--){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        count=0;//make count 0 and count remaining number of nodes
        ListNode* temp=cur;
        while(temp != NULL){
            temp=temp->next;
            count ++;
        }
        // If remaining number of nodes are less than k then no need to reverse them
        if(count<k){
            head->next=cur;
        }
        else{//this means that adequate number of nodes are left and we can still reverse in k groups 
        //Step 2:Recursion samhal lega baki 
            if(next != NULL){
                head->next=reverseKGroup(next,k);
            }
        }
    //Step 3:return the prev as the new head of the resultant linked list
    return prev;
    }

     bool hasCycle(ListNode *head) {

        if(!head || !head->next){
            return false;
        }
        ListNode * fast = head;
        ListNode * slow = head;

        while(fast->next && fast->next->next){
            slow= slow->next;
            fast = fast ->next ->next;
            if(fast == slow){
            return true;
        }
        }
        
        return false;
    }

     ListNode *detectCycle(ListNode *head) {
        if(head == NULL || !head->next){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* entry=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow == fast){
                while(entry != slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }

    