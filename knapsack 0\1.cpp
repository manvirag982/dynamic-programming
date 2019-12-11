/*Given weights and values related to n items and the maximum capacity allowed for these items. 
What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?*/


// knapsack 0/1  recursion

#include <bits/stdc++.h> 
using namespace std; 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	
// Base Case 
if (n == 0 || W == 0) 
	return 0; 

// If weight of the nth item is more 
// than Knapsack capacity W, then 
// this item cannot be included 
// in the optimal solution 
if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 

// Return the maximum of two cases: 
// (1) nth item included 
// (2) not included 
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
					knapSack(W, wt, val, n-1) ); 
} 

 
int main() 
{ 
	int val[] = {a, b, c}; 
	int wt[] = {A, B, B}; 
	int W = w; 
	int n = sizeof(val)/sizeof(val[0]); 
	cout<<knapSack(W, wt, val, n); 
	return 0; 
} 

// knapsack 0/1 wihout duplicate

#include <iostream>
using namespace std;

int main() {
	
	int t; cin>>t;  while(t--)
	{
	    int n,w; cin>>n>>w;   int P[n],W[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>P[i]; 
	    for(int i=0;i<n;i++)
	    cin>>W[i];
	    

        int dp[n+1][w+1];
        
        for(int i=0;i<=w;i++)
        dp[0][i]=0;
        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        
        for(int r=1;r<=n;r++)
        {
            for(int c=1;c<=w;c++)
            {
                if(c<W[r-1])
                dp[r][c]=dp[r-1][c];
                else
                dp[r][c]=max((dp[r-1][c-W[r-1]]+P[r-1]),dp[r-1][c]);   /// notice dp[r-1] make table we are including that element
            }
        }
        
        cout<<dp[n][w]<<endl;
	}
	return 0;
}


// dp solution with duplicates

#include <iostream>
using namespace std;

int main() {
	
	int t; cin>>t;  while(t--)
	{
	    int n,w; cin>>n>>w;   int P[n],W[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>P[i]; 
	    for(int i=0;i<n;i++)
	    cin>>W[i];
	    

        int dp[n+1][w+1];
        
        for(int i=0;i<=w;i++)
        dp[0][i]=0;
        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        
        for(int r=1;r<=n;r++)
        {
            for(int c=1;c<=w;c++)
            {
                if(c<W[r-1])
                dp[r][c]=dp[r-1][c];
                else
                dp[r][c]=max((dp[r][c-W[r-1]]+P[r-1]),dp[r-1][c]);    // here dp[r... including means duplicate
            }
        }
        
        cout<<dp[n][w]<<endl;
	}
	return 0;
}
