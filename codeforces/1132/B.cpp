#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long n;cin >> n;
    long long arr[n+5],tot=0;
    for(long long i=0;i<n;i++)
        cin >> arr[i],tot+=arr[i];
    sort(arr,arr+n,greater<long long>());
    long long q;
    cin >> q;
    for(long long i=0;i<q;i++)
    {
        long long x;cin >> x;
        cout<<tot-arr[x-1]<<endl;
    }
    return 0;
}
