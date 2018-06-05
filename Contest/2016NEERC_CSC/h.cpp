#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i++)
#define link(x) for(edge*j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define succ(x) (1<<(x))
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define eps 1e-8
#define pi 3.1415926
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}


int n,ans;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();
	ans=8;
	inc(i,2,min(n,9))ans*=9;
	printf("%d",ans);
	inc(i,10,n)printf("0");
	putchar('\n');
	return 0;
}
