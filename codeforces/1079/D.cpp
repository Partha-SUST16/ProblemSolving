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

int a,b,c;
double a1,a2,a3,a4,normal;
pair<double,double>A,B,p1,p2,p3,p4;

double gety(double x)
{
    return (-a*x-c)/b;
}
double getx(double y)
{
    return (-b*y-c)/a;
}
bool val(double aa,double bb,double cc)
{
    if((aa>=bb and aa<=cc) or (aa>=cc and aa<=bb))
        return 1;
    return 0;
}
#define sq(X) ((X)*(X))
double dist(pair<double,double> P,pair<double,double> Q)
{
    double d = sq(P.first-Q.first)+sq(P.second-Q.second);
    return sqrt(d);
}
int main()
{
    cin>>a>>b>>c>>A.first>>A.second>>B.first>>B.second;

    normal = abs(A.first-B.first)+abs(A.second-B.second);
    if(a==0 or b==0)
    {
        cout<<fixed<<setprecision(10)<<normal<<endl;
        return 0;
    }
    a1 = getx(A.second);p1={a1,A.second};
    a2 = gety(B.first);p2={B.first,a2};
    a3 = getx(B.second);p3={a3,B.second};
    a4 = gety(A.first);p4={A.first,a4};
     ///1 and 2
    if(val(a1,A.first,B.first) and val(a2,A.second,B.second))
    {
        double temp = 0;
        temp+=dist(A,p1);
        temp+=dist(p1,p2);
        temp+=dist(p2,B);
        temp = min(temp,normal);
        cout<<fixed<<setprecision(10)<<temp<<endl;
        return 0;
    }
    ///1and 3

    if(val(a1,A.first,B.first) and val(a3,A.first,B.first))
    {
         double temp = 0;
        temp+=dist(A,p1);
        temp+=dist(p1,p3);
        temp+=dist(p3,B);
        temp = min(temp,normal);
        cout<<fixed<<setprecision(10)<<temp<<endl;
        return 0;
    }
    ///2 and 4
    if(val(a2,A.second,B.second) and val(a4,A.second,B.second))
    {
         double temp = 0;
        temp+=dist(A,p4);
        temp+=dist(p4,p2);
        temp+=dist(p2,B);
        temp = min(temp,normal);
        cout<<fixed<<setprecision(10)<<temp<<endl;
        return 0;
    }
    ///3and 4
    if(val(a3,A.first,B.first) and val(a4,A.second,B.second))
    {
         double temp = 0;
        temp+=dist(A,p4);
        temp+=dist(p4,p3);
        temp+=dist(p3,B);
        temp = min(temp,normal);
        cout<<fixed<<setprecision(10)<<temp<<endl;
        return 0;
    }
            cout<<fixed<<setprecision(10)<<normal<<endl;

    return 0;
}
