//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited){
      visited[u]=true;
      int n=adj.size();
      
      for(int v=0;v<n;v++){
          if(!visited[v] && adj[u][v]==1){
              dfs(adj,v,visited);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool>visited(V,false);
        int count=0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};

