class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        int m = p.size();
        
       vector<int> indegree(n, 0);
       vector<int> topo;
       
       vector<int> adjlis[n];
       
       for(int i=0; i<m;i++){
           
           int inn = p[i][0];
           int outt = p[i][1];
           adjlis[outt].push_back(inn);
           indegree[p[i][0]]++;
       }
       
       queue<int> q;
       
       for(int i=0; i<n; i++) {
           if(indegree[i]==0) q.push(i);
       }
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           topo.push_back(node);
           
           
           for(auto it: adjlis[node]) {
               indegree[it]--;
               if(indegree[it]==0) q.push(it);
           }
       }
      
        return (topo.size()==n);
           
    

    }
};
