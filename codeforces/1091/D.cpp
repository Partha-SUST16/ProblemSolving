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

const int mod = 998244353;

ll n;
vll a1, a2;

ll flau(ll n, ll k)
{
    return (a1[n] * a2[k]) % mod;
}
ll px(ll x, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p % 2)
        {
            res = (res * x) % mod;
            --p;
        }
        else
        {
            x = (x * x) % mod;
            p /= 2;
        }
    }
    return res;
}
void pre()
{
    a1.assign(n + 1, 1);
    a2.assign(n + 1, 1);
    for (ll i = 1; i <= n; ++i)
    {
        a1[i] = (a1[i - 1] * i) % mod;
        a2[i] = px(a1[i], mod - 2);
    }
}
void work()
{
    ll ans = a1[n];
    for (ll k = 2; k < n; ++k)
        ans = (ans + (flau(n, k) * (((n - k) * (k - 1)) % mod))) % mod;
    cout << ans<<endl;

}
int main()
{
    cin >> n;
    pre();
    work();
    return 0;
}
