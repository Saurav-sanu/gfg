//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        
        int count=0;
        int n=adj.size();
        queue<int>q;
        vector<int>indegree(n,0);
        
        //step1
        for(int u=0;u<n;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        //step2
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        
        //step 3
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count==n){
            return false;
        }
        else {
            return true;
        }
        
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