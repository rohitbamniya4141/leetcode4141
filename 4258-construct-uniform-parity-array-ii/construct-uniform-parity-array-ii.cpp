class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size() == 1) return true;
        bool isodd = false;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 != 0) {
                isodd = true;
                break;
            }
        }
        int mine = *min_element(nums1.begin(), nums1.end());
        if(mine%2 != 0){
            return true;
        }
        else{
            if(isodd) return false;
        }
        return true;
    }
};