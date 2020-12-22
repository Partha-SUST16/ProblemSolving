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

int main()
{
    int n; cin >> n;
    vii arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int l = 0,r = n-1;
    string ans = "";
    vii v;

    while(l<=r)
    {
        bool lef = (v.empty() or arr[l]>v.back());
        bool rig = (v.empty() or arr[r]>v.back());
        if(!lef and !rig)
            break;
        if(lef and !rig)
        {
            ans+="L";
            v.pb(arr[l++]);
        }
        else if(rig and !lef)
        {
            ans+="R";
            v.pb(arr[r--]);
        }
        else
        {
            if(arr[l]<arr[r])
            {
                ans+="L";
                v.pb(arr[l++]);
            }
            else if(arr[r]<arr[l])
            {
                ans+="R";
                v.pb(arr[r--]);
            }
            else
            {
                string one,two;
                int tl = l,lst = (v.size()?v.back():-2e9);
                while(tl<=r and arr[tl]>lst)
                    one+="L",lst=arr[tl++];
                int tr = r;
                lst = (v.size()?v.back():-2e9);
                while(tr>=l and arr[tr]>lst)
                    two+="R",lst = arr[tr--];
                if(one.size()>two.size())
                    ans+=one;
                else ans+=two;
                l = r+1;
            }
        }
    }
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}
