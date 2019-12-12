/*Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for palindrome partitioning of a given string. For example, minimum 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. The first line of every Test Case consists of S, denoting a String.

Output:
For each test case in a new line print an integer, denoting the number cuts in the String to make it palindromic.

Constraints:
1<=T<=100
1<=|Length of String|<=1000

Example:
Input:
2
ababbbabbababa
aaabba

Output:
3
1*/



// first recursion   indirectly a bactracking question

#include<bits/stdc++.h>
using namespace std;
bool check(string st ,int j,int i)
{
	int s=i; int e=j;
	
	while(s<=e)
	{
		if(st[s]==st[e])
		{s++; e--;}
		else 
		return false;
	}
	return true;
}
int countminpar(string st,int i,int n)
{   
     if(i>=n)
     return 0;
     
     int res=INT_MAX;
     	
     for(int j=i;j<n;j++)
     {
     	if(check(st,j,i))                       
     	res=min(res, 1+countminpar(st,j+1,n));
     }
     
     return res;
	
}
int main()
{
	string st="abcde";
	
	
	cout<<countminpar(st,0,st.size())<<endl;
	return 0;
}



// now dp solution



#include<bits/stdc++.h>
using namespace std;

int countminpar(string st)
{
         int n=st.size();
         bool P[n][n];
         int C[n];
         
         for(int i=0;i<n;i++)
         P[i][i]=true;
         
         
         for(int l=2;l<=n;l++)
         {
             for(int r=0;r<=n-l;r++)
             {
                 int j=r+l-1;
                 
                 if(st[r]==st[j]&&l==2)
                 P[r][j]=true;
                 else if(st[r]==st[j]&&P[r+1][j-1])
                 P[r][j]=true;
                 else
                 P[r][j]=false;
             }
         }
         
         
         
         for(int i=0;i<n;i++) {
           if(P[0][i]==true)
            C[i]=0;
            else
            { C[i]=INT_MAX;
           for(int j=0;j<i;j++)
            if(P[j+1][i]==true)
             C[i]=min(C[i],1+C[j]);  }}
             
             return C[n-1];
}
int main()
{   
    int t; cin>>t;  while(t--){
        
      string st;   cin>>st;
    
	
    	cout<<(countminpar(st))<<endl;}
	return 0;
}
