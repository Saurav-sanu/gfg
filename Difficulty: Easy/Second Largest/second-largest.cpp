class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int second=INT_MIN;
        int largest=INT_MIN;
        for(int i=0;i<arr.size();i++){
           if(arr[i]>largest){
               second=largest;
               largest=arr[i];
           }
           else if(arr[i]<largest){
               if(arr[i]>second){
                   second=arr[i];
               }
           }
        }
        if(second==INT_MIN){
            return -1;
        }
        return second;
        
    }
};