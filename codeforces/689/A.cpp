#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0,isZero = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            {
                isZero = 1;
                break;
            }
    }
    if(isZero)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1' || s[i]=='2' || s[i]=='3')
            {
                cout<<"YES\n";
                return 0;
            }

        }
        cout<<"NO\n";
            return 0;
    }
    else
    {
        int f1=0,f2=0,f3=0,f4=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1' || s[i]=='2' || s[i]=='3')
                f1 = 1;
            if(s[i]=='1' || s[i]=='4' || s[i]=='7')
                f2 = 1;
            if(s[i]=='3' || s[i]=='6' ||s[i]=='9')
                f3 = 1;
            if(s[i]=='7' || s[i]=='9')
                f4 = 1;
        }
        if(f1 and f2 and f3 and f4)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
