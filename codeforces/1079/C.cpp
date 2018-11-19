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
const int N = 100005;

int notes[N],asc[N],dsc[N],same[N];
bool flag;
int main()
{
    int n;
    cin>>n;
    REP(i,n)cin>>notes[i];
    asc[n-1]=dsc[n-1]=0;

    for(int i=n-2;i>=0;i--)
    {
        if(notes[i+1]>notes[i])
            asc[i] = asc[i+1]+1;
        else
            asc[i] = 0;
        if(notes[i+1]<notes[i])
            dsc[i]=dsc[i+1]+1;
        else
            dsc[i]=0;
        if(notes[i]==notes[i+1])
            same[i]=same[i+1]+1;
        else same[i]=0;
        if(asc[i]>=5 or dsc[i]>=5)flag = 1;
    }
    if(flag)
    {
        return cout<<"-1\n",0;
    }
    int fig = -1;
    if(asc[0])fig = 1;
    else if(dsc[0])fig=5;
    else fig=3;
    cout<<fig;

    int i = 0;
    while(i<n-1)
    {
        if(same[i]!=0)
        {
            int nxt = i+same[i];
            int target;
            if(asc[nxt])target=1;
            else if(dsc[nxt])target = 5;
            else target = 5;

            int nct =same[i]-1;
            while(nct>0)
            {
                if(fig==2)fig=3;
                else fig = 2;
                cout<<" "<<fig;
                nct--;
                i++;
            }
            if(fig==target)
            {
                if(asc[nxt])target=2;
                else target = 4;
            }
            fig = target;
            cout<<" "<<fig;
            i++;
        }
        else if(asc[i]!=0)
        {
            int target = 5;
            int nxt=i+asc[i];
            if(same[nxt])
                target = 4;
            int cnt = asc[i]-1;
            while(cnt>0)
            {
                cout<<" "<<++fig;
                cnt--;
                i++;
            }
            if(fig==target)target++;
            fig = target;
            cout<<" "<<fig;
            i++;
        }
        else if(dsc[i]!=0)
        {
            int target = 1;
            int nxt = i+dsc[i];
            if(same[nxt])target = 2;
            int cnt = dsc[i]-1;
            while(cnt>0)
            {
                cout<<" "<<--fig;
                cnt--;
                i++;
            }
            if(fig==target)target--;
            fig=target;
            cout<<" "<<fig;
            i++;
        }
        else break;
    }
    cout<<endl;
    return 0;
}
