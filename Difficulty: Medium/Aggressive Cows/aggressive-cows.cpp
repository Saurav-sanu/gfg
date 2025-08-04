class Solution {
  public:
  bool ispossible(vector<int>&stalls,int dist,int noofcows){
      int cow=1;
      int last=stalls[0];
      for(int i=1;i<stalls.size();i++){
          if(stalls[i]-last>=dist){
              cow++;
              last=stalls[i];
          }
          
      }
      return cow>=noofcows;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int s=1;
        int e=stalls[n-1]-stalls[0];
        
        int result=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(ispossible(stalls,mid,k)){
                result=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return result;
        
    }
};