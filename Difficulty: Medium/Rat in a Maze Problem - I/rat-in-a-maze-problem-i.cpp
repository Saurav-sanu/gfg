class Solution {
  public:
  
  
//   vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
  void solve(vector<vector<int>>&maze,vector<string>&ans,int i,int j,string& path){
      int n=maze.size();
      if(i<0 || i>=n  ||j<0 ||j>=n ||maze[i][j]==0){
          return ;
      }
     
     
      if(i==n-1 && j==n-1){
          ans.push_back(path);
          return ;
      }
      
      
      maze[i][j]=0;
      
      path.push_back('D');
      solve(maze,ans,i+1,j,path);
      path.pop_back();
      
     
      
      
      path.push_back('L');
      solve(maze,ans,i,j-1,path);
      path.pop_back();
      
      path.push_back('R');
      solve(maze,ans,i,j+1,path);
      path.pop_back();
      
       path.push_back('U');
      solve(maze,ans,i-1,j,path);
      path.pop_back();
      
      
      
      maze[i][j]=1;
      
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
        string path="";
        int i=0;
        int j=0;
        
        solve(maze,ans,i,j,path);
        return ans;
        
    }
};