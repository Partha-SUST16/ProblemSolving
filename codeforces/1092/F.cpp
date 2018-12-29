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
const int N = 200000+10;

int n;
ll arr[N];
ll ans,res,sum[N];

vii g[N];

void dfs(int u,int p,int l)
{
    res += 1LL*l*arr[u];
    sum[u] = arr[u];
    //debug(res);
    for(int v:g[u])
    {
        if(v==p)continue;
        dfs(v,u,l+1);
        sum[u]+=sum[v];
    }
}

void dfs2(int u,int p)
{
    ans = max(ans,res);
    for(int v:g[u])
    {
        if(v==p)continue;
        ll temp = res;
        ll down = sum[v];
        ll up = sum[1]-sum[v];
        res += up;res-=down;
        dfs2(v,u);
        res = temp;
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1,x,y;i<n;i++)
    {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1,-1,0);
    dfs2(1,-1);
    cout<<ans<<endl;
    return 0;
}
