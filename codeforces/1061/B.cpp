#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>
#define fw(x) freopen("x.txt","w",stdout)
#define For(i,a,b,c) for(int i = a;i < b;i+=c)
#define REP(i,n) for(int i = 0;i < n;++i)
#define REP1(i,n) for(int i = 1; i<=n;i++)
#define mem(a,s) memset(a,s,sizeof a)
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
#define pf printf
#define sc scanf
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define vii vector<int>
#define vll vector<ll>
#define vss vector<string>
#define debug(x)  cout<<#x"="<<(x)<<endl
#define pb push_back


using namespace std;


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/


//big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
//ll setBit1(ll num, int idx) {return num or (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

const int mod = 1000000007;


int main()
{
//    int n,m;
//    cin>>n>>m;
//    vii arr;
//    if(n==1)
//        return cout<<0<<endl,0;
//    for(int i=0,x; i<n; i++)
//        cin>>x,arr.pb(x);
//    sort(all(arr),greater<int>());
//
//    ll ans = 0,prev=arr[0];
//    for(int i=0; i<arr.size()-1; i++)
//    {
//        if(prev==0)
//        {
//            ans+=arr[i]-1;continue;
//        }
//        if(prev<=arr[i+1])
//        {
//            ans+=arr[i]-1;prev--;
//        }
//        else
//        {
//            ans+=arr[i]-(prev-arr[i+1]);
//            prev = arr[i+1];
//        }
//    }
//    ans+=min((ll)arr.back()-1,(ll)arr.back()-prev);
//    cout<<ans<<endl;
    ll n,m,tot=0;
    cin>>n>>m;
    ll arr[n+5];
    REP1(i,n)cin>>arr[i],tot+=arr[i];
    sort(arr+1,arr+n+1);
    ll req = 0,prev = 0;
    REP1(i,n)
    {
        req++;
        if(arr[i]>prev)
            prev++;
    }
    req+=(arr[n]-prev);
    cout<<tot-req<<endl;
    return 0;
}
