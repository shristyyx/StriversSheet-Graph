class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    //In BFS, the nodes at one leevl are visited first and the next
    //Data structure used : QUEUE
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        int n= V;
        queue<int> q;
        vector<int> vis(n+1, 0);

        //Push 0 to the queue before starting the while loop
        q.push(0);
        vis[0]=1;
        v.push_back(0);
    
        //run a while loop which will add the adjacents of top element to the back
        //and give the first element everytime 

        while(!q.empty()){
            int val = q.front();
            q.pop();
    
            for(auto i: adj[val]){
                if(!vis[i]){
                    v.push_back(i);
                    q.push(i);
                    vis[i]=1;
                }
            }
        }

        
    return v;
    }
};