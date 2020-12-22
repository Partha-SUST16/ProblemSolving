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
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
#define maxn 300005
ll sum[maxn];
ll arr[maxn];
ll mup[maxn];
ll mlow[maxn];
ll mal[maxn];
ll n,x;
void work2()
{
    mup[n]=sum[n];
    for(int i=n-1;i>=1;--i)
        mup[i]=max(mup[i+1],sum[i]);

    for(int i=1;i<=n;++i)
        mlow[i]=min(mlow[i-1],sum[i]);

    mal[1]=min(0LL,(x-1)*sum[1]+mlow[1]);
    for(int i=2;i<=n;++i)
        mal[i]=min(mal[i-1],(x-1)*sum[i]+mlow[i]);
    ll ans=-mod;
    for(int i=1;i<=n;++i)
        ans=max(ans,mup[i]+(x-1)*sum[i]-mal[i]);
    cout<<ans<<endl;
    exit(0);
}
void work()
{
     for(int i=1;i<=n;++i)sum[i]=sum[i-1]+arr[i];
     work2();
}
int main()
{
    fast;
    cin>>n>>x;
    for(int i=1;i<=n;++i)
        cin>>arr[i];

    work();


    return 0;
}
