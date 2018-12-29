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
const int N = (int)1e6;

struct node{
    ll x,y,val;
    bool operator < (const node&p)const{
        return val<p.val;
    }
}edge[N];

ll par[N],arr[N],ans;
int n,m,cnt;

ll ffind(ll x)
{
    return x==par[x]?x:par[x]=ffind(par[x]);
}

void KRUSH()
{
    for(int i=1;i<=n;i++)par[i]=i;
    sort(edge+1,edge+1+cnt);
    int c = 0;

    for(int i=1;i<=cnt;i++)
    {
        int x = ffind(edge[i].x);
        int y = ffind(edge[i].y);
        if(x!=y)
        {
            par[x] = y;
            c++;
            ans+=edge[i].val;
             if(c==n-1)
                break;
        }

    }
}
int main()
{
    cin >> n >> m;
    ll mm = 1,x,y,z;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        if(arr[i]<arr[mm])mm=i;
    }

    for(int i=1;i<=m;i++)
    {
       cin >> x >> y >> z;
       edge[++cnt]={x,y,z};
    }
    x = n;
    for(int i=1;i<=n;i++)
    {
        if(mm!=i)
        edge[++cnt]={mm,i,arr[i]+arr[mm]};
    }

    KRUSH();
    cout<<ans<<endl;

    return 0;
}
