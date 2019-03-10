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
#define stree ll l = 2*pos,r=l+1

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

const int N = 1e6+9;

struct node
{
    ll n4,n7,n47,n74;
    node() {}
    node(ll a,ll b,ll c,ll d)
    {
        n4 = a;
        n7 = b;
        n47 = c;
        n74 = d;
    }
} tree[N*4];

bool isLazy[N*4];
string s;
void shift(ll pos)
{
    stree;
    if(isLazy[pos])
    {
        isLazy[l]^=1;
        isLazy[r]^=1;
        swap(tree[l].n4,tree[l].n7);
        swap(tree[l].n47,tree[l].n74);
        swap(tree[r].n4,tree[r].n7);
        swap(tree[r].n47,tree[r].n74);
    }
    isLazy[pos] = 0;
}
void build(ll pos,ll b,ll e)
{
    if(b==e)
    {
        tree[pos] = node(s[b]=='4',s[b]=='7',1,1);
        return;
    }
    ll mid = (b+e)>>1;
    stree;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[pos] = node(tree[l].n4+tree[r].n4, tree[l].n7+tree[r].n7,
                     max(tree[l].n47+tree[r].n7,tree[l].n4+tree[r].n47),
                     max(tree[l].n74+tree[r].n4,tree[l].n7+tree[r].n74));
}
void update(ll pos,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
        return;
    if(b>=i&&e<=j)
    {
        isLazy[pos]^=1;
        swap(tree[pos].n4,tree[pos].n7);
        swap(tree[pos].n47,tree[pos].n74);
        return;
    }
    shift(pos);
    ll mid=(b+e)>>1,l=2*pos,r=l+1;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    tree[pos]=node(tree[l].n4+tree[r].n4,tree[l].n7+tree[r].n7,max(tree[l].n47+tree[r].n7,tree[l].n4+tree[r].n47),max(tree[l].n74+tree[r].n4,tree[l].n7+tree[r].n74));
}
int main()
{
    fast;
    string t;
    ll n,q,l,r;
    cin >> n >> q >> s;
    build(1,0,n-1);
    while(q--)
    {
        cin >> t;
        if(t=="switch")
        {
            cin >> l >> r;
            --l,--r;
            update(1,0,n-1,l,r);
        }
        else
            cout<<tree[1].n47<<endl;
    }
    return 0;
}
