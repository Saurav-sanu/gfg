//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
public:
int MOD=1e9+7;
typedef pair<long long,int>P;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<P>>adj;
        for(auto edge:roads){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<long long>result(n,LLONG_MAX);
        vector<int>ways(n,0);


            pq.push({0,0});
            result[0]=0;
            ways[0]=1;


            while(!pq.empty()){
                auto node=pq.top();
                pq.pop();
                int source=node.second;
                long long dist=node.first;

                for(auto an:adj[source]){
                    int vec=an.first;
                    int wt=an.second;
                    long long newdist=dist+wt;

                    if(newdist<result[vec]){
                        result[vec]=newdist;
                        ways[vec]=ways[source];
                        pq.push({newdist,vec});
                    }
                    else if(dist+wt==result[vec]){
                        ways[vec]=(ways[vec]+ways[source])%MOD;
                    }
                }
            }

        return ways[n-1]%MOD;

    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends