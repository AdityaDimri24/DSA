#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int griduniquepath(int m,int n)
{
    if(m==0 ||n==0)
    return 0;
    if(m==1&&n==1)
    return 1;
    else if(dp[m][n]!=-1)
    return dp[m][n];
    else
    {
        
            return dp[m][n]=griduniquepath(m-1,n)+griduniquepath(m,n-1);
    }
}
int main()
{
    int n,m;
    cin>>m>>n;
    // int arr[m][n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<griduniquepath(m,n);
}