class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long count=0;
        int n=arr.size();
        long sum=0;
        unordered_map<int,int>mp;
        mp.insert({0,1});
        for(int i=0;i<n;i++){
            sum^=arr[i];

            int diff=sum^k;
            if(mp.find(diff)!=mp.end()){
                count+=mp[diff];
            }
            mp[sum]++;
        }
        return (long )count;
    }
};