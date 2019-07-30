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

const int N = (int)2e5+5;
const int mod = 1000000007;
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

ll arr[N],seg[N*4];

void build(int id,int s,int e)
{
    if(s==e)
    {
        seg[id] = arr[s];
        return;
    }
    int mid = (s+e)>>1;
    int left = 2*id,right = left + 1;
    build(left,s,mid);
    build(right,mid+1,e);
    seg[id]= max(seg[left],seg[right]);
}
ll query(int id,int s,int e,int l,int r)
{
    if(s>r or e<l)return 0;
    if(s>=l and e<=r)return seg[id];
    int mid = (s+e)>>1;
    int left = 2*id,right = left+1;
    return max(query(left,s,mid,l,r),query(right,mid+1,e,l,r));
}
int main()
{
    int n;
    cin >> n ;
    vector<pll>a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first;
        a[i].second = 0;
    }
    int q;
    cin >> q;
    for(int i=1,x,y;i<=q;i++)
    {
        cin >> x >> y;
        if(x==1)
        {
            cin >> x;
            y--;
            a[y] = {x,i};
            arr[i] = 0;
        }else
            arr[i] = y;
    }
    build(1,1,q);
    for(int i = 0;i<n;i++)
    {
        ll mx = a[i].first;
        mx = max(mx,query(1,1,q,a[i].second,q));
        cout<<mx<<' ';
    }
    return 0;
}
