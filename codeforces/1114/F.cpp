#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL)//;cout.tie(NULL)
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

const int mod = 1e9+7;
ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
const int N=300,M=4e5+9;

struct BIT {
    ll dataMul[M],dataAdd[M];
    void internalUpdate(int at, long long mul, long long add) {
        while (at < M) {
            dataMul[at] += mul;
            dataAdd[at] += add;
            at |= (at + 1);
        }
    }
    void update(int left, int right, long long by) {
        internalUpdate(left, by, -by * (left - 1));
        internalUpdate(right, -by, by * right);
    }
    long long query(int at) {
        long long mul = 0;
        long long add = 0;
        int start = at;
        while (at >= 0) {
            mul += dataMul[at];
            add += dataAdd[at];
            at = (at & (at + 1)) - 1;
        }
        return (mul * start + add);
    }
    ll query(int l,int r)
    {
        return query(r)-query(l-1);
    }
    void clear()
    {
        mem(dataMul,0);
        mem(dataAdd,0);
    }
}t;

int spf[N],n,q,i,j;
vii prime;
int l[M],r[M],x[M],a[M];
ll ans[M];
void seive()
{
    for( i=2; i<N; i++)
    {
        if(spf[i]==0)
            spf[i]=i,prime.emplace_back(i);
        int sz=prime.size();
        for( j=0; j<sz and i*prime[j]<N and prime[j]<=spf[i]; j++)
            spf[i*prime[j]]=prime[j];
    }
}

int main()
{
    fast;
    seive();
    cin >> n >> q;
    for( i=1;i<=n;i++)cin >> a[i];
    string s;
    for( i=1;i<=q;i++){
        cin>>s>>l[i]>>r[i];
        if(s[0]=='M') cin>>x[i];
    }
    for( i=1;i<=q;i++)ans[i]=1;

    for(int p:prime)
    {
        t.clear();

        for( i=1;i<=n;i++)
        {
            int cnt=0;
            int tmp=a[i];
            while(tmp%p==0) tmp/=p,cnt++;
            t.update(i,i,cnt);
        }
        int p2=qpow(p,mod-2);
                p2=(1LL-p2+mod)%mod;
        for( i=1;i<=q;i++)
        {
            if(x[i]>0)
            {
                int cnt=0;
                int tmp=x[i];
                while(tmp%p==0) tmp/=p,cnt++;
                t.update(l[i],r[i],cnt);
            }
            else
            {
                ll po=t.query(l[i],r[i]);
                if(!po) continue;
                po%=(mod-1);
                ans[i]*=qpow(p,po);
                ans[i]%=mod;

                ans[i]*=p2;
                ans[i]%=mod;
            }
        }
    }
    for(int i=1;i<=q;i++)
        if(!x[i])
            cout<<(ans[i]+mod)%mod<<endl;
    return 0;
}
