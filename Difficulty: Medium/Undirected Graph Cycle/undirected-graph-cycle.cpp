//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycleDfs(int u,vector<bool>&visited,vector<vector<int>>& adj,int parent){
        visited[u]=true;
        
        for(int &v:adj[u]){
           if(v==parent){
               continue;
           }
           if(visited[v]==true){
               return true;
           }
           
           if(isCycleDfs(v,visited,adj,u)){
               return true;
           }
            
            
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visited(n,false);
        
        
        for(int i=0;i<n;i++){
            if(!visited[i] && isCycleDfs(i,visited,adj,-1)){
                return true;
            }
            
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends