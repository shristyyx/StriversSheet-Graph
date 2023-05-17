//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//Rotten Oranges

class Solution 
{
    public:
    //Bredth First Search Technique application
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        queue<pair<int,int>> q; 
        //visited array
        vector<vector<int>> vis (n, vector<int> (m,0));

        //answer array
        vector<vector<int>> ans (n, vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //push all rotten oranges index in queue
                //mark all rotten oranges as visited
                if(grid[i][j]==2) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //changes in row and column to visit adjacent nodes
            int delrow[] = {-1, 0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int i=0; i<4; i++){

                //adacent nodes
                int nr= row+delrow[i];
                int nc= col+delcol[i];
                

                //if node is unvisited
                //if node is fresh orange
                //if index is not out of range
                if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({nr,nc});
                    ans[nr][nc] = ans[row][col] +1;
                    vis[nr][nc]=1;
                }
            }
        }
        
        int mx=0;
        
        //maximum time taken 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mx= max(mx, ans[i][j]);
                
                if(grid[i][j]==1 && ans[i][j]==0) return -1;
            }
        }
        return mx;

    }
};