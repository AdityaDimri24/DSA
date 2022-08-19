#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int griduniquepath(int m,int n, vector<vector<int>>&arr)
{
    if(m==0 ||n==0)
    return 0;
    else if(m==1&&n==1)
    return 1;
    else if(arr[m-1][n-1]==-1)
    return 0;
    else if(dp[m][n]!=-1)
    return dp[m][n];
    else
    {
        int go_up=0,go_left=0;
        
        go_up=griduniquepath(m-1,n,arr);
        go_left=griduniquepath(m,n-1,arr);
            return dp[m][n]=go_left+go_up;
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
    if(arr[m-1][n-1]!=-1)
    cout<<griduniquepath(m,n,arr);
    else cout<<0;
}