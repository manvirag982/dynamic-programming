/*H. Queries for Number of Palindromes
time limit per test5 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You've got a string s = s1s2... s|s| of length |s|, consisting of lowercase English letters. There also are q queries, each query is described by two integers li, ri (1 ≤ li ≤ ri ≤ |s|). The answer to the query is the number of substrings of string s[li... ri], which are palindromes.

String s[l... r] = slsl + 1... sr (1 ≤ l ≤ r ≤ |s|) is a substring of string s = s1s2... s|s|.

String t is called a palindrome, if it reads the same from left to right and from right to left. Formally, if t = t1t2... t|t| = t|t|t|t| - 1... t1.

Input
The first line contains string s (1 ≤ |s| ≤ 5000). The second line contains a single integer q (1 ≤ q ≤ 106) — the number of queries. Next q lines contain the queries. The i-th of these lines contains two space-separated integers li, ri (1 ≤ li ≤ ri ≤ |s|) — the description of the i-th query.

It is guaranteed that the given string consists only of lowercase English letters.

Output
Print q integers — the answers to the queries. Print the answers in the order, in which the queries are given in the input. Separate the printed numbers by whitespaces.

Examples
inputCopy
caaaba
5
1 1
1 4
2 3
4 6
4 5
outputCopy
1
7
3
4
2
Note
Consider the fourth query in the first test case. String s[4... 6] = «aba». Its palindrome substrings are: «a», «b», «a», «aba».*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
#define pi pair<int,int>
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end() 
#define i32 int32_t
#define i16 int16_t
#define endl "\n"
#define v2dd vector<vector<int>>
#define v2d(m,r,c) vector<vector<int>> m(r,(vector<int> (c)))
const int MAX =5002;
void pls()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
int q;
bool p[MAX][MAX];
int dp[MAX][MAX];
i32 main(){pls();  // time_t start,end;     // time(&start);// time(&end);
// .................................................................................................................................................   
   
   string s; cin>>s;
   cin>>q;
   int n=s.size();
   for(int i=0;i<n;i++)
   {
       dp[i][i]=1;
       p[i][i]=1;

   }

   for(int len=2;len<=n;len++)
   {
      for(int i=0;i<=n-len;i++)
      {
          int j=i+len-1;

          if(len==2  && s[i]==s[j])
              p[i][j]=1;

          if(len>2)
          {
                if(p[i+1][j-1] && s[i]==s[j])
                    p[i][j]=1;
          }

          dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];

          if(p[i][j])
            dp[i][j]++;


      }

   }

   // for(int i=0;i<n;i++){
   //  for(int j=0;j<n;j++)
   //      cout<<dp[i][j]<<" ";
   //  cout<<endl;}


    while(q--)
    {
          int l,r; cin>>l>>r;
          l--; r--;
          cout<<dp[l][r]<<endl;
    }

   
// ...................................................................................................................................
//   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 
 return 0;}
     


