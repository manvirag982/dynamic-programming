/*Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0 */
 

//  this is best indirectly dynamic program related only to memorization
// logic is simple but doesnot come in quickly
//          
//    before solving question i can think like if we do something so that another dp matrix save size of sub matrix
//     becoz, if there is submatrix then  1 1 ,   means if right corner =1 and across three also one
//                                        1 1     by using this thinking solved question

#include<bits/stdc++.h>
using namespace std; 
int a[50][50];

int sizeofmatrix(int r ,int c){
    
    int dp[r][c];
    
    for(int i=0;i<c;i++)
    dp[0][i]=a[0][i];
    for(int i=0;i<r;i++)
    dp[i][0]=a[i][0];
    
    int res=INT_MIN;
    for(int i=1;i<r;i++)
    {
        for(int j=1; j<c ;j++)
        {
            if(a[i][j]==1)
            dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));   // it will store submatrix size contain dp[i][j] as bottom right corner
            else
            dp[i][j]=0;
            
            cout<<dp[i][j]<<"  ";
            
            res=max(res,dp[i][j]);
        }
        cout<<endl;
    }
    if(res<0)
    return 0;
    else
    return res;
}
int main(){
    
    int t; cin>>t;  while(t--){
        
        int r,c; cin>>r>>c;
        
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
           {
			         cin>>a[i][j]; }
			 
        }
        
        cout<<sizeofmatrix(r,c)<<endl;
    }
}
