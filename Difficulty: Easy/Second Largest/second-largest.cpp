class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int second=INT_MIN;
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>ans){
                second=ans;
                ans=arr[i];
                
            }
            if(arr[i]>second && arr[i]<ans){
                second=arr[i];
            }
        }
        if(second==INT_MIN){
            return -1;
        }
        return second;
        
    }
};