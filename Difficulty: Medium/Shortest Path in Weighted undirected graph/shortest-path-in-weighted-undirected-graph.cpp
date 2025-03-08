//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  typedef pair<int,int>P;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>result(n+1,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        unordered_map<int,vector<P>>adj;
        vector<int>parent(n+1);
        vector<int>path;
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        result[1]=0;
        
        
        pq.push({0,1});
        
        while(!pq.empty()){
            auto element=pq.top();
            pq.pop();
            
            int node=element.second;
            int dist=element.first;
            
            for(auto &it:adj[node]){
                int distance=it.second;
                int adjNode=it.first;
                
                if(dist+distance<result[adjNode]){
                    result[adjNode]=dist+distance;
                    pq.push({dist+distance,adjNode});
                    parent[adjNode]=node;
                    
                }
            }
        }
        
        int destNode=n;
        
        if(result[destNode]==INT_MAX){
            return {-1};
            
        }
        
        while(parent[destNode]!=destNode){
            path.push_back(destNode);
            destNode=parent[destNode];
        }
        path.push_back(1);
        
        reverse(path.begin(),path.end());
        
        
         vector<int> finalPath;
        finalPath.push_back(result[n]);
        for (int node : path) {
            finalPath.push_back(node);
        }

        return finalPath;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends