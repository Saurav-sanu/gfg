class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>prefix;
        int i=0;
        int sum=0;
        int len=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                
                maxlen=i+1;
            }
            
            int diff=sum-k;
            if(prefix.find(diff)!=prefix.end()){
                
                len=i-prefix[diff];
                maxlen=max(len,maxlen);
                
            }
            if(prefix.find(sum)==prefix.end()){
                
                prefix[sum]=i;
            }
            
            
        }
        return maxlen;
    }
};