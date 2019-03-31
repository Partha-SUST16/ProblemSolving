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
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

vector<vll>g;
vii vis,par,arr,arr1;
int n,m,flag;
string ans;
void ini()
{
    g.resize(n+5);
    par.resize(n+5);
    vis.resize(n+5);
    arr.resize(m+5);
    arr1.resize(m+5);
}
void dfs(int now,int pa,int type);
void inp()
{
    cin >> n >> m;
    ini();
    REP(i,m)
    {
        cin >> arr[i] >> arr1[i];
        g[arr[i]-1].push_back(arr1[i]-1);
        g[arr1[i]-1].push_back(arr[i]-1);
    }
    REP(i,n+3)vis[i]=0;
    dfs(0,-1,0);
}
void work()
{
    if(flag)
    {
        puts("NO");
        exit(0);
    }
    puts("YES");
    ans = "";
    for(int i=0;i<m;i++)
    {
        if(par[arr[i]-1]==0)
            ans+="0";
        else
            ans+="1";
    }
    cout<<ans<<endl;
    exit(0);
}
int main()
{
    inp();
    work();
    return 0;
}
void dfs(int now,int pa,int type)
{
    vis[now]=1;
    par[now]=type;
    for(int i:g[now])
    {
        if(!vis[i])
        {
            if(!type)
                dfs(i,now,1);
            else
                dfs(i,now,0);
        }
        else if(i!=pa)
        {
            if(par[i]==type)
                flag=1;
        }
    }
}
