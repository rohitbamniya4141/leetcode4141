class Solution {
public:

    long long LIMIT = 1e6;


    long long nCr(int n, int r, long long cap){

        if(r < 0 || r > n)
            return 0;

        if(r > n-r)
            r = n-r;


        long long ans = 1;

        for(int i = 1; i <= r; i++){

            ans = ans * (n-r+i) / i;

            if(ans >= cap)
                return cap;
        }

        return ans;
    }



    long long countWays(vector<int>& cnt, long long cap){

        int total = 0;

        for(int x : cnt)
            total += x;


        long long ways = 1;


        for(int x : cnt){

            if(x == 0)
                continue;


            ways *= nCr(total, x, cap);


            if(ways >= cap)
                return cap;


            total -= x;
        }


        return ways;
    }



    string smallestPalindrome(string s, int k) {


        vector<int> freq(26,0);


        for(char c : s)
            freq[c-'a']++;



        string mid = "";


        for(int i = 0; i < 26; i++){

            if(freq[i] % 2)
                mid = char('a'+i);


            freq[i] /= 2;
        }



        int n = s.size()/2;


        // check total possible palindrome
        if(countWays(freq, k+1) < k)
            return "";



        string left = "";

        long long K = k;



        for(int pos = 0; pos < n; pos++){


            bool placed = false;


            for(int ch = 0; ch < 26; ch++){


                if(freq[ch] == 0)
                    continue;



                // try character
                freq[ch]--;



                long long ways = countWays(freq, K+1);



                if(K > ways){

                    // skip this block
                    K -= ways;

                    freq[ch]++;
                }
                else{

                    // choose this character
                    left += char('a'+ch);

                    placed = true;

                    break;
                }
            }


            if(!placed)
                return "";
        }



        string right = left;

        reverse(right.begin(), right.end());


        return left + mid + right;
    }
};