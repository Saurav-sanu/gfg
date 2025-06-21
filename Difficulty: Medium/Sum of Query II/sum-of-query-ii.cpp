// User function Template for C++

class Solution {
  public:
  void buildSegmentTree(int i,int l,int r,vector<int>&segment,int arr[]){
      if(l==r){
          segment[i]=arr[l];
          return ;
      }
      int mid=l+(r-l)/2;
      buildSegmentTree(2*i+1,l,mid,segment,arr);
      buildSegmentTree(2*i+2,mid+1,r,segment,arr);
      
      segment[i]=segment[2*i+1]+segment[2*i+2];
      
  }
  
  int query(int start,int end,int i,int l,int r,vector<int>&segment){
      if(l>end || r<start){
          return 0;
      }
      if(l>=start && r<=end){
          return segment[i];
      }
      int mid=l+(r-l)/2;
      
      return query(start,end,2*i+1,l,mid,segment)+ query(start,end,2*i+2,mid+1,r,segment);
      
  }
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // code here
    
        vector<int>segment(4*n);
        buildSegmentTree(0,0,n-1,segment,arr);
        vector<int>result;
        
        for(int i=0;i<2*q;i+=2){
            int start=queries[i]-1;
            int end=queries[i+1]-1;
            
            result.push_back(query(start,end,0,0,n-1,segment));
        }
        return result;
        
        
    }
};