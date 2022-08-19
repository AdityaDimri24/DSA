#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int minmaxpath(int m,int n,int s,int row,vector<vector<int>>&arr)
{
   if(n==0||n>s)
    return INT_MIN;
   else if(m==row)
    return arr[m-1][n-1];
    
    else if(dp[m][n]!=-1)
    return dp[m][n];
    else
    {           
                 dp[m][n]= arr[m-1][n-1]+max(max(minmaxpath(m+1,n,s,row,arr),minmaxpath(m+1,n+1,s,row,arr)),minmaxpath(m+1,n-1,s,row,arr));
             return dp[m][n];
    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int> (n));
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
    {
        cin>>arr[i][j];
    }
    }
  
    memset(dp,-1,sizeof(dp));
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
    ans=max(ans,minmaxpath(1,i,n,m,arr));
    }
    cout<<ans<<"\n";
  }

}

