// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
  
  void solve(vector<string>&ans,string temp,int n,int open,int close){
      //base case
      if(temp.size()==n){
         
              ans.push_back(temp);
          
          return ;
      }
      
      if(open<n/2){
          temp.push_back('(');
          solve(ans,temp,n,open+1,close);
          temp.pop_back();
      }
      
      if(close<open){
          temp.push_back(')');
          solve(ans,temp,n,open,close+1);
          temp.pop_back();
          
      }
  }
  
  
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>ans;
        string temp="";
        solve(ans,temp,n,0,0);
        return ans;
        
    }
};