#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define inf 1e9
#define link(x) for(edge*j=h[x];j;j=j->next)
#define pi 3.14159
#define mid (x+y)>>1
#define eps 1e-12
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define succ(x) (1<<(x))
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
