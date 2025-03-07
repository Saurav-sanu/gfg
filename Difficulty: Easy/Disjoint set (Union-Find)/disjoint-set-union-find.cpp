//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            if (s == "UNION") {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            } else {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends


/*Complete the functions below*/
int find(int par[], int x) {
    
    if(x==par[x]){
        return x;
    }
    
    return find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    int x_parent=find(par,par[x]);
    int y_parent=find(par,par[z]);
    
    if(x_parent!=y_parent){
        par[x_parent]=y_parent;
    }
}