#include <bits/stdc++.h>
using namespace std;
int dp[101];
int ans=0;
int kfrogjump(int n,int k,int arr[])
{
    if(n==0)
    return 0;
    else if(dp[n]!=-1)
    return dp[n];
    else{
        int jump=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(n-j>=0)
            {
                int addthis=0;
                if(dp[n-j]!=-1)
                addthis=dp[n-j];
                else
                addthis=kfrogjump(n-j,k,arr);
                jump= min(abs(arr[n]-arr[n-j])+addthis,jump);
            }
        }
        return dp[n]=jump;
        
          // For more optimization check frogjump1 and frogjump2 whether they r present in dp or not before calling them. 
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<kfrogjump(n-1,k,arr);
}