#include <bits/stdc++.h>
using namespace std;
int dp[101];
int houserobber(int start,int n,int arr[])
{
    if(n<=0)
    return 0;
    else if(start==2&&n<=1)
    {
        return 0;
    }
    else if(dp[n]!=-1)
    return dp[n];
    else
    {
        
                long long int nottake=0,take=0;
                if(dp[n-1]!=-1)
                nottake=dp[n-1];
                else
                nottake=houserobber(start,n-1,arr);
                 if(n-2>=0&&dp[n-2]!=-1)
                take=dp[n-2];
                else
                take=houserobber(start,n-2,arr);
         dp[n]= max(arr[n-1]+take,nottake);
         return dp[n];

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

    cout<<houserobber(1,n-1,arr)<<"\n"<<houserobber(2,n,arr);
}