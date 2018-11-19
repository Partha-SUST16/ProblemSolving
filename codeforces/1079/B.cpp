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


int main()
{
    string s;cin>>s;
    if(s.length()<=20)
    {
        cout<<"1 "<<s.length()<<endl;
        cout<<s<<endl;
    }
    else if(s.length()<=40)
    {
        if(s.length()&1)
        {
            cout<<"2 "<<s.length()/2 +1<<endl;
            for(int i=0;i<s.length()/2;i++)cout<<s[i];
            cout<<"*\n";
            for(int i=s.length()/2;i<s.length();i++)cout<<s[i];
        }
        else
        {
            cout<<"2 "<<s.length()/2<<endl;
            for(int i=0;i<s.length()/2;i++)cout<<s[i];
            cout<<"\n";
            for(int i=s.length()/2;i<s.length();i++)cout<<s[i];
        }
    }
    else if(s.length()<=60)
    {
        if(s.length()%3==0)
        {
            cout<<3<<' '<<s.length()/3<<'\n';
            REP(i,s.length()/3) cout<<s[i];
            cout<<'\n';

            for(int i=s.length()/3; i<s.length()/3*2; i++) cout<<s[i];
            cout<<'\n';
            for(int i=s.length()/3*2; i<s.length(); i++) cout<<s[i];

        }
        else if(s.length()%3==1)
        {
            cout<<3<<' '<<s.length()/3+1<<'\n';
            REP(i,s.length()/3) cout<<s[i];
            cout<<"*\n*";
            for(int i=s.length()/3; i<s.length()/3*2; i++) cout<<s[i];
            cout<<'\n';
            for(int i=s.length()/3*2; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%3==2)
        {
            cout<<3<<' '<<s.length()/3+1<<'\n';
            REP(i,s.length()/3+1) cout<<s[i];
            cout<<'\n';
            for(int i=s.length()/3+1; i<s.length()/3*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(int i=s.length()/3*2+1; i<s.length(); i++) cout<<s[i];
        }
    }
    else if(s.length()<=80)
    {
        if(s.length()%4==0)
        {
            int i;
            cout<<4<<' '<<s.length()/4<<'\n';
            for(i=0; i<s.length()/4; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/4*2; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/4*3; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%4==1)
        {
            int i;
            cout<<4<<' '<<s.length()/4+1<<'\n';
            for(i=0; i<s.length()/4; i++) cout<<s[i];
            cout<<"*\n*";
            for(; i<s.length()/4*2; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length()/4*3; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%4==2)
        {
            int i;
            cout<<4<<' '<<s.length()/4+1<<'\n';
            for(i=0; i<s.length()/4+1; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/4*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/4*3+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%4==3)
        {
            int i;
            cout<<4<<' '<<s.length()/4+1<<'\n';
            for(i=0; i<s.length()/4+1; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/4*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/4*3+2; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
    }
    else if(s.length()<=100)
    {
        if(s.length()%5==0)
        {
            int i;
            cout<<5<<' '<<s.length()/5<<'\n';
            for(i=0; i<s.length()/5; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*2; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*3; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*4; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%5==1)
        {
            int i;
            cout<<5<<' '<<s.length()/5+1<<'\n';
            for(i=0; i<s.length()/5; i++) cout<<s[i];
            cout<<"*\n*";
            for(; i<s.length()/5*2; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length()/5*3; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*4; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%5==2)
        {
            int i;
            cout<<5<<' '<<s.length()/5+1<<'\n';
            for(i=0; i<s.length()/5+1; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*3+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*4+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%5==3)
        {
            int i;
            cout<<5<<' '<<s.length()/5+1<<'\n';
            for(i=0; i<s.length()/5+1; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*3+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*4+2; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
        else if(s.length()%5==4)
        {
            int i;
            cout<<5<<' '<<s.length()/5+1<<'\n';
            for(i=0; i<s.length()/5+1; i++) cout<<s[i];
            cout<<'\n';
            for(; i<s.length()/5*2+1; i++) cout<<s[i];
            cout<<"*\n";
            for(; i<s.length()/5*3+2; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length()/5*4+3; i++) cout<<s[i];
            cout<<"\n";
            for(; i<s.length(); i++) cout<<s[i];
        }
    }
    return 0;
}
