#include <bits/stdc++.h>
using namespace std;
int dp[101];
int ans=0;
int frogjump(int n,int arr[])
{
    if(n==0)
    return 0;
    else if(dp[n]!=-1)
    return dp[n];
    else{
        int j1=abs(arr[n]-arr[n-1]);
        if(n>1){
        int j2=abs(arr[n]-arr[n-2]);
          return dp[n]=min(j1+frogjump(n-1,arr), j2+frogjump(n-2,arr));
          // For more optimization check frogjump1 and frogjump2 whether they r present in dp or not before calling them. 
    }
    return dp[n]=j1;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<frogjump(n-1,arr);
}