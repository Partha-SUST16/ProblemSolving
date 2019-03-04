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

int n,a[200111],b[200111],c2[200111];
class BIT
{
	private:
		int a[200111];
	public:
		void add(int i,int x)
		{
			while(i<=n)
			{
				a[i]+=x;
				i+=i&(-i);
			}
		}
		int cal(int i)
		{
			int ans=0;
			while(i>0)
			{
				ans+=a[i];
				i-=i&(-i);
			}
			return ans;
		}
}bit1,bit2,bit3;
int binsearch(int x)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(mid-bit3.cal(mid+1)<x)l=mid+1;else r=mid-1;
	}
	return l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		c2[i]+=a[i]-bit1.cal(a[i]+1);
		//debug(c2[i]);
		bit1.add(a[i]+1,1);
	}
	for(int i=1;i<=n;i++)
	{
		c2[i]+=b[i]-bit2.cal(b[i]+1);
		bit2.add(b[i]+1,1);
	}
	for(int i=n;i>=1;i--)
	{
		if(c2[i]>=(n-i+1))
		{
			c2[i-1]++;
			c2[i]-=(n-i+1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=binsearch(c2[i]);
		cout<<tmp<<" ";
		bit3.add(tmp+1,1);
	}
	return 0;
}
