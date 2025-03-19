//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  int MOD=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end){
            return 0;
        }
        vector<int>result(MOD,INT_MAX);
        
        queue<pair<int,int>>q;
        q.push({start,0});
        result[start]=0;
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            int nod=node.first;
            int steps=node.second;
            if(nod==end){
                return steps+1;
            }
            
            
            for(auto ar:arr){
                int num=(ar*nod)%MOD;
                if(num==end){
                    return steps+1;
                }
                if(steps+1<result[num]){
                    result[num]=steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends