// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int ans=0;
        int temp=n;
        
        while(n){
            int digit=n%10;
            ans=ans+pow(digit,3);
            n=n/10;
        }
        if(ans==temp){
            return true;
        }
        else{
            return false;
        }
    }
};