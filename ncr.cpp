/*Find nCr for given n and r.

Input:
First line contains number of test cases T. T testcases follow. Each testcase contains 1 line of input containing 2 integers n and r separated by a space.

Output:
For each testcase, in a new line, find the nCr. Modulus your output to 109+7.

Constraints:
1 <= T <= 50
1<= n <= 103
1<= r <=800

Example:
Input:
2
3 2
4 2
Output:
3
6




// find ncr dynamic programming

// simple if we know that ncr=n-1cr-1 + n-1cr







#include <iostream>
using namespace std;
typedef long int lint;
int main() {
	
	lint t;
	cin>>t;  
	while(t--){
	    
	    lint N,R;  cin>>N>>R;
	    
	    lint ncr[R+1][N+1];
	    
	    for(lint i=0;i<=N;i++) ///  nc0==1
	    ncr[0][i]=1;
	    
	    for(lint i=1;i<=R;i++)
	    ncr[i][0]=0;      // 0Cr=0
	    
	    
	    for(lint r=1;r<=R;r++)
	    {
	        for(lint n=1;n<=N;n++)
	        {
	            ncr[r][n]=(ncr[r-1][n-1]+ncr[r][n-1])%1000000007;   
	        }
	    }
	    cout<<ncr[R][N]<<endl;
	}
	return 0;
}
