class Solution {
public:

    vector<vector<int>> dist = {
    };

    int n;

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};


    void bfs(vector<vector<int>>& grid){

        queue<pair<int,int>> q;

        dist.assign(n, vector<int>(n,-1));


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }


        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();


            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n 
                   && dist[nx][ny]==-1){

                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }


    bool canReach(int safe){

        queue<pair<int,int>> q;

        vector<vector<int>> vis(n,vector<int>(n,0));


        if(dist[0][0]<safe)
            return false;


        q.push({0,0});
        vis[0][0]=1;


        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();


            if(x==n-1 && y==n-1)
                return true;


            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];


                if(nx>=0 && ny>=0 && nx<n && ny<n
                   && !vis[nx][ny]
                   && dist[nx][ny]>=safe){

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }



    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n=grid.size();

        bfs(grid);


        int low=0;
        int high=2*n;


        int ans=0;


        while(low<=high){

            int mid=(low+high)/2;


            if(canReach(mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }


        return ans;
    }
};