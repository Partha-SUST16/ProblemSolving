#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+9;

struct node
{
    int mx;
    ll sum;
} t[4*N];
int arr[N];

void build(int pos,int b,int e)
{
    if(b==e)
    {
        t[pos].mx=arr[b];
        t[pos].sum=arr[b];
        return;
    }
    int mid=(b+e)>>1,l=2*pos,r=l+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[pos].mx=max(t[l].mx,t[r].mx);
    t[pos].sum=t[l].sum+t[r].sum;
}

void update(int pos,int b,int e,int i,int val)
{
    if(b>i||e<i) return ;
    if(b>=i&&e<=i)
    {
        t[pos].mx=val;
        t[pos].sum=val;
        return;
    }
    int mid=(b+e)>>1,l=2*pos,r=l+1;
    update(l,b,mid,i,val);
    update(r,mid+1,e,i,val);
    t[pos].mx=max(t[l].mx,t[r].mx);
    t[pos].sum=t[l].sum+t[r].sum;
}
void domod(int pos,int b,int e,int i,int j,int x)
{
    if(b>j||e<i) return;
    if(b>=i&&e<=j&&b==e)
    {
        t[pos].mx=t[pos].mx%x;
        t[pos].sum=t[pos].sum%x;
        return;
    }
    int mid=(b+e)>>1,l=2*pos,r=l+1;
    if(t[l].mx>=x) domod(l,b,mid,i,j,x);
    if(t[r].mx>=x) domod(r,mid+1,e,i,j,x);
    t[pos].mx=max(t[l].mx,t[r].mx);
    t[pos].sum=t[l].sum+t[r].sum;
}
ll query(int pos,int b,int e,int i,int j)
{
    if(b>j||e<i) return 0;
    if(b>=i&&e<=j) return t[pos].sum;
    int mid=(b+e)>>1,l=2*pos,r=l+1;
    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
}

int main()
{
    ll n,m;
    cin>>n >> m;
    for(int i=1; i<=n; i++)cin>>arr[i];
    build(1,1,n);
    for(int i=0,type,l,r,x; i<m; i++)
    {
        cin>>type>>l>>r;
        if(type==1)
            cout<<query(1,1,n,l,r)<<endl;
        else if(type==2)
        {
            cin>>x;
            domod(1,1,n,l,r,x);
        }
        else
            update(1,1,n,l,r);
    }
}

