// #include <bits/stdc++.h>
// using namespace std;
// void printNSE(int arr[], int n)
// {
//     stack<int> s;
//     s.push(arr[0]);
//     for (int i = 1; i < n; i++)
//     {
//         if (s.empty())
//         {
//             s.push(arr[i]);
//         }
//         else
//         {
//             while (!s.empty())
//             {
//                 if(s.top() > arr[i]){
//                     cout << s.top() << " " << arr[i] << "\n";
//                     s.pop();
//                 }
//                 else break;
                    
//             }
//             s.push(arr[i]);
//         }
//     }
//     while (!s.empty())
//     {
//         cout << s.top() << " " << -1 << "\n";
//         s.pop();
//     }
// }
// int main()
// {
//     int arr[] = {11, 13, 21, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printNSE(arr, n);
//     return 0;
// }


// to maintain stability 

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void printNSE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[n-1]);
    cout<<arr[n-1]<<" "<<-1<<"\n";
    for (int i = n-2; i >=0; i--)
    {
        if(s.empty()){
        s.push(arr[i]);
        cout<<arr[i]<<" "<<-1<<"\n";}
        else
        {
            if ( s.top()>=arr[i])
            {
                while (s.empty() == false && arr[i] <= s.top())
                {
                    s.pop();
                }
                if (s.empty() == false)
                {
                    cout<<arr[i]<<" "<<s.top()<<"\n";
                    s.push(arr[i]);
                }
                else
                {
                    cout<<arr[i]<<" "<<-1<<"\n";
                }
            }
            else
            {
                cout<<arr[i]<<" "<<s.top()<<"\n";
                s.push(arr[i]);
            }
        }
        
    }
}
int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}