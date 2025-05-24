class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high){
            return ;
        }
        
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
        
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        
        int pivot=arr[high];
        int pi=low;
        
        for(int i=low;i<high;i++){
            if(arr[i]<=pivot){
                swap(arr[i],arr[pi]);
                pi++;
            }
        }
        swap(arr[pi],arr[high]);
        return pi;
    }
};