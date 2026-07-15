class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string a, string b) {
        string key = a + " " + b;
        
        if(dp.count(key)) return dp[key];
        if(a.compare(b) == 0) return true;
       int n = a.size();
        if(a.size() <= 1) return false;     // kyuki agar len 1 bhi hui upar check kr liya hai equal nhi hai toh obvious false hog eg  a = t  ,  b = g; false
        bool flag = false;
       
        for(int i = 1; i < n; i++){
            // first ka first scramble of first and second ka second scr. of second
           
            bool con1 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)); 

             // first ka first scramble of second ka second and first ka second scr. of second ka first
            bool con2 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i));
            if(con1 || con2) {
                flag = true;
                break;
            }
        }
        return dp[key] = flag;
    }
    bool isScramble(string a, string b) {
        int n = a.size();
        return solve(a, b);
    }
};