/*input

*/
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
 #define mem(a,s) memset(a,s,sizeof a)
 #define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
 #define pf printf
 #define sc scanf
 #define ll long long
 #define pii pair<int,int>
 #define pll pair<ll,ll>
 #define vii vector<int>
 #define vll vector<ll>
 #define vss vector<string>
 #define vpii vector<pii>
 #define vpll vector<pll>
 #define all(v) v.begin(),v.end()
 #define debug(x)  cout<<#x"="<<(x)<<endl
 #define pb push_back
 #define nd '\n'


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
const int N = 300005;

struct node
{
    int to,d,num;
    node(){}
    node(int a,int b,int c)
    {
        to=a,d=b,num=c;
    }
};
vector<node> g[N<<1];
struct node2
{
    ll id,d,num;
    node2(){}
    node2(ll a,ll b,ll c)
    {
        id=a,d=b,num=c;
    }
    bool friend operator <(node2 n1,node2 n2)
    {
        return n1.d>n2.d;
    }
};
ll n,m,k;
ll dis[N],vis[N],ans[N];
void ini()
{
    mem(vis,0);
    mem(ans,0);
    for(int i=1;i<=n;i++)g[i].clear(),dis[i]=0x3f3f3f3f3f3f3f;
}
void dj()
{
    priority_queue<node2> q;
    dis[1]=0;
    q.push(node2(1,0,0));
    ll cnt=0;
    while(!q.empty())
    {
        node2 now=q.top();
        q.pop();
        ll id=now.id;
        if(vis[id])continue;
        vis[id]=1;
        if(cnt<=k)
        {
            ans[now.num]=1;
            cnt++;
        }
        for(int i=0;i<g[id].size();i++)
        {
            ll to=g[id][i].to,w=g[id][i].d;
            if(!vis[to]&&dis[to]>dis[id]+w)
            {
                dis[to]=dis[id]+w;
                q.push(node2(to,dis[to],g[id][i].num));
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    ini();
    for(ll a,b,c,i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        g[a].pb(node(b,c,i));
        g[b].pb(node(a,c,i));
    }
    k=min(k,n-1);
    dj();
    cout<<k<<endl;
    for(int i=1;i<=m;i++)
    {
        if(ans[i])cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
