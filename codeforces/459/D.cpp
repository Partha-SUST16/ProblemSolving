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
ll qpow(ll n,ll k)
{
    ll ans=1;
    assert(k>=0);
    n%=mod;
    while(k>0)
    {
        if(k&1)
            ans=(ans*n)%mod;
        n=(n*n)%mod;
        k>>=1;
    }
    return ans%mod;
}

deque<int>lft,rght;
map<int,int>mp;
int n,arr[1000005];
vii tree[1000005*4];

void build(int pos,int l,int r)
{
    if(l>r)
        return;
    for(int i=l; i<=r; i++)
        tree[pos].pb(rght[i]);
    sort(all(tree[pos]));

    if(l==r)
        return;
    int mid = (l+r)>>1;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
}
int query(int pos,int L,int R,int l,int r,int v)
{
    if(r<L or R<l)
        return 0;

    if(l<=L and R<=r)
    {
        return (upper_bound(all(tree[pos]),v-1)-tree[pos].begin());

    }
    int mid = (L+R)/2;
    int a = query(2*pos,L,mid,l,r,v);
    int b =query(2*pos+1,mid+1,R,l,r,v);
    return a+b;
}
int cc[1000 * 1000 + 10];
int t[1000 * 1000 + 10];

void upd(int i, int v)
{
    //cerr << "upd(" << i << ", " << v << ")\n";
    while(i <= n)
    {
        //cerr << "i = " << i << "\n";
        t[i] += v;
        i += i & (-i);
    }
}

int get(int i)
{
    //cerr << "get(" << i << ")\n";
    int rs = 0;
    while(i)
    {
        //cerr << "i = " << i << "\n";
        rs += t[i];
        i -= i & (-i);
    }
    return rs;
}
int main()
{
    fast;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
//    for(int i=0;i<n;i++)
//    {
//        lft.pb(++mp[arr[i]]);
////        debug(v1[i]);
//    }
//    mp.clear();
//    for(int i=n-1;i>=0;i--)
//        rght.push_front(++mp[arr[i]]);
////    REP(i,n)cout<<v2[i]<< " ";
//
//    ll ans = 0;
//    build(1,0,n-1);
//
//    for(int i=0;i<n-1;i++)
//    {
//        ans += (ll)query(1,0,n-1,i+1,n-1,lft[i]);
//    }
//    cout<<ans<<endl;
    for(int i = n; i >= 1; i--)
    {
        cc[i] = ++mp[arr[i]];
        upd(cc[i], +1);
    }
    mp.clear();
    long long rs = 0;
    for(int i = 1; i <= n; i++)
    {
        mp[arr[i]]++;
        upd(cc[i], -1);
        rs += get(mp[arr[i]]-1);
    }
    cout << rs << endl;
    return 0;
}
