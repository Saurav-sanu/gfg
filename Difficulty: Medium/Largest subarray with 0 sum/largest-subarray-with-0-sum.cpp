class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int count=0;
        unordered_map<int,int>mp;
        int sum=0;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                count=max(count,i+1);
            }
            else if(mp.find(sum)!=mp.end()){
                count=max(i-mp[sum],count);
            }
            else{
                mp[sum]=i;
                
            }
            
            
        }
        return count;
        
    }
};