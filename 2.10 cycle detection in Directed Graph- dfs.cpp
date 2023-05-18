//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//cycle detection in directed graph (dfs)


//we will mark path as visited and while returning on this path
//we will mark path as unvited after complete recursion
//because while on a path only if a visited node is reached 
//it is considered a loop
//because it needs to be a closed loop

//   1 --> 2 ---> 3
//         ^---4--^


//because in this case, dfs call from 4-->2-->3 will reach 2-->3 again
//but different path 
//and does not form a closed loop

class Solution {
  public:
    bool dfs(int node, vector<int> & vis , vector<int> &pathVis, vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it : adj[node]){
            if(vis[it]==1 && pathVis[it]==1) return true;
            if(!vis[it]&&dfs(it, vis, pathVis, adj)==true) return true;
            
        }
        
        pathVis[node]=0;
        return false;
    }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)==true) return true;
            }
        }
    return false;
    }
};