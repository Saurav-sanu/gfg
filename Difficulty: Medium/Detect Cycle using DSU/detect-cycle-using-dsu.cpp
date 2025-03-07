//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    vector<int>parent;
    vector<int>rankA;
    
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        
        return parent[x]=find(parent[x]);
    };
    
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        
        if(x_parent==y_parent){
            return;
        }
        
        if(rankA[x_parent]<rankA[y_parent]){
            parent[x_parent]=y_parent;
        }
        else if(rankA[y_parent]<rankA[x_parent]){
            parent[y_parent]=x_parent;
        }
        else{
            parent[y_parent]=x_parent;
            rankA[x_parent]+=1;
        }
    };
	int detectCycle(int V, vector<int>adj[])
	{
	    parent.resize(V);
	    rankA.resize(V);
	    
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rankA[i]=1;
	    }
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	            if(u<v){
	                int parent_u=find(u);
	                int parent_v=find(v);
	                
	                if(parent_u==parent_v){
	                    return 1;
	                }
	                else{
	                    Union(u,v);
	                }
	            }
	        }
	    }
	    
	    return 0;
	    
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends