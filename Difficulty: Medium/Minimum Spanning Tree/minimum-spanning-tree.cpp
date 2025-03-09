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



// time is 0(ElogV).


// } Driver Code Ends





using kruskal alogo

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int>parent;
    vector<int>Rank;
    
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        
        return parent[i]=find(parent[i]);
    }
    void Union(int u,int v){
        int parent_u=find(u);
        int parent_v=find(v);
        
        if(parent_u==parent_v){
            return ;
        }
        
        if(Rank[parent_u]<Rank[parent_v]){
            parent[parent_u]=parent_v;
        }
        else if(Rank[parent_v]<Rank[parent_u]){
            parent[parent_v]=parent_u;
        }
        else {
            parent[parent_v]=parent_u;
            Rank[parent_u]++;
        }
    }
    
    int kruskal(vector<vector<int>>&vec){
        int sum=0;
        
        for(auto &temp:vec){
            int u=temp[0];
            int v=temp[1];
            int wt=temp[2];
            
            
            int parent_u=find(u);
            int parent_v=find(v);
            
            if(parent_u!=parent_v){
                Union(u,v);
                sum+=wt;
            }
        }
        
        return sum;
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        
        parent.resize(V);
        Rank.resize(V,0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        //using kruskla 
        auto comparator=[&](vector<int>&vec1,vector<int>&vec2){
            return vec1[2]<vec2[2];
        };
        
        vector<vector<int>>vec;
        for(int u=0;u<V;u++){
            for(auto &t:adj[u]){
               
                int v=t[0];
                int wt=t[1];
                
                vec.push_back({u,v,wt});
                
            }
        }
        sort(vec.begin(),vec.end(),comparator);
        
        return kruskal(vec);
        
    }
};


// time and space is

// Total time: O(E log E) (since sorting dominates)

// space :	O(V + E) (since edge list and adjacency list contribute the most)
