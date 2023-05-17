//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//Flood Fill


class Solution {
public:

    //Bredth First Search
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n= image.size();
        int m= image[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        q.push({sr,sc}); 
        vis[sr][sc]=1;
        int oc= image[sr][sc];
        image[sr][sc] = newColor;

        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            
            for(int i=0; i<4; i++){
                int nr= row+ dr[i];
                int nc= col+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && image[nr][nc]==oc){
                    image[nr][nc] = newColor;
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
                
            }     
        }
        
        return image;
        }
    
};