// #include <bits/stdc++.h>
// using namespace std;
// int dp[101][101];
// int ninja(int row,int col1,int col2,int collen,int rowlen,vector<vector<int>>&arr)
// {
     

//     if(col1==0||col1>collen||col2==0||col2>collen)
//     return INT_MIN;
     
//    else if(row==rowlen)
//    {
//     if(col1==col2)
//     return arr[row-1][col1-1];
//     else
//     return arr[row-1][col1-1]+arr[row-1][col2-1];
//    }
//     else
//     {      
//         if(col1==col2)
//         return arr[row-1][col1-1]+max(max(ninja(row+1,col1,col2,collen,rowlen,arr),ninja(row+1,col1+1,col2+1,collen,rowlen,arr)),ninja(row+1,col1-1,col2-1,collen,rowlen,arr));
//         else
//        {int ans=INT_MIN;
//         for(int i=-1;i<=1;i++)
//         {
//             ans= max(ans,arr[row-1][col1-1]+arr[row-1][col2-1]+max(max(ninja(row+1,col1,col2+i,collen,rowlen,arr),ninja(row+1,col1+1,col2+i,collen,rowlen,arr)),ninja(row+1,col1-1,col2+i,collen,rowlen,arr)));
//         }
//         return ans;
//        }
//     }
// }
// int main()
// {
//   int t;
//   cin>>t;
//   while(t--)
//   {
//     int m,n;
//     cin>>m>>n;
//     vector<vector<int>> arr(m,vector<int> (n));
//     for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++)
//     {
//         cin>>arr[i][j];
//     }
//     }
  
//     memset(dp,-1,sizeof(dp));
    
//    cout<<ninja(1,1,n,n,m,arr)<<"\n";
    
//   }

// }

#include<bits/stdc++.h>

using namespace std;
int ninja(int row,int col1,int col2,int collen,int rowlen,vector<vector<int>>&arr,vector<vector<vector<int>>> &dp)
{
    
    if(col1==0||col1>collen||col2==0||col2>collen)
    return INT_MIN;
    else if(dp[row][col1][col2]!=-1)
        return dp[row][col1][col2];
   else if(row==rowlen)
   {
    if(col1==col2)
    return arr[row-1][col1-1];
    else
    return arr[row-1][col1-1]+arr[row-1][col2-1];
   }
    else
    {      
        if(col1==col2)
        return  arr[row-1][col1-1]+max(max(ninja(row+1,col1,col2,collen,rowlen,arr,dp),ninja(row+1,col1+1,col2+1,collen,rowlen,arr,dp)),ninja(row+1,col1-1,col2-1,collen,rowlen,arr,dp));
        else
       {int ans=INT_MIN;
        for(int i=-1;i<=1;i++)
        {
            ans= max(ans,arr[row-1][col1-1]+arr[row-1][col2-1]+max(max(ninja(row+1,col1,col2+i,collen,rowlen,arr,dp),ninja(row+1,col1+1,col2+i,collen,rowlen,arr,dp)),ninja(row+1,col1-1,col2+i,collen,rowlen,arr,dp)));
        }
        return  ans;
       }
    }
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
//     unordered_map<string,int> mp;
    vector < vector < vector < int >>> dp(r+1, vector < vector < int >> (c+1, 
  vector < int > (c+1, -1)));
    
    return ninja(1,1,c,c,r,grid,dp);
}
int main() {

   vector<vector<int> > matrix{
      {2,3,1,2},
      {3,4,2,2},
      {5,6,3,5},
  };

  int n = matrix.size();
  int m = matrix[0].size();

  cout << maximumChocolates(n, m, matrix);
}
