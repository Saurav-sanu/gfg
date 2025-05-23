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





// or same code can be wriiten like this
class Solution {
  public:
  
    int solve(int m,int n,string &s1,string &s2,vector<vector<int>>&t){
        //base case
       if(m==0 ||n==0){
           return m+n;
       }
        
        if(t[m][n]!=-1){
            return t[m][n];
        }
        
        int take=0;
        int nottake=0;
        if(s1[m-1]==s2[n-1]){
             take=1+solve(m-1,n-1,s1,s2,t);
            
        }
        else{
            nottake=1+min(solve(m-1,n,s1,s2,t),solve(m,n-1,s1,s2,t));
        }
        
        return t[m][n]=take+nottake;
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return solve(m,n,s1,s2,t);





    //bottum up appraoach
      class Solution {
  public:
  
    //bottum up
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    t[i][j]=i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
        
    }
};

    }
};
// } Driver Code Ends


class Solution {
  public:
  
    //LCS 
    // LCS+(length of s1 -LCS)+(LENGTof s2- LCS);
    int shortestCommonSupersequence(string &s1, string &s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        
        int LCS=t[m][n];
        int extra_in_s1=m-LCS;
        int extra_in_s2=n-LCS;
        
        return LCS+extra_in_s1+extra_in_s2;
        
    }
};
