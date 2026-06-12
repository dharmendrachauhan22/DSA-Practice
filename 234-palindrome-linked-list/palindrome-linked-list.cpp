/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middle(ListNode* head,ListNode* &previous){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                previous=slow;
                slow=slow->next;
            }
            
        }return slow;
    }
    ListNode* reverseList(ListNode* head,ListNode* prev,ListNode* curr){
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;

    }


    
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return true;
        }
        ListNode* header=head;
        ListNode* previous=NULL;
        ListNode* middleNode=middle(head,previous);
        previous->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=middleNode;
        ListNode* newHead=reverseList(head,prev,curr);
        ListNode* temp1=header;
        ListNode* temp2=newHead;
        while(temp1!=NULL){
            if(temp1->val!=temp2->val){
                return false;

            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }

        }return true;


    }
};