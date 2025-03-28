//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int step,vector<int>&height,vector<int>&dp){
      //base case
      int n=height.size();
      if(step==height.size()-1){
          return 0;
      }
      
      if(dp[step]!=-1){
          return dp[step];
      }
      int onestep=INT_MAX;
      if(step+1<height.size()){
         onestep=solve(step+1,height,dp)+abs(height[step+1]-height[step]);
      }
      int twostep=INT_MAX;
      if(step+2<height.size()){
         twostep=solve(step+2,height,dp)+abs(height[step+2]-height[step]);
      }
      
      return dp[step]=min(onestep,twostep);
  }
    int minCost(vector<int>& height) {
        int step=0;
        int n=height.size();
        vector<int>mp(n,-1);
        return solve(0,height,mp);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends