/*Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the number of key.

Output:
Print maximum number of A's. Print -1, if N is greater than 75.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 75

Example:
Input:
2
3
7

Output:
3
9

Explanation:
Testcase 1:  We can at most get 3 A's on screen by pressing following key sequence.
A, A, A.
Testcase 2: We can at most get 9 A's on screen by pressing following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V */



// recursion same as dp

#include <stdio.h> 

int specialkeyword(int N) 
{ 
	if (N <= 6) 
		return N; 

              int res=INT_MIN;                          
	            for(int j=N-3;j>=0;j--)                
	           res=max(res,(j+2)*specialkeyword(N-j-3));           
	           
             return res;
	        
    
} 

int main() 
{ 
     int t; cin>>t; while(t--)
    {
         int n; cin>>n;
         cout<<specialkeywords(n)<<endl;
     }
     return 0;
	
} 



// this is according to me good question becoz recurvise 

// dp solution all same is recursion


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; 
	cin>>t;
	int dp[76];   // constraints
	dp[0]=0;
	for(int i=1;i<=6;i++)
	dp[i]=i;
	while(t--){
	    
	    int n; cin>>n;      
	    if(n>75)
	    cout<<"-1"<<endl;
	    else if(n<=6)
	    cout<<n<<endl;
	    else
	    {
	        for(int i=7;i<=n;i++)
	        {
	            int res=INT_MIN;                        //   try count upto 15 manually   
	            for(int j=i-3;j>=0;j--)                // you will see that optimal will be A Ca Cc Cv Cv Cv Cv.......  always ctrl v but problem in printing intitial A....how much print i.e checking allposibilities  
	           res=max(res,(j+2)*dp[i-j-3]);           // genrate formula manually
	           dp[i]=res;
	        }
	        
	        cout<<dp[n]<<endl;
	        
	    }
	}
	return 0;
}
