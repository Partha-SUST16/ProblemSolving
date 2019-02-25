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

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
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
struct node
{
    ll x,y;
};
vss vv;
int n;
int arr[60][60],vis[60][60];

void bfs(node point,int a)
{
    node temp;
    queue<node>Q;
    Q.push(point);
    vis[point.x][point.y]=a;
    while(!Q.empty())
    {
        point=Q.front();
        //cout << point.x << " " << point.y << endl;
        Q.pop();
        for(int i=0; i<4; i++)
        {
            temp.x=point.x+dx[i];
            temp.y=point.y+dy[i];
            if(1<=temp.x and temp.x<=n and 1<=temp.y and temp.y<=n)
            {
                if(!vis[temp.x][temp.y] and arr[temp.x][temp.y]==0)
                {
                    Q.push(temp);
                    vis[temp.x][temp.y]=a;
                }
            }
        }
    }
}
int main()
{

    cin >> n;
    node st,en;
    cin >> st.x >> st.y >> en.x >> en.y;
    string s;
    for(int i=0; i<n; i++)
        cin >> s,vv.pb(s);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i+1][j+1]=vv[i][j]-'0';

        }

    }
    bfs(st,1);
    if(vis[st.x][st.y]==vis[en.x][en.y])
        return cout<<0<<endl,0;

    bfs(en,2);
    vector<node>v1,v2;
    node temp;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(vis[i][j]==1)
            {

                v1.pb({i,j});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(vis[i][j]==2)
            {

                v2.pb({i,j});
            }
        }
    }
    ll cost = mod,c;
    for(int i=0; i<v1.size(); i++)
    {
        for(int j=0; j<v2.size(); j++)
        {
            c = (v1[i].x-v2[j].x)*(v1[i].x-v2[j].x)+(v1[i].y-v2[j].y)*(v1[i].y-v2[j].y);
            cost = min (cost,c);
        }
    }
    cout<<cost<<endl;
    return 0;
}
