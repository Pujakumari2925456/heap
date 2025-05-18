//merge k sorted linked list
//link=>https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // pair<int,ListNode*>
        priority_queue< pair<int,ListNode*>,
        vector< pair<int,ListNode*>>,
        greater< pair<int,ListNode*>>>p;
        for(auto &i:lists){
            if(i)
            p.push({i->val,i});
        }
        ListNode* dummy= new ListNode(0);
        ListNode* temp = dummy;
        while(!p.empty()){
            auto current=p.top().second;
            temp->next=current;
            temp=temp->next;
            p.pop();
            if(current->next){
                p.push({current->next->val,current->next});
            }


        }
        return dummy->next;
    }
};