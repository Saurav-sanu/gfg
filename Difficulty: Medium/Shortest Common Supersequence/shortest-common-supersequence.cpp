//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&t){
        //base case
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }
        
        if(t[i][j]!=-1){
            return t[i][j];
        }
        
        int take=0;
        int nottake=0;
        if(s1[i]==s2[j]){
             take=1+solve(i+1,j+1,s1,s2,t);
            
        }
        else{
            nottake=1+min(solve(i+1,j,s1,s2,t),solve(i,j+1,s1,s2,t));
        }
        
        return t[i][j]=take+nottake;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return solve(0,0,s1,s2,t);
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends