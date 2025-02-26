//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool isCycleDFS(vector<vector<int>>&adj,vector<bool>&visited,int u,vector<bool>&inRecursion){
      visited[u]=true;
      inRecursion[u]=true;
      
      for(int &v:adj[u]){
          if(visited[v]==false && isCycleDFS(adj,visited,v,inRecursion)){
              return true;
          }
          else if( inRecursion[v]==true){
              return true;
          }
      }
      inRecursion[u]=false;
      return false;
      
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<bool>inRecursion(n,false);
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isCycleDFS(adj,visited,i,inRecursion)){
                return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends