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
const int M = 1e5+9;
vii v[28];
string s;
//void work1()
//{
//    fast;
//    int n,q;
//    cin >> n >> q >> s;
//    REP(i,s.length())v[s[i]-'a'].pb(i);
//    int l,r,k;
//    while(q--)
//    {
//        cin >> l >> r >> k;
//        --l,--r;
//        int beg = l;
//        if(k==1)
//        {
//            for(int i=0;i<27;i++)
//            {
//                auto low = lower_bound(all(v[i]),l)-v[i].begin();
//                auto up = upper_bound(all(v[i]),r)-v[i].begin();
//                for(int j=low;j<up;j++)v[i][j]=beg++;
//            }
//        }
//        else
//        {
//            for(int i=26;i>=0;i--)
//            {
//                auto low = lower_bound(all(v[i]),l)-v[i].begin();
//                auto up = upper_bound(all(v[i]),r)-v[i].begin();
//                for(int j=low;j<up;j++)v[i][j]=beg++;
//            }
//        }
//    }
//    for(int i=0;i<27;i++)
//        for(int x : v[i])s[x]=char('a'+i);
//    cout<<s<<endl;
//}

int tree[M*4][28];
int lazy[M*4];
int arr[M*4],cnt[30];


void build(int pos,int b,int e)
{
    arr[pos]=e-b+1;
    if(b==e)
    {
        tree[pos][s[b]-'a'] = 1;
        return;
    }
    int mid = (b+e)>>1;
    int l = 2*pos,r=l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    for(int i=0;i<26;i++)
        tree[pos][i] = tree[l][i]+tree[r][i];
}
void shift(int pos)
{
    if(lazy[pos]!=-1)
    {
        int l = 2*pos,r=l+1;
        lazy[l] =lazy[pos],lazy[r]=lazy[pos];
        for(int i=0;i<26;i++)
            if(i==lazy[pos])tree[l][i]=arr[l],tree[r][i]=arr[r];
            else tree[l][i] = tree[r][i] = 0;
    }
    lazy[pos] = -1;
}
void update(int pos,int b,int e,int i,int j,int ch)
{
    if(b>j or e<i)return;
    if(b>=i and e<=j)
    {
        lazy[pos] = ch;
        for(int k=0;k<26;k++)
            if(k==ch)tree[pos][k] = (e-b+1);
            else tree[pos][k] = 0;
        return;
    }
    shift(pos);
    int mid = (b+e)>>1;
    int l = 2*pos,r=l+1;
    update(l,b,mid,i,j,ch);
    update(r,mid+1,e,i,j,ch);
     for(int i=0;i<26;i++)
        tree[pos][i] = tree[l][i]+tree[r][i];
}
int query(int pos,int b,int e,int i,int j,int ch)
{
    if(b>j or e<i) return 0;
    if(b>=i and e<=j) return tree[pos][ch];
    shift(pos);
    int mid=(b+e)>>1,l=2*pos,r=l+1;
    return query(l,b,mid,i,j,ch)+query(r,mid+1,e,i,j,ch);
}
void print(int pos,int b,int e)
{
    if(b==e)
    {
        for(int i=0;i<26;i++) if(tree[pos][i]==1) cout<<char('a'+i);
        return;
    }
    shift(pos);
    int mid=b+(e-b)/2,l=2*pos,r=l+1;
    print(l,b,mid);
    print(r,mid+1,e);
}
int main()
{
    mem(lazy,-1);
    int l,r,type,n,q;
    cin >> n >> q >> s;
    build(1,0,n-1);
    while(q--)
    {
        cin >> l >> r >> type;
        l--;r--;
        for(int i=0;i<26;i++)cnt[i]=query(1,0,n-1,l,r,i);
        if(type==1)
        {
            int cur = l;
            for(int i=0;i<26;i++)
            {
                update(1,0,n-1,cur,cur+cnt[i]-1,i);
                cur+=cnt[i];
            }
        }
        else{
           int cur=r;
            for(int i=0;i<26;i++){
                update(1,0,n-1,cur-cnt[i]+1,cur,i);
                cur-=cnt[i];
            }
        }
    }
    print(1,0,n-1);
    return 0;
}
