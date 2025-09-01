// User function Template for C++
class Solution {
  public:
  vector<int>parent;
  vector<int>rank;
  int find(int x){
      if(x==parent[x]){
          return x;
      }
      return parent[x]=find(parent[x]);
  }
  void Union(int x,int y){
      int x_parent=find(x);
      int y_parent=find(y);
      
      if(x_parent==y_parent){
          return ;
      }
      if(rank[x_parent]>rank[y_parent]){
          parent[y_parent]=x_parent;
      }
      else if(rank[x_parent]<rank[y_parent]){
          parent[x_parent]=y_parent;
          
      }
      else{
          parent[x_parent]=y_parent;
          rank[y_parent]++;
      }
      
  }
  
  int kruskal(vector<tuple<int,int,int>>&adj,int n){
      int sum=0;
      
      for(auto &[wt,u,v]:adj){
          
              
              int parent_u=find(u);
              int parent_v=find(v);
              if(parent_u!=parent_v){
                  Union(u,v);
                  sum+=wt;
              }
              
      }
      return sum;
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++) parent[i]=i;
        
        vector<tuple<int,int,int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            adj.push_back({wt,u,v});
        }
        sort(adj.begin(),adj.end());
        
        return kruskal(adj,V);
        
    }
};