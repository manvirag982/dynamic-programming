/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last. */

................................................................................................................
//recusion solution 



#include <bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int i, int end)
{
    if(i >  end) 
    return 0;
    
    if( arr[i]==0 && i!= end) 
    return 0;
    
    if(i==end)
    return 0;
    
    int count =0;
    int min_count= INT_MAX;
    
    for (int j=1; j<= arr[i]; j++)
    {
        count = minJumps(arr, i+ j, end);
        min_count= min(min_count, count+1);
    }
    return  min_count;
}
int main() 
{
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  cout<<minJumps(arr, 0, n-1); 
	return 0;
}




//soution  worse case time complexity O(n2)

#include <bits/stdc++.h>
using namespace std;
typedef long int lint;
int main() {
	
	lint t ; cin>>t;  while(t--){
	    
	    lint n;  cin>>n; lint a[n];  for(int i=0;i<n;i++) cin>>a[i];
	    
	    lint dp[n];
	    dp[n-1]=0;
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        if(a[i]+i>=n-1)    // according to question
  	          dp[i]=1;
	        else
	          {
	              lint res=INT_MAX;
	              lint j=a[i];
	              lint k=i+1;
	              while(j--){
	                  
	                  res=min(res,dp[k++]);
	              }
	              dp[i]=res+1;
	          }
	        
	    }
	    if(dp[0]>n)          // ifdp[0] INT_MAX	 MEANS somewhere is zero present like 1,0  or 2 ,0,0 or 3,0,0,0 etc
            cout<<"-1"<<endl;
	    else
	    cout<<dp[0]<<endl;
	    
	}
	return 0;
}
