// User function Template for C++

class Solution {
  public:
  vector<vector<int>>result;
  void solve(vector<int>&arr,vector<int>&ans,int idx){
    //base case
    if(idx==arr.size()){
       
        result.push_back(ans);
        
        return ;
    }


    ans.push_back(arr[idx]);
    solve(arr,ans,idx+1);
    ans.pop_back();

    solve(arr,ans,idx+1);


}
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int>ans;
        solve(arr,ans,0);
        sort(result.begin(),result.end());
        return result;
        
    }
};