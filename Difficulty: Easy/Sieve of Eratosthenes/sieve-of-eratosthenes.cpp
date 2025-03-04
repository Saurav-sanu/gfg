//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<bool>isPrime(N+1,true);
        vector<int>result;
        isPrime[0]=false;
        isPrime[1]=false;
        
        for(int i=2;i<=N;i++){
            if(isPrime[i]==true){
                result.push_back(i);
                for(int j=2;i*j<=N;j++){
                    isPrime[i*j]=false;
                }
            }
           
        }
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends