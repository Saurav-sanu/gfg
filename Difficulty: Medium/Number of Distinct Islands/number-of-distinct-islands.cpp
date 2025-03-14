//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(int row,int col,vector<vector<bool>>&visited,vector<vector<int>>&grid,
  int row0,int col0,vector<pair<int,int>>&vec){
      visited[row][col]=true;
      vec.push_back({row-row0,col-col0});
      int n=grid.size();
        int m=grid[0].size();
      
      for(auto dir:direction){
          int new_row=row+dir[0];
          int new_col=col+dir[1];
          
          if(new_row>=0 && new_row<n && new_col>=0 && new_col<m &&!visited[new_row][new_col]
          && grid[new_row][new_col]==1){
              dfs(new_row,new_col,visited,grid,row0,col0,vec);
          }
      }
      
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,visited,grid,i,j,vec);
                    st.insert(vec);
                    
                }
            }
        }
        return st.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends