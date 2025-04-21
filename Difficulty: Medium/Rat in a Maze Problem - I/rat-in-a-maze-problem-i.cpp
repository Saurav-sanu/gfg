//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    
    void solve(int i,int j,vector<vector<int>> &mat,vector<string>&result,string &path){
        //base ase
        int m=mat.size();
        int n=mat[0].size();
        if(i<0 || i>=n || j<0 ||j>=n ||mat[i][j]==0){
            return ;
        }
        if(i==m-1 && j==n-1){
            result.push_back(path);
            return ;
        }
        
        mat[i][j]=0;
        
        //down
        path.push_back('R');
        solve(i,j+1,mat,result,path);
        path.pop_back();
        
        path.push_back('D');
        solve(i+1,j,mat,result,path);
        path.pop_back();
        
        path.push_back('U');
        solve(i-1,j,mat,result,path);
        path.pop_back();
        
        path.push_back('L');
        solve(i,j-1,mat,result,path);
        path.pop_back();
        
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        //
        vector<string>result;
        string path="";
        solve(0,0,mat,result,path);
        
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends