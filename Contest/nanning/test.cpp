#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define inf 1e9
#define mem(a) memset(a,0,sizeof(a))
#define succ(x) (1<<(x))
#define eps 1e-8
#define link(x) for(edge*j=h[x];j;j=j->next)
#define lowbit(x) (x&(-x))
#define ll long long
#define sqr(x) ((x)*(x))
#define pi 3.1415926
#define mid (x+y>>1)
#define NM 105
#define nm 100005
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,a[NM][NM],m;

int dfs(int k){
	if(k==2*m+1)return 0;
	int s=k%2?0:inf;
	inc(x,1,3)inc(y,1,3){
		int t=a[x][y]+a[x][y+1]+a[x+1][y]+a[x+1][y+1];
		swap(a[x][y],a[x+1][y]);
		swap(a[x][y],a[x+1][y+1]);
		swap(a[x][y],a[x][y+1]);
		if(k%2)s=max(s,t+dfs(k+1));
		else s=min(s,t+dfs(k+1));
		swap(a[x][y],a[x][y+1]);
		swap(a[x][y],a[x+1][y+1]);
		swap(a[x][y],a[x+1][y]);
	}
	return s;
}


int main(){
	n=4;
	int _=read();while(_--){
		m=read();mem(a);
		inc(i,1,n)inc(j,1,n)a[i][j]=read();
		printf("%d\n",dfs(1));
	}
	return 0;
}
