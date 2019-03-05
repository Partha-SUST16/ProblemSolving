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
vector<pii>v;
int tree[4123456];
vector<pair<char,pii> > q;

void update(int l,int r,int pos,int b,int p)
{
    if(pos>r or pos<l)
        return;
    if(l==r)
    {
        tree[p] = b?v[pos].second:-1;
        return;
    }
    int mid = (l+r)>>1;
    update(l,mid,pos,b,p*2+1);
    update(mid+1,r,pos,b,p*2+2);
    tree[p] = max(tree[2*p+1],tree[2*p+2]);
}
int ffind(int l,int r,int x,int y,int p)
{
    if(v[r].first<=x)
        return -1;
    if(l==r)
        return l;
    int rem = -1,mid=(l+r)>>1;
    if(tree[2*p+1]>y)
        rem = ffind(l,mid,x,y,2*p+1);
    if(rem==-1 and tree[2*p+2]>y)
        rem = ffind(mid+1,r,x,y,p*2+2);
    return rem;
}
int main()
{
    fast;
    int n,x,y;
    string in;
    cin >> n;
    REP(i,n)
    {
        cin >> in >> x >> y;
        q.pb({in[0],{x,y}});
        v.pb({x,y});
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());

    for(int i=0; i<n; i++)
    {
        if(q[i].first=='a')
        {
            int pos = lower_bound(all(v), make_pair(q[i].second.first,q[i].second.second))-v.begin();
            update(0,v.size()-1,pos,1,0);
        }
        else if(q[i].first=='r')
        {
            int pos = lower_bound(all(v),make_pair(q[i].second.first,q[i].second.second))-v.begin();
            update(0,v.size()-1,pos,0,0);
        }
        else
        {
            int ans = ffind(0,v.size()-1,q[i].second.first,q[i].second.second,0);
            if(ans==-1)
                cout<<-1<<endl;
            else
                cout<<v[ans].first<<" "<<v[ans].second<<endl;
        }
    }
    return 0;
}
