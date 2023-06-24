#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//! Recursive approach for merge two sorted lists 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        else if(!list2){
            return list1;
        }
        else{
            //recursive approach
            ListNode* result = NULL;
            if(list1->val <= list2->val){
                result = list1;
                result -> next = mergeTwoLists(list1->next , list2);
            }
            else{
                result = list2;
                result ->next = mergeTwoLists(list1, list2->next);
            }
        return result;
        }
    }

//! Iterative approach for merge two sorted lists 

ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1->next == NULL){
            //if list1's next becomes NULL then we must point first list's next to list2
            list1->next=list2;
            return list1;
        }
        ListNode* cur1=list1;
        ListNode* cur2=list2;
        ListNode* next1=cur1->next;
        ListNode* next2;
        while(next1 && cur2){
            if(cur1->val <= cur2->val && cur2->val <=next1->val){
                //add the node in between the nodes
                cur1->next=cur2;
                next2=cur2->next;
                cur2->next=next1;
                //add pointers
                cur1=cur2;
                cur2=next2;
            }
            else{
                //update pointers
                cur1=next1;
                next1=next1->next;
            }
            if(next1 == NULL){
                cur1->next=cur2;
                return list1;
            }
        }
        return list1;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        if(list1->val <= list2->val){
           return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }
    }

    //! Merge k sorted linked lists 
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        else if (lists.size() == 1){
            return lists[0];
        }
       
        else{
            //means there must be more than one linked lists
            int last = lists.size() - 1;
            while(last > 0){
                int i = 0 , j = last;
                while(i < j){
                    lists[i] = mergeTwoLists(lists[i] , lists[j]);
                    i++;
                    j--;
                    if(i >= j){ // if i passes j then update last to j for second time iteration and merging
                        last = j;
                    }
                }
            }
        }
    return lists[0];
    }