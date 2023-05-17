//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//Cycle Detection using DFS


class Solution {
  public:

    //Depth First Search Code
    //Par variable (par) stores the Parent of each node
    int dfs(int n, vector<int> vis, vector<int> adj[], int par){
        vis[n]=1;
        for(auto it : adj[n]){

            //if not visited and cycle detected ahead then return 1
            if(!vis[it]) { if(dfs(it, vis,adj, n)==1) return 1;}

            //if already visited, check if the adjacent node is not the parent
            //parent is already visited
            //if any other adjacent node is already visited
            //cycle is detected

            else if(it!=par) return 1;
        }
        
        return 0;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        //parent of unvisited elements is -1
        for(int i=0; i<V; i++){
            if (!vis[i] && dfs(i, vis, adj,-1)==1) {
                return 1;
        }
        
        }
        return 0;
        
    }
};