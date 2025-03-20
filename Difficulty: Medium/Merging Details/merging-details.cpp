//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class DisjointSet{

public:

    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            size[i]=1;
            parent[i] = i;
        }
        
    }
    
    int findParent(int u)
    {
        if(u==parent[u])return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unite(int u, int v)
    {
        int pu,pv;
        pu = findParent(u);
        pv = findParent(v);
        
        if(pu==pv) return;
        if(size[pu] <= size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
};

class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        
        int n = details.size();
        
        map<string, int> email;
        
        DisjointSet dj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                if(email.find(details[i][j]) != email.end())
                {
                    dj.unite(i, email[details[i][j]]);
                }
                else{
                    email[details[i][j]] = i;
                }
            }
        }
        map<int, vector<string>> rm;


        
        for(auto i: email)
        {
            string email_id = i.first;
            int node = i.second;
            
            int parent = dj.findParent(node);


            rm[parent].push_back(email_id);
        }
        vector<vector<string>> res;
        
        for(auto i: rm)
        {
            int parent = i.first;
            vector<string> v = i.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), details[parent][0]);
            res.push_back(v);
        }
        
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};

































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends