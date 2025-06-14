// User function Template for C++

class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
        
    }
};