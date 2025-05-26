class Solution {
  public:
  void solve(string s,vector<string>&ans,string &curr,int i){
    //   base case
    if(i>=s.length()){
        if(curr!=""){
            ans.push_back(curr);
        }
        return ;
    }
    
    
    curr.push_back(s[i]);
    solve(s,ans,curr,i+1);
    curr.pop_back();
    
    
    solve(s,ans,curr,i+1);
    
      
  }
    vector<string> AllPossibleStrings(string s) {
        vector<string>ans;
        string curr="";
        solve(s,ans,curr,0);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};