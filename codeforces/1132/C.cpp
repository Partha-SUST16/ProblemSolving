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
    for(int i=l; i<=r; i++)
    {
        if(s[i]==s[r+1] or s[i]==s[l-1])
            dp[l][r] = min(dp[l][r],rec(l,i-1)+rec(i+1,r));
        else
            dp[l][r] = min(dp[l][r],rec(l,i-1)+rec(i+1,r)+1);
    }
    return dp[l][r];
}
const int M = 5001;
int a[M];
int a1[M];
int a2[M];
vector<pair<int, int>> v;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0,L,R; i < q; ++i)
    {
        cin >> L >> R;
        for (int j = L - 1; j < R; ++j)
        {
            a[j]++;
        }
        v.push_back({L - 1, R - 1});
    }
    int sm = 0;
    if(a[0] > 0) sm++;
    if(a[0] == 1) a1[0]++;
    if(a[0] == 2) a2[0]++;
    for (int i = 1; i < n; ++i)
    {
        a1[i] = a1[i - 1];
        a2[i] = a2[i - 1];
        if(a[i] == 1) a1[i]++;
        if(a[i] == 2) a2[i]++;
        if(a[i] > 0) sm++;
    }
    int best = sm;
    for(int i = 0; i < q; i++)
    {
        for(int j = i + 1; j < q; j++)
        {
            int res = 0;
            if (v[i].first == 0) res = a1[v[i].second];
            else res = a1[v[i].second] - a1[v[i].first - 1];
            if (v[j].first == 0) res += a1[v[j].second];
            else res += a1[v[j].second] - a1[v[j].first - 1];
            int L = max(v[i].first, v[j].first), R = min(v[i].second, v[j].second);
            if (L <= R)
            {
                if (L == 0) res += a2[R];
                else res += a2[R] - a2[L - 1];
            }
            best = min(best, res);
        }
    }
    cout << sm - best << endl;
    return 0;
}
