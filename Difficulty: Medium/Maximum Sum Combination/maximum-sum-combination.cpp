class Solution {
  public:
  typedef pair<int,pair<int,int>>p;
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        vector<int>ans;
        priority_queue<p>pq;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        set<pair<int, int>> visited;

        
        pq.push({a[0]+b[0],{0,0}});
        visited.insert({0, 0});
        
        
        while(!pq.empty() && k--){
            auto temp=pq.top();
            pq.pop();
            
            int sum=temp.first;
            
            ans.push_back(sum);
            
            int i=temp.second.first;
            int j=temp.second.second;
            
            visited.insert({i,j});
            
            if(i+1< n && !visited.count({i+1,j})){
                pq.push({a[i+1]+b[j],{i+1,j}});
                visited.insert({i+1,j});
                
            }
             if(j+1< n && !visited.count({i,j+1})){
                pq.push({a[i]+b[j+1],{i,j+1}});
                visited.insert({i,j+1});
                
            }
            
            
            
            
        }
        return ans;
        
        
    }
};