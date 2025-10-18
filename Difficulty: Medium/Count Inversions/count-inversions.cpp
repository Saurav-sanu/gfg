class Solution {
  public:
  int count=0;
  void merge(vector<int>&arr,int l,int mid,int r){
      int n1=mid-l+1;
      int n2=r-mid;
      vector<int>left(n1);
      vector<int>right(n2);
      
      int k=l;
      
      for(int i=0;i<n1;i++){
          left[i]=arr[k++];
      }
       for(int i=0;i<n2;i++){
           
          right[i]=arr[k++];
      }
      
      //now merege
      
      int i=0;
      int j=0;
      k=l;
      
      while(i<n1 && j<n2){
          if(left[i]<=right[j]){
              arr[k++]=left[i++];
          }
          else{
              arr[k++]=right[j++];
              count+=n1-i;
          }
      }
      while(i<n1){
          arr[k++]=left[i++];
      }
      while(j<n2){
          arr[k++]=right[j++];
      }
  }
  void mergesort(vector<int>&arr,int l,int r){
      //base case
      if(l==r){
          return ;
      }
      
      int mid=l+(r-l)/2;
      
      mergesort(arr,l,mid);
      mergesort(arr,mid+1,r);
      merge(arr,l,mid,r);
      
  }
    int inversionCount(vector<int> &arr) {
        
        mergesort(arr,0,arr.size()-1);
        return count;
    }
};