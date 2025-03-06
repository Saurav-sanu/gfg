//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool isCyclic(vector<vector<int>> &adj) {
        int n=adj.size();
        queue<int>q;
        int count=0;
        
        vector<int>indegree(n,0);
        
        //step 1
        for(int i=0;i<n;i++){
            for(int &v:adj[i]){
                indegree[v]++;
            }
        }
        
        //step 2
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        
        //step 3
        while(!q.empty()){
            int element=q.front();
            q.pop();
            count++;
            
            for(int &v:adj[element]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
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