/*Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.*/


// first understand meaning of subsequence ==== its instersection of subset and subarray ,,,means element may be discontinuous but we cant select previous element like subsset


//

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	int t; cin>>t;  while(t--){
	    int res=1;
	    int n ; cin>>n; int a[n]; for(int i=0;i<n;i++) cin>>a[i];
	    
	    int dp[n]={0};
	    dp[n-1]=1;
	    for(int i=n-2;i>=0;i--)     // we are just saving longest incresing subsequence at end at each e=index and using saving data
	    {
	        res=1;
	        for(int j=i+1;j<n;j++)
	        {
	            
	            if(a[i]<a[j])
	            res=max(res,dp[j]+1);
	            
	        }
	        dp[i]=res;
	    }
	    int x=*max_element(dp,dp+n);
	    cout<<x<<endl;
	}
	return 0;
}


