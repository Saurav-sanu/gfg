class Solution {
  public:
  void merge(vector<int>&arr,int l,int m,int r){
      int n1=m-l+1;
      int n2=r-m;
      
      vector<int>left(n1);
      vector<int>right(n2);
      
      int k=l;
      for(int i=0;i<n1;i++){
          left[i]=arr[k++];
      }
      for(int i=0;i<n2;i++){
          right[i]=arr[k++];
      }
      
      //now merge
      int i=0;
      int j=0;
      k=l;
      while(i<n1 && j<n2){
          if(left[i]<=right[j]){
              arr[k++]=left[i++];
              
          }
          else{
              arr[k++]=right[j++];
          }
      }
      while(i<n1){
          arr[k++]=left[i++];
      }
      while(j<n2){
          arr[k++]=right[j++];
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l==r){
            return ;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
        
    }
};