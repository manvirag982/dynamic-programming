/*Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.*/




// first we will discuss recursion solution


#include <bits/stdc++.h> 
using namespace std; 

bool isSubsetSum (int arr[], int n, int sum) 
{ 
	// Base Cases 
	if (sum == 0) 
		return true; 
	if (n == 0 && sum != 0) 
		return false; 

	// If last element is greater than sum, then 
	// ignore it 
	if (arr[n-1] > sum) 
	return isSubsetSum (arr, n-1, sum); 

	/* else, check if sum can be obtained by any of 
		the following 
		(a) including the last element 
		(b) excluding the last element 
	*/
	return isSubsetSum (arr, n-1, sum) || 
		isSubsetSum (arr, n-1, sum-arr[n-1]); 
} 

bool findPartiion (int arr[], int n) 
{ 
	int sum = 0; 
	for (int i = 0; i < n; i++) 
	sum += arr[i]; 

	if (sum%2 != 0) 
	return false; 

	return isSubsetSum (arr, n, sum/2); 
} 

int main() 
{
	int t;
	cin>>t; 
	while(t--){
	    
	    int n; 
	    cin>>n;
	    int a[n]; 
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
      if (findPartiion(arr, n) == true) 
		  cout <<"YES"<<endl; 
	    else
		   cout <<"NO"<<endl;
			}
	return 0; 
} 






//now dynamic programming solution


#include <bits/stdc++.h>
using namespace std;
bool subsetsum(int a[],int n ,int sum){
    
    // using standard dynamic algo for subset sum
    
    bool dp[n+1][sum+1];
    
    dp[0][0]=1;
    
    for(int s=1;s<=sum;s++)
    dp[0][s]=0;
    
    for(int v=1;v<=n;v++)
    dp[v][0]=1;
    
    for(int v=1;v<=n;v++)           // since v=1 ==== array a , index==0
    {
        for(int s=1;s<=sum;s++)
        {
            if(a[v-1]==s)
            dp[v][s]=1;
            else if(a[v-1]<s)
            dp[v][s]=dp[v-1][s-a[v-1]]||dp[v-1][s];// check sum subtracting this element and not including that
            else
            dp[v][s]=dp[v-1][s];    //if sum < that value so we check not including 
        }
    }
    

    return dp[n][sum];
}
int main()
{
	
	int t;
	cin>>t; 
	while(t--){
	    
	    int n; 
	    cin>>n;
	    int a[n]; 
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    int sum=accumulate(a,a+n,0); // sum of all element
	    
	    // since we have to divide into two so sum must be even if not then it can't be
	    
	    if(sum%2!=0)
	    {cout<<"NO"<<endl; continue;}
	    
	    // sum it is applicatioin of subsetsum problem now we have to check only whether sum/2 is present or not becoz total sum=2*(sum/2)
	    
	    if(subsetsum(a,n,sum/2))
	    cout<<"YES"<<endl;
	    else 
	    cout<<"NO"<<endl;
	}
	return 0;
}
