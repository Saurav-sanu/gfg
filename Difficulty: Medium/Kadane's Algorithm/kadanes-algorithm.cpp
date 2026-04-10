class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int currSubarray=arr[0];
        int maxSubarray=arr[0];
        for(int i=1;i<arr.size();i++){
            currSubarray=max(arr[i],currSubarray+arr[i]);
            maxSubarray=max(maxSubarray,currSubarray);
        }
        return maxSubarray;
        
    }
};