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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto it=head;
        int n=0;
        while(it){
            n++;
            it=it->next;
        }
        it=head;
        int partsize=n/k;
        int extraNodes=n%k;
        vector<ListNode*>ans(k,nullptr);
        for(int i=0;i<k && it;i++){
            ans[i]=it;
            int total=partsize+(extraNodes-->0 ? 1:0);
            for(int j=0;j<total-1;j++){
                it=it->next;
            }
            auto newHead=it->next;
            it->next=nullptr;
            it=newHead;
            
        }return ans;
        
    }
};