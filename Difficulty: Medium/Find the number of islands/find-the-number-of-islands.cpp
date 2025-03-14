//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    void BFS(vector<vector<bool>>&visited,vector<vector<char>>&grid,int x, int y,int n,int m){
        queue<pair<int,int>>q;
        q.push({x,y});
        visited[x][y]=true;
        
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int x=v.first;
            int y=v.second;
            
            for(auto dir:directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && visited[new_x][new_y]==false &&grid[new_x][new_y] == '1'){
                    visited[new_x][new_y]=true;
                    q.push({new_x,new_y});
                }
            }
        }
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j] == '1'){
                    count++;
                    BFS(visited,grid,i,j,n,m);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends