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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode*c1 = head;
        ListNode*c2 = head->next;
        if(!c2->next) return {-1, -1};
        ListNode*c3 = c2->next;
        int i = 2;
        bool perm = true;
        int first = 0;
        int curr = 100000;
        int mini = INT_MAX, maxi = INT_MIN;
        while(c3){
            if(c3->val > c2->val && c1->val > c2->val){
                if(perm){
                    first = i;
                    perm = false;
                }
               else{
                    mini = min(mini, i-curr);
                    maxi = max(maxi, i - first);
                }
                 curr = i;
            }
            else if(c3->val < c2->val && c1->val < c2->val){
                if(perm){
                    first = i;
                    perm = false;
                }
                else{
                    mini = min(mini, i-curr);
                    maxi = max(maxi, i - first);
    
                }
                 curr = i;
            }
            c3 = c3->next;
            c2 = c2->next;
            c1 = c1->next;
            i++;
        }

        if(mini == INT_MAX || maxi == INT_MIN) return {-1, -1};

       
        return {mini, maxi};
    }
};