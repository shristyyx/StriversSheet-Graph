//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//Distance of nearest cell having 1



//BFS Problem
class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
        int n= grid.size();
        int m= grid[0].size();
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> ans(n, vector<int> (m,-1));
        

        //mark all ones with 0 in distance array, and visited, and push in queue.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                {
                    if(grid[i][j]==1){
                        ans[i][j]=0;
                        q.push({i,j});
                        vis[i][j]=1;
                    } 
                }
        }
        
        
        //BFS
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            
            //Distance of each adjacent cell is 1+distance of parent cell
            for(int i=0; i<4; i++){
                int nr= row+dr[i];
                int nc= col+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    ans[nr][nc] = ans[row][col]+1;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
        return ans;
	}
};