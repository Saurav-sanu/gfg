class Solution {
  public:
  bool ispossible(vector<int>&arr,int mid,int k){
      int count=1;
      int pages=0;
      for(int i=0;i<arr.size();i++){
          if(pages+arr[i]>mid){
              count++;
              pages=arr[i];
          }
          else{
              pages+=arr[i];
          }
      }
      return count<=k;
  }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        // code here
        int s=*max_element(arr.begin(),arr.end());
        int e=accumulate(arr.begin(),arr.end(),0);
        
        int result=-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(arr,mid,k)){
                result=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
};