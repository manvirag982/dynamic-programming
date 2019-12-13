/*Given a string, the task is to count all palindromic sub-strings present in it.

Input:

The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the length of the string, next line of test case contains the string


Output:

For each test case output a single line depecting the number of palindromic substrings present.


Constraints:

1<=T<=100
2<=N<=500


Example:

Input

2
5
abaab
7
abbaeae

Output

3
4

Explanation:

Test Case 1
Input : str = "abaab"
Output: 3
All palindrome substring are : "aba" , "aa" , "baab"

Test Case 2
Input : str = "abbaeae"
Output: 4
All palindrome substring are : "bb" , "abba" ,"aea","eae"*/



// prequisite longest palindrome substring


///dp solution

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin>>t; while(t--){
	    
	    int n; cin>>n;  string s; cin>>s;
	    int j;
	    int dp[n][n];
	    memset(dp,0, sizeof(dp));
	    int sum=0;
	    for(int l=2;l<=n;l++)    // we are checking string like first l=2,l=3...... and checking palindrome of string at each length
 	    {
	        for(int i=0;i<=n-l;i++)   // dp is same like matrix chain multiplication
	        {
	            j=l-1+i; 
	            
	            if(s[i]==s[j]&&(l==2||l==3)){
	                
	               dp[i][j]=1;
	               sum+=1;                         // we are filling 1 for palindrome and zero for non palindrome
                                                 //sum is calculating all ones i.e all palindromic substring
	            }
	            else if(s[i]==s[j]){
	                
	                dp[i][j]=dp[i+1][j-1];
	                sum+=dp[i][j];
	            }
	            
	        }
	    }
	    
	    cout<<sum<<endl;
	}
	return 0;
}
