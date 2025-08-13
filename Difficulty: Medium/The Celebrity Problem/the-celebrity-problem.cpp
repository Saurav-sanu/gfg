class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>st;
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(mat[a][b]==1){
                st.push(b);
            }
            else{
                st.push(a);
            }
            
         
        }
        int celeb=st.top();
        
        for(int i=0;i<mat.size();i++){
            if(i!=celeb && (mat[i][celeb]==0 || mat[celeb][i]==1 )){
                return -1;
            }
        }
        return celeb;
    }
};