// User function Template for C++

class Solution {
  public:
  void generate(int n,string output,vector<string>&ans){
      //base case
      if(output.length()==n){
          ans.push_back(output);
          return ;
      }
      
      generate(n,output+'0',ans);
      if(output.empty() || output.back()!='1'){
        generate(n,output+'1',ans);
          
      }
  }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        vector<string>ans;
        generate(num,"",ans);
      
        
        return ans;
    }
};