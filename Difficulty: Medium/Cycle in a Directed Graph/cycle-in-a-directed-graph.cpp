//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleDfs(vector<bool>&visited,vector<bool>&inRecursion,int u,vector<vector<int>>&adj){
        visited[u]=true;
        inRecursion[u]=true;
        
        
        for(int &v:adj[u]){
            if(visited[v]==false && isCycleDfs(visited,inRecursion,v,adj)){
                return true;
            }
            
            else if(inRecursion[v]==true && visited[v]==true){
                return true;
            }
        }
        inRecursion[u]=false;
        return false;
        
        
    }
    bool isCyclic(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isCycleDfs(visited,inRecursion,i,adj)){
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