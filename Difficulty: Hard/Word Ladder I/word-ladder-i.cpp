//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord,1});
        
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            string word=node.first;
            
            int steps=node.second;
            int size=word.length();
            
            
            
            
            if(word==targetWord){
                return steps;
            }
            
            
            
            for(int i=0;i<size;i++){
                char ch=word[i];
                
                for(ch='a';ch<='z';ch++){
                    word[i]=ch;
                    
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word=node.first;
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends