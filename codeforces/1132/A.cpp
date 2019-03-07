#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==0 and c+d!=0)return puts("0"),0;
    if(a==d)return puts("1"),0;
    puts("0");
    return 0;
}
