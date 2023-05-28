
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  // Cycle detection can also be done using Kahn's Algorithm
  // Topo Sort  is only possible in DAG --> Directed Acyclic Graph
  // So if topo sort array has less than V nodes in it
  // A cycle was detected
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> topo;
        vector<int> indegree(V,0);
        queue<int> q;
        
        
        // first form an indegree array
        for(int i=0 ; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        //then push all the nodes with indegree =0 in the queue
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        
        // apply Kahn's Algorithm 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]) { 
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
                
            }
        }
        
        return !(topo.size()==V);
        
    }

};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
