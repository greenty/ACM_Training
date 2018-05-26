#include <bits/stdc++.h>
const int MAXN=1e5+10;
#define ll long long
const ll inf=1e12;
using namespace std;
typedef struct node{
	ll flag;ll minn;
}node;
node d[MAXN<<2];ll a[MAXN];
void push(int rt){
	if(d[rt].flag){
		d[rt<<1].flag+=d[rt].flag;
		d[rt<<1|1].flag+=d[rt].flag;
		d[rt<<1].minn-=d[rt].flag;
		d[rt<<1|1].minn-=d[rt].flag;
		d[rt].flag=0;
	}
}
void up(int x){d[x].minn=min(d[x<<1].minn,d[x<<1|1].minn);}
void built(int rt,int l,int r){
	if(l==r){d[rt].minn=a[l];d[rt].flag=0;return ;}
	int mid=(l+r)>>1;
	built(rt<<1,l,mid);
	built(rt<<1|1,mid+1,r);
	d[rt].flag=0;up(rt);
}
void update(int rt,int l,int r,int ql,int qr,ll t){
	if(ql<=l&&r<=qr){d[rt].flag+=t;d[rt].minn-=t;return ;}
	int mid=(l+r)>>1;
	push(rt);
	if(ql<=mid)update(rt<<1,l,mid,ql,qr,t);
	if(qr>mid) update(rt<<1|1,mid+1,r,ql,qr,t);
	up(rt);
}
ll ans;
void querty(int rt,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){ans=min(ans,d[rt].minn);return ;}
	int mid=(l+r)>>1;
	push(rt);
	if(ql<=mid)querty(rt<<1,l,mid,ql,qr);
	if(qr>mid)querty(rt<<1|1,mid+1,r,ql,qr);
	up(rt);
}
int main(){
	int _;scanf("%d",&_);
	while(_--){
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		built(1,1,n);ll sum=0;
		for(int i=m;i<=n;i++){
			ans=inf;querty(1,1,n,i-m+1,i);
			sum+=ans;
			update(1,1,n,i-m+1,i,ans);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
