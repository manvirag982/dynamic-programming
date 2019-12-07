/*Given an array arr of N integers. Find the contiguous sub-array with maximum sum.*/


#include <bits/stdc++.h>
using namespace std;
int kadane(int a[],int n){
    
    int sum=0;
    int res=INT_MIN;
    
    for(int i=0;i<n;i++){
        sum+=a[i];
        
        res=max(res , max(sum , a[i])); // since it is contiguous subarray so max at any index will be its value or sum of previous index and itself
        
        if(sum<0)
        sum=0;
    }
    return res;
}
int main() {
	
	
	// kadane algorithm
	
	int t;
	cin>>t;  
	while(t--){
	    
	    int n; cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    
	    cout<<kadane(a,n)<<endl;
	}
	return 0;
}
