#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int minpath(int m,int n, int s,vector<vector<int>>&arr)
{
    if(m==s||n==s)
    return arr[m-1][n-1];
    else if(dp[m][n]!=-1)
    return dp[m][n];
    else
    {           
                 dp[m][n]= min(arr[m-1][n-1]+minpath(m+1,n,s,arr),arr[m-1][n-1]+minpath(m+1,n+1,s,arr));
             return dp[m][n];
    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<vector<int>> arr;
    vector<int> v;
    for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++)
    {
        int x;
        cin>>x;
    v.push_back(x);
    }
    arr.push_back(v);
        v.clear();

    }
  
    memset(dp,-1,sizeof(dp));
    cout<<minpath(1,1,n,arr)<<"\n";
  }

}

