class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        int n = bills.size();

        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five <= 0){
                    return false;
                }
                five--;
                ten++;
            }
            else if(bills[i] == 20){
                if(ten > 0){
                    if(five <= 0){
                        return false;
                    }
                    else{
                        ten--;
                        five--;
                    }
                }
                else if(five >= 3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};