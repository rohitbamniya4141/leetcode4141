class Solution {
public:
    unordered_map<char,char>parent;
    char find(char c){
        if(parent[c] == c) return c;
        return parent[c] = find(parent[c]);
    }

    void Union(char a, char b){
        char px = find(a);
        char py = find(b);
        if(px < py){
            parent[py] = px;
            parent[b] = px;
        }
        else if(px > py){
            parent[px] = py;
            parent[a] = py;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i < s1.size(); i++){
            parent[s1[i]] = s1[i];
            parent[s2[i]] = s2[i];
        }
        for(int i = 0; i < baseStr.size(); i++){
            parent[baseStr[i]] = baseStr[i];
        }
        for(int i = 0; i < s1.size(); i++){
            char a = s1[i];
            char b = s2[i];
            Union(a,b);
        }
        string ans = "";
         for(int i = 0; i < baseStr.size(); i++){
            char curr = find(baseStr[i]);
            ans+=curr;
        }
        return ans;
    }
};