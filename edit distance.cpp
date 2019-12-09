/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1. */


// dp solution

#include <bits/stdc++.h>
using namespace std;
int editdistance(string s1,string s2){
    
    int dp[s1.size()+1][s2.size()+1];
    
    for(int j=0;j<=s2.size();j++)
    dp[0][j]=j;
    
    for(int i=0;i<=s1.size();i++)
    dp[i][0]=i;
    
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    return dp[s1.size()][s2.size()];
    
    
}
int main() {
	
	int t; cin>>t;  while(t--){
	    
	    int n1,n2; cin>>n1>>n2;
	    string s1,s2;  cin>>s1>>s2;
	    
	    cout<<editdistance(s1,s2)<<endl;
	    
	}
	return 0;
}
