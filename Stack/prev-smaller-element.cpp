#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void printPSE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout<<-1<<"\n";
    for (int i = 1; i < n; i++)
    {
        if(s.empty()){
        s.push(arr[i]);
        cout<<-1<<"\n";}
        else
        {
            if (arr[i] <= s.top())
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
    printPSE(arr, n);
    return 0;
}