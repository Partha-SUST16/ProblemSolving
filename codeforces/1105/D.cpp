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

int n,m,p;
int s[12],ans[12];
char S[1200];
int f[1200][1200];
int O[20];
vii X[10],Y[10];
int bfs(int V,int &head,int T)
{
    for(int i=1; i<=T; i++)
    {
        int tail=X[V].size()-1;
        while(head<tail)
        {
            head++;
            int x=X[V][head];
            int y=Y[V][head];
            //		printf("%d %d %d\n",V,x,y);
            if(x+1<=n&&f[x+1][y]==0)
                X[V].push_back(x+1),Y[V].push_back(y),f[x+1][y]=V;
            if(x-1>=1&&f[x-1][y]==0)
                X[V].push_back(x-1),Y[V].push_back(y),f[x-1][y]=V;
            if(y+1<=m&&f[x][y+1]==0)
                X[V].push_back(x),Y[V].push_back(y+1),f[x][y+1]=V;
            if(y-1>=1&&f[x][y-1]==0)
                X[V].push_back(x),Y[V].push_back(y-1),f[x][y-1]=V;
        }
        if(head+1==X[V].size())
            return 1;
    }
    return 0;
}
int main()
{
    sc("%d%d%d",&n,&m,&p);
    for(int i=1; i<=p; i++)
        sc("%d",&s[i]);
    for(int i=1; i<=n; i++)
    {
        sc("%s",S+1);
        for(int j=1; j<=m; j++)
        {
            if(S[j]=='#')
                f[i][j]=-1;
            if(S[j]>='1'&&S[j]<='9')
            {
                f[i][j]=-1;
                X[S[j]-'0'].push_back(i);
                Y[S[j]-'0'].push_back(j);
            }
        }
    }
    for(int i=1; i<=p; i++)
        O[i]=-1;
    for(int i=1; i<=100000000; i++)
    {
        int o=0;
        for(int i=1; i<=p; i++)
            o+=bfs(i,O[i],s[i]);
        if(o==p)
            break;
    }
    for(int i=1; i<=p; i++)
        pf("%d ",X[i].size());
        return 0;
}
