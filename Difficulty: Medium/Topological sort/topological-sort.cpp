//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//using dfs

class Solution {
  public:
  void dfs(vector<vector<int>>&adj,vector<bool>&visited,int u,stack<int>&st){
      visited[u]=true;


    //phle mere bacho ko dalo stack mai
      for(int &v:adj[u]){
          if(!visited[v]){
              dfs(adj,visited,v,st);
          }
      }

    //phir mere ko dalo
      st.push(u);
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        stack<int>st;
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i,st);
            }
        }
        vector<int>result;
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            result.push_back(top);
        }
        return result;
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends



//using bfs -- and it is alos called kahn's algorithm


vector<int> topologicalSort(vector<vector<int>>& adj) {
        // using BFS
        int n=adj.size();
        vector<int>result;
        vector<bool>visited(n,false);
        vector<int>indegree(n,0);
        
        queue<int>q;
        
        //step 1
        
        for(int u=0;u<n;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        // step2
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        // step3
        while(!q.empty()){
            int element=q.front();
            q.pop();
            result.push_back(element);
            
            for(int &v:adj[element]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return result;
    }
