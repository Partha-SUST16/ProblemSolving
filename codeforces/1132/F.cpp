#include<bits/stdc++.h>
using namespace std;
int n;
int dp[555][555];
string s;
int rec(int l,int r)
{
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r] = n;
    for(int i=l;i<=r;i++)
    {
        if(s[i]==s[r+1] or s[i]==s[l-1])
            dp[l][r] = min(dp[l][r],rec(l,i-1)+rec(i+1,r));
        else
            dp[l][r] = min(dp[l][r],rec(l,i-1)+rec(i+1,r)+1);
    }
    return dp[l][r];
}
int main()
{
    cin >> n >> s;
    memset(dp,-1,sizeof dp);
    s="$"+s;
    cout<<rec(1,n)<<endl;
    return 0;
}
