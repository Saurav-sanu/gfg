

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
       vector<int> ans;
    int n = arr.size();
    int maxRight = arr[n - 1];
    ans.push_back(maxRight); // last element is always a leader

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxRight) {
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }

    reverse(ans.begin(), ans.end()); // to maintain order
    return ans;
    }
};