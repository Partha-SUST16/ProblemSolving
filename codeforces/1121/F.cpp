#include<bits/stdc++.h>
using namespace std;

char s[50005];
int dp[5005],lcs[5005][5005];
int main()
{
    int n,a,b;
    cin >> n >> a >> b >> s+1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = dp[i-1]+a;
        for(int j=1;j<i;j++)
        {
            if(s[i]==s[j])
                lcs[i][j] =lcs[i-1][j-1]+1;
            if(lcs[i][j]!=0 and i-j>=lcs[i][j])
                dp[i] = min(dp[i],dp[i-lcs[i][j]]+b);
        }
    }
    cout<<dp[n]<<endl;

    return 0;
}
