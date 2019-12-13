/*Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. Leading 0’s are not counted as digits. Print your output % 10^9+7.

Input:
The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains 2 integers n and sum.

Output:
Print the number of digits. Print -1 if answer is not possible.

Constraints:
1<=T<=30
1<=n<=100
1<=sum<=1000

Example:
Input:
1
2 2

Output:
2

Explaination:  2 numbers 11 and 20.*/


//// here we will discuss top down dp approach


#include<bits/stdc++.h>
using namespace std;
long long int dp[101][1001];

int countn(int n,int sum,int i){
	
	if(sum==0)
	return dp[n][sum]=1;
	if(sum<0)
	return 0;
	if(n==0)
	return 0;
	
    long long int count=0;
	
	 if(dp[n][sum]!=-1)
	 return dp[n][sum];
	for(int j=0;j<=9;j++)
	{
		if(sum-j>=0){
			
			if(j==0&&i==1)continue;         // here is only the role of i
			else
			count=(count+countn(n-1,sum-j,i+1))%1000000007;
		}
	}
	return dp[n][sum]=count;
}
int main(){
	
	int t; cin>>t; while(t--){
	
	int n;
	int sum;
	cin>>n>>sum;
	memset(dp,-1,sizeof(dp));
	int x=countn(n,sum,1);     // we are sending one only for help in not count no. with 0 at front
	if(x!=0)
	cout<<countn(n,sum,1)<<endl;
	else
	cout<<"-1"<<endl;
	    
	    
	}
	
	return 0;
}
