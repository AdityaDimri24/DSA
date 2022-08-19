#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int minpath(int m,int n, vector<vector<int>>&arr)
{
    if(m==0 ||n==0)
    return INT_MAX;
    else if(m==1&&n==1)
    return arr[0][0];
    else if(dp[m][n]!=-1)
    return dp[m][n];
    else
    {
        int path=INT_MAX;
             dp[m][n]= arr[m-1][n-1]+min(minpath(m-1,n,arr),minpath(m,n-1,arr));
             return dp[m][n];
    }
}
int main()
{
    int n,m;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int> (n));
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>arr[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<minpath(m,n,arr);

}