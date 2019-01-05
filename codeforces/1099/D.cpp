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

int n;
const int N=(int)1e5+1;
vector<int> gra[N];
ll arr[N],bara[N];


void work2();
void work1()
{
    for(int i=2,p; i<=n; i++)
    {
        cin >> p;
        gra[p].pb(i);
    }

    REP1(i,n)
    cin>>arr[i];
    work2();

}
void funck(int s,int p,int h);
void work2()
{
    bara[1]=arr[1];
    for(int i=0; i<gra[1].size(); i++)
    {
        int z=gra[1][i];
        funck(z,1,2);
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {

        ans+=bara[i];
    }
    cout<<ans<<endl;
}
int main()
{
    cin >> n;
    work1();
    return 0;
}
void funck(int s,int p,int h)
{

    if(h%2==0)
    {
        ll mid=1e10;
        for(int i=0; i<gra[s].size(); i++)
        {
            int z=gra[s][i];
            mid=min(mid,arr[z]);
        }
        if(gra[s].size()==0)
            mid=arr[p];

        if(mid<arr[p])
        {
            cout<<"-1"<<endl;
            exit(0);
        }
        bara[s]=mid-arr[p];
        arr[s]=arr[p]+bara[s];
        for(int i=0; i<gra[s].size(); i++)
        {
            int z=gra[s][i];
            funck(z,s,h+1);
        }
    }
    else
    {
        if(arr[p]>arr[s])
        {
            cout<<"-1"<<endl;
            exit(0);
        }
        bara[s]=arr[s]-arr[p];
        for(int i=0; i<gra[s].size(); i++)
        {
            int z=gra[s][i];
            funck(z,s,h+1);
        }
    }
}
