#include<bits/stdc++.h>

using namespace std;
bool subsetsum(int n,int k, vector<int> &arr)
{
    if(k==0)
    return true;
    else if(n==0||k<0)
    return false;
    else
    {
        return subsetsum(n-1,k-arr[n-1],arr)||subsetsum(n-1,k,arr);
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    subsetsum(n,k,arr);
}
int main()
{
    int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    // vector<vector<int>> arr(m,vector<int> (n));
    vector<int> arr(n);
    for(int j=0;j<n;j++)
    {
        cin>>arr[j];
    }
    
  
    // memset(dp,-1,sizeof(dp));
    
   cout<<subsetsum(n,k,arr)<<"\n";
    
  }
}
// int main() {

  
//   vector<int> arr = {1,2,3,4};
//   int k=4;
//   int n = arr.size();
                                 
//   if(subsetSumToK(n,k,arr))
//     cout<<"Subset with given target found";
//   else 
//     cout<<"Subset with given target not found";
// }

