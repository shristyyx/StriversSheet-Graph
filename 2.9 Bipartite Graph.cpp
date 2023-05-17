//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.2 : Problems on BFS/DFS 
//Bipartite Graph


//A bipartite graph is a graph that can be colored with two colors,
//and no adjacent nodes have same color

//can be checked by calling a dfs, and coloring negative of present color,
//if already colored and same as present node
//then return false


class Solution {
public:
    bool dfs(int node, vector<int> adj[],  int col, vector<int> &color){
        color[node] = col;
        
        for(auto it : adj[node] ){
            //if further nodes return false, return false
            if(color[it]==-1){
                if (dfs(it, adj, !col, color)==false) return false;
            }
            //if adj node already colored, check if colored same as par node
            else if(color[it]==col) return false;
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0; i<V; i++){
	        
	        if(color[i]==-1)
	            if (dfs(i, adj, 0, color)==false) return false;
	    }
	    return true;
	}

};