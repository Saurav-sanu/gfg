//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

void dfs(vector<bool>&visited,int u,vector<int>adj[]){
    visited[u]=true;
    
    for(auto it=adj[u].begin();it!=adj[u].end();it++){
        int v=*it;
        if(!visited[v]){
            dfs(visited,v,adj);
        }
    }
}
bool isConnected(int V,vector<int>adj[]){
    int nonZeroVertex=-1;
    for(int i=0;i<V;i++){
        if(adj[i].size()!=0){
            nonZeroVertex=i;
            break;
        }
    }
    
    vector<bool>visited(V,false);
    
    dfs(visited,nonZeroVertex,adj);
    
    for(int i=0;i<V;i++){
        if(!visited[i] && adj[i].size()>0){
            return false;
        }
    }
    return true;
}


	    bool isEularCircuitExist(int V, vector<int>adj[]){
	   // if(isConnected(V,adj)==false){
	   //     return 0;
	   // }
	    
	    int oddDegreeCount=0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size()%2!=0){
	            oddDegreeCount++;
	        }
	    }
	    
	   
	    if(oddDegreeCount==0){
	        return 1;
	    }
	    else {
	        return 0;
	    }
	    
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends