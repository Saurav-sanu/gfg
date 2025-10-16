class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        if (arr.empty()) return 0;

    sort(arr.begin(), arr.end());
    int len = 1, currLen = 1;
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currLen++; // consecutive
        } 
        else if (arr[i] != arr[i - 1]) {
            currLen = 1; // reset if not duplicate
        }
        // update maximum
        len = max(len, currLen);
    }

    return len;
        
    }
};