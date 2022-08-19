#include <bits/stdc++.h>
using namespace std;
// int dp[101][101];
// int ninja(int n, int arr[][3],int prevpicked )
// {
//     if(n==0)
//     return 0;
//     if(dp[n][prevpicked]!=-1)
//     return dp[n][prevpicked];
//     else{
//         int ans=INT_MIN;
//         for(int i=1;i<=3;i++)
//         {
//             if(prevpicked!=i)
//             ans=max(ans,arr[n-1][i-1]+ninja(n-1,arr,i));
//         }
//         return dp[n][prevpicked]=ans;        
//     }
// }
// int main()
// {
//     int n,k;
//     cin>>n;
//     int arr[n][3];
//     for(int i=0;i<n;i++)
//     for(int j=0;j<3;j++)
//     {
//         cin>>arr[i][j];
//     }
//     memset(dp,-1,sizeof(dp));
//     cout<<ninja(n,arr,-1);
// }

int ninja(int n, vector<vector<int>> &arr,int prevpicked,vector<vector<int>> &dp )
{
    if(n==0)
    return 0;
    else if(dp[n][prevpicked]!=-1)
    return dp[n][prevpicked];
    else{
        int ans=0;
        for(int i=1;i<=3;i++)
        {
            if(prevpicked!=i)
            ans=max(ans,arr[n-1][i-1]+ninja(n-1,arr,i,dp));
        }
         dp[n][prevpicked]=ans;        
        return ans;
    }
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
   vector<vector<int>> dp(n+1,vector<int> (4,-1));
//     for(int i=0;i<=n;i++)
//         for(int j=0;j<4;j++)
//             dp[i][j]=-1;
    
   return ninja(n,points, 0,dp);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
    cin>>n;
   vector<vector<int>>  arr(n,vector<int> (3,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<3;j++)
    {
        cin>>arr[i][j];
    }
    cout<<ninjaTraining( n, arr)<<"\n";
    
    
    
    }

}