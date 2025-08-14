class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        int sum=0;
        int temp=0;
        for(auto &a:arr){
            pq.push(a);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            
            temp=a+b;
            sum+=temp;
            
            pq.push(temp);
        }
        return sum;
        
    }
};