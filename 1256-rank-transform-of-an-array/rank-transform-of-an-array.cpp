class Solution {
public:
     
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for(int i = 0; i < arr.size(); i++){
            minheap.push({arr[i], i});
        }
         
        int rank = 1;
        while(!minheap.empty()){
            int curr = minheap.top().first;
            arr[minheap.top().second] = rank;
            minheap.pop();
            if( minheap.top().first != curr) rank++; 
           
        }
        return arr;
    }
};