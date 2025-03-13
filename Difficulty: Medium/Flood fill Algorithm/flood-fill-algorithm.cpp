//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
typedef pair<int,int>P;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {

        
   
        int m=image.size();
        int n=image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image;


        queue<P>q;
        q.push({sr,sc});
       
        image[sr][sc]=newColor;

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto node=q.front();
                q.pop();

                int x=node.first;
                int y=node.second;

                for(auto dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(new_x>=0 && new_x<m && new_y>=0&& new_y<n && image[new_x][new_y]==originalColor){
                        image[new_x][new_y]=newColor;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        return image;

    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends