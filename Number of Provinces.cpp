//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//Number of Provinces
//User function Template for C++


//number of provinces is same as connected compoments

//dfs code
class Solution {
    void dfs(int vis[], vector<int> adjlis[],  int node){
        
            vis[node]=1;
            for(auto it:adjlis[node])
                if(!vis[it])
                    dfs(vis, adjlis, it);
        
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int start=1;
        vector<int> adjlis[V];
        int vis[V+1]= {0};
        
        //convertinng adj matrix to adj list
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjlis[i].push_back(j);
                    adjlis[j].push_back(i);
                }
            }
        }
        

        //increase count on every non visited component and call dfs for it
        //mark all connncted nodes as visited
        int count=0;
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                count++;
                dfs(vis, adjlis, i);

            }
        }
        
        return count;
    }
};