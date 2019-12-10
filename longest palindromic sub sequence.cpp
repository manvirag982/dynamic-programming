/*Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4*/




// recursion

#include<bits/stdc++.h> 
using namespace std; 

int lps(char seq[], int i, int j) 
{ 
// Base Case 1: If there is only 1 character 
if (i == j) 
	return 1; 

// Base Case 2: If there are only 2 
// characters and both are same 
if (seq[i] == seq[j] && i + 1 == j) 
	return 2; 

// If the first and last characters match 
if (seq[i] == seq[j]) 
	return lps (seq, i+1, j-1) + 2; 

// If the first and last characters do not match 
return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 


int main() 
{ 
	char seq[] = "GEEKSFORGEEKS"; 
	int n = strlen(seq); 
	cout <<lps(seq, 0, n-1); 
	return 0; 
} 



/// dp...for proper understanding draw dp table


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t; cin>>t;  while(t--){
        
    string st; cin>>st;
    int n=st.size();
    int dp[n][n];
    
    for(int i=0;i<n;i++)   // for substring length 1
    dp[i][i]=1;
    
    for(int sl=2;sl<=n;sl++)    // sl=substring length
    {
        for(int r=0;r<=n-sl;r++)
        {
            int j=r+sl-1;  //  r==one pointer , j= second pointer
        
             if(st[r]==st[j]&&sl==2)
             dp[r][j]=2;
             else if(st[r]==st[j])
             dp[r][j]=2+dp[r+1][j-1];
             else
             dp[r][j]=max(dp[r+1][j],dp[r][j-1]);
            
        }
    }
    
     cout<<dp[0][n-1]<<endl;    
    }
    return 0;
}
