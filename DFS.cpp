//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//DFS

class Solution {
  public:
    //Function to return a list containing the DFS traversal of the graph.
    //We use Recursion to DFS
    //In DFS a function is made, which traverse to all the adjacents of the 
    //node first.

    void dfs(int node, int vis[],vector<int> adj[], vector<int> &ans){
        vis[node]=1;
        ans.push_back(node);
        

        //for all adjacents of the node
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, vis, adj, ans);
        }  
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int start=0;
        int vis[V]= {0};
        vis[0]=1;

        dfs(start,vis, adj, ans);
        
       return ans; 
    }
};