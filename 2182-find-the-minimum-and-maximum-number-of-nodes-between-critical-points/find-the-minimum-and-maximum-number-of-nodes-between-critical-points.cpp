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
        vector<int>points;
        ListNode*c1 = head;
        ListNode*c2 = head->next;
        if(!c2->next) return {-1, -1};
        ListNode*c3 = c2->next;
        int i = 2;
        while(c3){
            if(c3->val > c2->val && c1->val > c2->val){
                points.push_back(i);
            }
            else if(c3->val < c2->val && c1->val < c2->val){
                points.push_back(i);
            }
            c3 = c3->next;
            c2 = c2->next;
            c1 = c1->next;
            i++;
        }
        if(points.size() <= 1) return {-1, -1};
        int mini = points[1]-points[0];
        int maxi = points[points.size()-1]-points[0];

        for(int i = 1; i < points.size(); i++){
            mini = min(mini, points[i]-points[i-1]);
            maxi = max(maxi, points[i]-points[0]);
        }
        return {mini, maxi};
    }
};