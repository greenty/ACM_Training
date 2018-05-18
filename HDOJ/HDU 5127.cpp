#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define eps 1e-12
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid (x+y>>1)
#define NM 200005
#define nm 1000005
#define pi 3.1415926535897931
using namespace std;
const ll inf=1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}


int _t,a[NM],b[NM],tot,n;
bool vis[NM];
ll _x,_y,ans;


int main(){
	while(scanf("%d",&n)!=EOF){
		tot=0;
		if(n==0) break;
		while(n--){
			_t=read();_x=read();_y=read();
			if(_t==1){
				a[++tot]=_x;b[tot]=_y;vis[tot]=0;
			}else if(_t==-1){
				inc(i,1,tot)if((a[i]==_x&&b[i]==_y)&&vis[i]==0){
					vis[i]=1;
					break;
				}
			}else if(_t==0){
				ans=-2ll*inf*inf;
				for(int i=1;i<=tot;i++){
                    if(ans>=(_x*a[i]+_y*b[i])||vis[i]==1) continue;
                    ans=_x*a[i]+_y*b[i];
				}
				printf("%lld\n",ans);
			}
		}
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
