/*Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} 
valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions:
{1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.*/

// recursion

#include<stdio.h> 

int count( int S[], int m, int n ) 
{ 
	// If n is 0 then there is 1 solution 
	// (do not include any coin) 
	if (n == 0) 
		return 1; 
	
	// If n is less than 0 then no 
	// solution exists 
	if (n < 0) 
		return 0; 

	// If there are no coins and n 
	// is greater than 0, then no 
	// solution exist 
	if (m <=0 && n >= 1) 
		return 0; 

	// count is sum of solutions (i) 
	// including S[m-1] (ii) excluding S[m-1] 
	return count( S, m - 1, n ) + count( S, m, n-S[m-1] ); 
} 

int main() 
{ 
	int i, j; 
	int arr[] = {1, 2, 3}; 
	int m = sizeof(arr)/sizeof(arr[0]); 
	cout<<count(arr, m, 4)); 
	return 0; 
} 




// dp solution

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t; cin>>t;  while(t--){
        
        int n; cin>>n;  int a[n];  for(int i=0;i<n;i++) cin>>a[i];
        int s; cin>>s;
        
        int dp[n+1][s+1];
        
        for(int i=1;i<=s;i++)
        dp[0][i]=0;
        for(int i=0;i<=n;i++)
        dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(j<a[i-1])
                dp[i][j]=dp[i-1][j];           // if coin > sum we can't include it ,,so we wiil fill previous value
                else
                dp[i][j]=dp[i][j-a[i-1]]+dp[i-1][j];    //   like  2,3 coins  sum =5  now i select 2 coin then i will have to see total combinatio of 5-2=3   
            }
        }
        
        cout<<dp[n][s]<<endl;
    }
    return 0;
}



.......................................//application
	/*Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. Leading 0’s are not counted as digits. Print your output % 10^9+7.*/
