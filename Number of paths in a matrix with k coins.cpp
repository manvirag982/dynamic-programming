/*Given a N x N matrix where every cell has some number of coins. Count number of ways to reach bottom right cell of matrix from top left cell with exactly K coins. We can move to (i+1, j) or (i, j+1) from a cell (i, j).

Input:
First line contains number of test cases T. For each test case, first line contains the integer value 'X' denoting coins, second line contains an integer 'N' denoting the order of square matrix. Last line contains N x N elements in a single line in row-major order.

Output:
Output the number of paths possible.

Constraints:
1 <=T<= 500
1 <= K <= 200
1 <= N <= 200
1 <= Ai <= 200

Example:
Input:
2
16
3
1 2 3 4 6 5 9 8 7
12
3
1 2 3 4 6 5 3 2 1

Output:
0
2

Explanation:
Testcase 2: There are 2 possible paths with exactly K coins, which are (1 + 4 + 3 + 2 + 1) and (1 + 2 + 3 + 5 + 1).*/




...............................................................
//this is also bactracking question
// we will do it by top down dynamic programming




#include <bits/stdc++.h>
using namespace std;
#define max 50                  
typedef long long int lint;
lint dp[max][max][max];
lint exactkcoins(vector< vector<lint> > & m,int r,int c,int sum){         // since question has optimal substracture property
                                                                          // we are moving from bottom
    if(r<0||c<0)  return 0;        //out of matrix
    if(sum<0) return 0;            // when >k coins
    if(dp[r][c][sum]!=-1)           /// top down dp
    return dp[r][c][sum];
     
    if(sum==m[0][0]&&r==0&&c==0){        // this is imp base case sum==m[0][0] becoz when we reach m[0][0] sum has not reduced at m[0][0]        
        dp[r][c][sum]=1;
        return 1;
    }
    
    
    dp[r][c][sum]=( exactkcoins(m,r,c-1,sum-m[r][c])+exactkcoins(m,r-1,c,sum-m[r][c]));      // two ways left and up becoz in reverse
    
    return dp[r][c][sum];
    
}
int main() {
	
	int t; cin>>t; while(t--){
	 int k,n; cin>>k>>n;  
	  memset(dp,-1,sizeof(dp));
       vector< vector<lint> > m(n, vector<lint> (n));   // using vector 2d matrix is good idea instead of 2d array matrix	 
	 
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        cin>>m[i][j];
	    }
	 
	 cout<<exactkcoins(m,n-1,n-1,k)<<endl;
	 
	}
	
	return 0;
}
