/*Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

Example:
 if you had four matrices A, B, C, and D, you would have:

    (ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

For example:

A: 10 × 30 matrix
B : 30 × 5 matrix
C : 5 × 60 matrix
Then,
     (AB)C = (10×30×5) + (10×5×60) 
           = 1500 + 3000 
           = 4500 operations
     A(BC) = (30×5×60) + (10×30×60) 
           = 9000 + 18000 
           = 27000 operations.
Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.

  Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 
  20x30, 30x10 and 10x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained 
  by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  */
  
  
  
  // 1...recursion
  
// Matrix Ai has dimension a[i-1] x a[i] 
// for i = 1..n 
 
#include <bits/stdc++.h>
using namespace std;

int matrixchain(int a[] ,int i ,int j){
    
    if(i==j){     // when product of matrix with itself
    return 0;    
    }
    
    int res=INT_MAX;
    
    for(int k=i;k<j;k++){                                                          //matrixchain(a,i,k)===for below like a ab abc
                                                                                   //matrixchain(a,k+1,j)===for below bcd ,cd,d
                                                                                   //a[i-1]*a[k]*a[j]= operation of combining of two part
        res=min(res,  matrixchain(a,i,k)+matrixchain(a,k+1,j)+a[i-1]*a[k]*a[j]);   // we are cutting string checking for different case and taking min of it
    }                                                                              // like abcd==(a,bcd) (ab,cd) (abc,d)
    
    return res;
    
    
}
int main() {
	
	int t; cin>>t;  while(t--){
	    
	    int n; cin>>n;  int a[n];  for(int i=0;i<n;i++) cin>>a[i];
	    cout<<matrixchain(a,1,n-1)<<endl;
	    }
	return 0;
}
  
  
  
  
 //  dp top down
 #include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int matrixchain(int a[] ,int i ,int j){
    
    if(i==j){
    dp[i][j]=0;
    return 0;    
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int res=INT_MAX;
    
    for(int k=i;k<j;k++){
        
        res=min(res,  matrixchain(a,i,k)+matrixchain(a,k+1,j)+a[i-1]*a[k]*a[j]);
    }
    
    dp[i][j]=res;
    return res;
    
    
}
int main() {
	
	int t; cin>>t;  while(t--){
	    
	    int n; cin>>n;  int a[n];  for(int i=0;i<n;i++) cin>>a[i];
	    memset(dp,-1,sizeof(dp));    
	    cout<<matrixchain(a,1,n-1)<<endl;
	    }
	return 0;
}




// dp bottom up approach



#include<bits/stdc++.h> 
using namespace std; 

int MatrixChainOrder(int p[], int n) 
{ 

	int m[n][n]; 

	int i, j, k, L, q; 

	for (i = 1; i < n; i++) 
		m[i][i] = 0; 

	// L is chain length. 
	for (L = 2; L < n; L++) 
	{ 
		for (i = 1; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; 
			m[i][j] = INT_MAX; 
			for (k = i; k <= j - 1; k++) 
			{ 
				q = m[i][k] + m[k + 1][j] + 
					p[i - 1] * p[k] * p[j]; 
				if (q < m[i][j]) 
					m[i][j] = q; 
			} 
		} 
	} 

	return m[1][n - 1]; 
} 
int main() 
{ 
	int arr[] = {1, 2, 3, 4}; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	cout<< MatrixChainOrder(arr, size); 

	return 0; 
} 

