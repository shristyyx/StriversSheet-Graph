//Strivers Sheet
//GRAPHS [CONCEPTS AND PROBLEMS]
//Step 15.1 : Learning
//Graph and Types

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long count(int n) {
        
        //total number of edges possible from every node = n*(n-1)
        //since it is a directed graph, a-->b is same as b-->a edges possible = n*(n-1)/2
        
        long long int total_edges = n*(n-1)/2;
        // we have a choice for every edge: take or non take
        
        long long int ans = pow(2, total_edges);
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}
