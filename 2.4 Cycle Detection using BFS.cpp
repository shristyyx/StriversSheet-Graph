//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//Cycle Detection using BFS


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    // If a node is already visted and gets visited again by different node
    // cycle is detected
    bool isCycle(int V, vector<int> adj[]) {
        //visited array
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        
        // for all conected components
        for(int i=0; i<V; i++){

            if(!vis[i]){
                vis[i]=1;
                q.push({i,-1});
                
                while(!q.empty()){
                    int val = q.front().first;
                    int par = q.front().second;
                    q.pop();


                    for(auto it: adj[val]){
                        //if not visited mark visited and add to queue
                        if(!vis[it]){
                        vis[it]=1;
                        q.push({it, val});}
                        else {
                            //if not visited & is not same as parent
                            //parent will be adjacent and already visited too
                            //but that is not a loop
                            //any other adjacent node than parent, if visited
                            //cycle is detected
                            if(it != par) return 1;
                        }
                    }
                }
                
            }
        }
        
        
        return 0;
    }
};