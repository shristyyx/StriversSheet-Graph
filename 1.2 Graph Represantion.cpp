//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//Graph Represantion | C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int n, vector<int> adj[]) {
      vector<vector<int>> v;
      
      
      //traversing through the graph 
      //traverse through each node
      for(int i=0; i<n; i++){
          
          //form a dummy vector to contain the adjacent nodes of each nodes
          vector<int> dummy;
          
          //push the node itself in dummy 
          dummy.push_back(i);
          
          //push all the adjacent elements of the node
          for(auto it: adj[i]){
              dummy.push_back(it);
          }
          
          //sort the dummy array from second index, excluding the self node
          sort(dummy.begin()+1, dummy.end());
          
          //push the dummy node to the adjacency list
          v.push_back(dummy);
      }
      
      //return adjacenecy list
      return v;
      
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>> ans = obj.printGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size() - 1; j++) {
                cout << ans[i][j] << "-> ";
            }
            cout << ans[i][ans[i].size() - 1];
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
