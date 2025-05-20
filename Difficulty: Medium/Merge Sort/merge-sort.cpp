class Solution {
  public:
  void merge(vector<int>&arr,int l,int m,int r){
      //base case
      int n1=m-l+1;
      int n2=r-m;
      
      int k=l;
      
      int L[n1],R[n2];
      for(int i=0;i<n1;i++){
          L[i]=arr[k];
          k++;
      }
      for(int i=0;i<n2;i++){
          R[i]=arr[k];
          k++;
      }
      
      int i=0;
      int j=0;
      k=l;
      
      while(i<n1 && j<n2){
          if(L[i]<=R[j]){
              arr[k]=L[i];
              i++;
          }
          else{
              arr[k]=R[j];
              j++;
          }
          k++;
      }
      while(i<n1){
          arr[k]=L[i];
          i++;
          k++;
      }
      while(j<n2){
          arr[k]=R[j];
          j++;
          k++;
          
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l==r){
            return;
        }
        int mid=l+(r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
        
    }
};