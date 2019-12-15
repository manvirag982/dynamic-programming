/*Given an array sequence [A1 , A2 ...An], the task is to find the maximum possible sum of increasing subsequence S of length K such that Si1<=Si2<=Si3.........<=Sin.

INPUT
The first line contains an integer 'T' denoting the number of testcases. Then 'T' test cases follows. Each test case consists of two line containing two space separated integers 'N' and 'K' denoting the size of the array and length of the subsequence.

OUTPUT
Print the maximum possible sum. If their is no subsequence of length K print "-1".

CONSTRAINTS
1 <= T <= 100
1 <= N <= 100
1 <= a[i] <= 10^5
1 <= k <=100

Example
Input
1
8 3
8 5 9 10 5 6 19 8

Output
38

Explanation
In sample input Possible Increasing subsequence of Length 3 with maximum possible sum is 9 10 19*/


/// i would say best example of longest increasing subsequence  
// time complexty O(n^2)
// concept we need length k
// if we make LIS > k no sense becoz max k element will be last k becoz sum max since LIS
// so we will calculate only length<=k
#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

int main() 
{
    int t;
   	cin>>t;
 	   while(t--){
        
        int n,k; cin>>n>>k;
    
        lint s[n];    // it will fill max sum of LIS lenth <=k 
        lint l[n];     // it will store length of LIS it will also <=k
        lint a[n];  
          for(int i=0;i<n;i++){
          cin>>a[i];
          s[i]=a[i];       // initially filling element
          l[i]=1;          // initial length =1
        }
        
        //  LIS
        for(int i=n-2;i>=0;i--){
            lint res=INT_MIN;
                lint ix=-1;
                
            for(int j=n-1;j>i;j--){
                if(a[j]>a[i]){
                    if(l[i]+l[j]<=k&&l[j]>=res){     // this is main logic
                        res=l[j]; ix=j;               // we are saving index and length of lIS such that length <=k becoz we need only k length 
                    }
                }
                
            }
            if(res>0&&ix>0){       // if any element found
            s[i]+=s[ix];        
            l[i]+=l[ix];}   
        }
       
        lint res=INT_MIN;
        for(int i=n-1;i>=0;i--){      // thare are may be many LIS with length k so for max sum
            
            
            if(l[i]==k)
            res=max(res,s[i]);
        }
        if(res<0)
        cout<<"-1"<<endl;
        else
        cout<<res<<endl;
    }	
	return 0;
}
