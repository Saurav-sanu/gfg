// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  public:
  bool isvalid(string t){
      int count=0;
      for(char &ch:t){
          if(ch=='('){
              count++;
          }
          else{
              count--;
              if(count<0){
                  return false;
              }
          }
          
      }
      return count==0;
  }
  void solve(vector<string>&ans,string temp,int n){
      //base case
      if(temp.size()==n){
          if(isvalid(temp)){
              ans.push_back(temp);
          }
          return ;
      }
      
      temp.push_back('(');
      solve(ans,temp,n);
      temp.pop_back();
      
      temp.push_back(')');
      solve(ans,temp,n);
      temp.pop_back();
  }
  
  
    vector<string> generateParentheses(int n) {
        // code here
        vector<string>ans;
        string temp="";
        solve(ans,temp,n);
        return ans;
        
    }
};