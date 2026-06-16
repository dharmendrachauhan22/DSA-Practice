/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node*head){
        if(!head) return nullptr;

        auto it=head;
        auto tail=head;
        while(it){
            if(it->child){
                auto recTail=solve(it->child);
                auto temp=it->next;
                it->next=it->child;
                it->next->prev=it;
                recTail->next=temp;
                if(temp) temp->prev=recTail;
                it->child=nullptr;

            }
            tail=it;
            it=it->next;
        }return tail;
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};