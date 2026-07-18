class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string oth = "";
        string X = "";
        string Y = "";
        for(char ch : s){
            if(ch == x){
                X += ch;
            }
            else if(ch == y){
                Y += ch;
            }
            else{
                oth += ch;
            }
        }
        return oth + Y + X;
    }
};