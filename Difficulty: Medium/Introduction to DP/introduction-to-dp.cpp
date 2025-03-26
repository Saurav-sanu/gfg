//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  const long long int MOD = 1e9 + 7;
 
  public:
    long long int topDownUtil(int n, vector <long long int>& dp)
    {
        if(n<2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (topDownUtil(n-1, dp)%MOD+topDownUtil(n-2,dp)%MOD)%MOD;
    }
  
    long long int topDown(int n) {
        vector <long long int> dp(n+1, -1);
        return topDownUtil(n, dp);
    }
    long long int bottomUp(int n) {
        vector <long long int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = (dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
        }
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends