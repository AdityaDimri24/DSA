#include <bits/stdc++.h>
using namespace std;
int dp[101];
int climbingstairs(int idx)
{
    int ans=0;
    if(idx==0||idx==1)
    return 1;
    else if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    else{
        int lhalf,rhalf;
        if(dp[idx-1]!=-1)
        lhalf= dp[idx-1];
        else
        lhalf=climbingstairs(idx-1);
        if(dp[idx-2]!=-1)
        rhalf= dp[idx-2];
        else
        rhalf=climbingstairs(idx-2);
        return lhalf+rhalf;
    }
    return dp[idx];
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<climbingstairs(n);
}