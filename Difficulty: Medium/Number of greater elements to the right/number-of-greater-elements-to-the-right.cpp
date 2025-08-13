
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        // code here
        int n=arr.size();
        
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    count++;
                }
            }
            ans[i]=count;
        }
        
        vector<int>result;
        for(auto r:indices){
            result.push_back(ans[r]);
        }
        return result;
    }
};