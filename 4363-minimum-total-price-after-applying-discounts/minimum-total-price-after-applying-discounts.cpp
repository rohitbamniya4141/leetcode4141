class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int k = min(prices.size(), discounts.size());
        double ans = 0;
        for(int i = 0; i < prices.size(); i++){
            ans += prices[i];
            if(i < k){
                ans -= (double)prices[i]*discounts[i]/100.0;
            }
        }
        return ans;
    }
};