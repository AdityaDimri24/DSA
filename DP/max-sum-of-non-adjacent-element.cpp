#include <bits/stdc++.h>
using namespace std;
int dp[101];
int maxsum(int n,int arr[])
{
    if(n<=0)
    return 0;
    else if(dp[n]!=-1)
    return dp[n];
    else
    {
        
                int nottake=0,take=0;
                if(dp[n-1]!=-1)
                nottake=dp[n-1];
                else
                nottake=maxsum(n-1,arr);
                 if(n-2>=0&&dp[n-2]!=-1)
                take=dp[n-2];
                else
                take=maxsum(n-2,arr);
        return dp[n]= max(arr[n-1]+take,nottake);

    }
}
int main()
{
    int n,k;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<maxsum(n,arr);
}