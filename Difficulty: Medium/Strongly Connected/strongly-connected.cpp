//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Position this line where user code will be pasted.
class Solution {
  public:
  void dfsfill(vector<vector<int>>&adj,int u,stack<int>&st,vector<bool>&visited){
      visited[u]=true;
      
      for(auto &v:adj[u]){
          if(!visited[v]){
              dfsfill(adj,v,st,visited);
          }
      }
      st.push(u);
  }
  void dfstraversal(vector<vector<int>>&adjReversal,int i,vector<bool>&visited){
      visited[i]=true;
      
      for(auto &v:adjReversal[i]){
          if(!visited[v]){
              dfstraversal(adjReversal,v,visited);
          }
      }
  }
  
    int kosaraju(vector<vector<int>> &adj) {
        //step 1
        int n=adj.size();
        vector<vector<int>>adjReversal(n);
        
        stack<int>st;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsfill(adj,i,st,visited);
            }
            
        }
        
        // step 2 caretion of reversal of adj
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                adjReversal[v].push_back(u);
            }
        }
        
        //step 3
        
        int countScc=0;
        
        visited=vector<bool>(n,false);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!visited[node]){
                dfstraversal(adjReversal,node,visited);
                countScc++;
            }
        }
        
        return countScc;
        
        
        
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends