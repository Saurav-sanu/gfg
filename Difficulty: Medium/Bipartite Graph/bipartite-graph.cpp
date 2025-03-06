//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool DFS(vector<vector<int>>&adj,int u,vector<int>&Color,int currColor){
        Color[u]=currColor;
        
        for(auto &v:adj[u]){
            if(Color[u]==Color[v]){
                return false;
            }
            
            if(Color[v]==-1){
                int colorofV=1-currColor;
                if(DFS(adj,v,Color,colorofV)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>Color(n,-1);
        
        for(int i=0;i<n;i++){
            if(Color[i]==-1){
                if(DFS(adj,i,Color,1)==false){
                    return false;
                }
            }
        }
        return true;
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends