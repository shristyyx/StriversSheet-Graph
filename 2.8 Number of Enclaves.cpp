//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//Number of Enclaves


class Solution { 
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        //starting bfs/dfs calls from all the nodes which are 1 and on boundary
        //these cells are connected to the boundary through land and can cross the boundary

        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1){
                q.push({i,0});
            }
                if(!vis[i][m-1] && grid[i][m-1]==1){
                q.push({i,m-1});
            }
            
        }

        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i]==1){
                q.push({0,i});
            }
            
            if(!vis[n-1][i] && grid[n-1][i]==1){
                q.push({n-1,i});
            }
        }
        
        //call bfs and mark all the vistables as visited
        while(!q.empty()){
            
            int row= q.front().first;
            int col= q.front().second;
            vis[row][col]=1;
            q.pop();
            
            int delrow[]= {-1,0,1,0};
            int delcol[]= {0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int nr= row+delrow[i];
                int nc= col+delcol[i];
                
                if(nr>=0&&nr<n&&nc>=0&&nc<m&& !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                }  
            }
        }
        
        int count=0;
        //count all the cells which are land (value as 1) 
        //but not visited by any bfs call from the edge node
        //thus not connected to any edge node

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j])
                count++;
            }
        }
     return count;   
    }
};
