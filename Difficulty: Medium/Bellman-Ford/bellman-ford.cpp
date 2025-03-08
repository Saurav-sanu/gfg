//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src]=0;
        
        for(int count=1;count<=V-1;count++){
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u]!=1e8 &&dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        //one more time relax for negative cycle detection
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=1e8 &&dist[u]+wt<dist[v]){
                return {-1};
            }
        }
        
        return dist;
        
        
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

time is 0(v*m)

Edge Relaxation (V-1 times)

Each iteration scans M edges.
Total operations: 
(𝑉−1)×𝑀=𝑂(𝑉𝑀)

for negative scycle detection
scanning M edges
total operation for this is 0(m).

ttoal time complexity is 0(vM)+0(m)
  which is equal to 0(VM).





  
  space is 0(v+m).
  Distance Array (dist)

Requires O(V) space to store shortest distances.
Graph Representation (edges vector)

Stores M edges, requiring O(M) space.



// } Driver Code Ends
