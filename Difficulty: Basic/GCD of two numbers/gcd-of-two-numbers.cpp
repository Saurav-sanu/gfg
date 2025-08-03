class Solution {
  public:
  
    int gcd(int a, int b) {
        while(a!=b){
          if(a>=b){
              a=a-b;
          }
          else{
              b=b-a;
          }
      }
      return a==0?b:a;
      
        
    }
};
