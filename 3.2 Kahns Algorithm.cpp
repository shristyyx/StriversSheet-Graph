#include <bits/stdc++.h>
using namespace std;


// Kahn's Algoruithm is uised to find toposort using Queue Data structure
// and indegree
// indegree of nodes = 0, we push it to q, and reduce indegree of adjacent nodes
// if indegree of adj node reduces to zero, push it to q

class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]){
	    vector<int> indegree(V,0);
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it : adj[node]){
	            indegree[it]--;
	            
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	        
	    }
	    
	    return topo;
	}
};


int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}