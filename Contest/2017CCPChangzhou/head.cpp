#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge*j=h[x];j;j=j->next)
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define inf 1e9
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define succ(x) (1<<(x))
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
