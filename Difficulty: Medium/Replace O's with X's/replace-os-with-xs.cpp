//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
  void DFS(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&visited,int n,int m){
      visited[i][j]=1;
      
      for(auto dir:directions){
          int new_i=i+dir[0];
          int new_y=j+dir[1];
          
          if(new_i>=0 && new_y>=0 && new_i<n && new_y<m && visited[new_i][new_y]==0 && mat[new_i][new_y]=='O'){
              DFS(new_i,new_y,mat,visited,n,m);
          }
      }
  }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        //first and last row;
        for(int j=0;j<m;j++){
            //first row
            if(visited[0][j]==0 && mat[0][j]=='O'){
                DFS(0,j,mat,visited,n,m);
            }
            
            //lst row
            if(visited[n-1][j]==0 && mat[n-1][j]=='O'){
                DFS(n-1,j,mat,visited,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            //first row
            if(visited[i][0]==0 && mat[i][0]=='O'){
                DFS(i,0,mat,visited,n,m);
            }
            
            //lst row
            if(visited[i][m-1]==0 && mat[i][m-1]=='O'){
                DFS(i,m-1,mat,visited,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends