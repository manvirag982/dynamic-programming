/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3*/




//as usual first recursion



#include <bits/stdc++.h>
using namespace std;
int formapalindrome(string st, int s, int e){
    
    if(s>=e)                   // when start crosses end or if single word i.e s==e
    return 0;
    else if(st[s]==st[e])
    return formapalindrome(st,s+1,e-1);     // if(both corner same check for further
    else 
    return min(1+formapalindrome(st,s+1,e),1+formapalindrome(st,s,e-1));   // if corner not equal means 
}
int main() 
{
	int t; cin>>t;  while(t--){
	    string st;  cin>>st;
	    
	    cout<<formapalindrome(st,0,st.size()-1)<<endl;   // two pointer technique start and end
	}
	return 0;
}



//// dyanmic memorization


#include <bits/stdc++.h>
using namespace std;
int dp[41][41];
int formapalindrome(string st, int s, int e)
{
    
    if(s>=e)
    return 0;
    else if(st[s]==st[e])
    {
        
        if(dp[s+1][e-1]!=-1)
        return dp[s+1][e-1];
        else
        return dp[s+1][e-1]=formapalindrome(st,s+1,e-1);
        
    }
    else
    {
        
        int x,y;
        if(dp[s+1][e]!=-1)
        x=dp[s+1][e];
        else
        x=dp[s+1][e]=formapalindrome(st,s+1,e);
        
        if(dp[s][e-1]!=-1)
        y=dp[s][e-1];
        else
        y=dp[s][e-1]=formapalindrome(st,s,e-1);
        
        return min(x+1,y+1);
        
    }
}   
int main() 
{
	int t; cin>>t;
	while(t--)
	{
	    string st;  cin>>st;
	    memset(dp,-1,sizeof(dp));
	    cout<<formapalindrome(st,0,st.size()-1)<<endl;
	}
	return 0;
}


//dp tabulation  there are two method 1..find longest common subsequence of string and it reverse the subtract string length -lcs





