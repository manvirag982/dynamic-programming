/*Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.*





//this is very easy dp question ince draw dp table by code you will see very easy
// dp solution



#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t; cin>>t;  while(t--){
        
        int a,b; cin>>a>>b;  
        
        string x,y;  cin>>x>>y;
        int res=0;
        int dp[a+1][b+1];
        memset(dp,0,sizeof(dp));
        
        
        for(int r=1;r<=a;r++)
        {
            for(int c=1;c<=b;c++)
            {
                if(x[r-1]==y[c-1])
                dp[r][c]=1+dp[r-1][c-1];       // we are only checking previous status and adding
                res=max(res,dp[r][c]);        // since when dp table is formed maximum value may be anywhere so we are calulating here,,,sothat no again lopp 
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

