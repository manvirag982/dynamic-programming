/*Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have 
same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same
index in the original string.*/



// total same as longest common subsequence
// we will find longest common subsequence in same string such that i!=j  index should be different



//dp


#include <bits/stdc++.h>
using namespace std;

int LRS(string st ,string st2){
    
    int n=st.size();
    int dp[n+1][n+1];   memset(dp,0,sizeof(dp));
    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            
            if(st[i-1]==st2[j-1]&&i!=j)
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    
    return dp[n][n];
}
int main() 
{
     int t; cin>>t; while(t--){
         
         int n; cin>>n;  string st; cin>>st;
         
         
         cout<<LRS(st,st)<<endl;
     }	
	return 0;
}
