//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
	public:
	typedef pair<int,int>P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<P,vector<P>,greater<P>>pq;
        //wt,node
        pq.push({0,0});
        vector<bool>inMst(V,false);
        int sum=0;
        
        while(!pq.empty()){
            auto front=pq.top();
            int wt=front.first;
            int node=front.second;
            pq.pop();
            
            if(inMst[node]==true){
                continue;
            }
            inMst[node]=true;
            sum+=wt;
            
            for(auto &tmp:adj[node]){
                int neighbour=tmp[0];
                int neighbour_wt=tmp[1];
                
                if(inMst[neighbour]==false){
                    pq.push({neighbour_wt,neighbour});
                }
            }
        }
        return sum;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends