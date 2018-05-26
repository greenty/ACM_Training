#include <bits/stdc++.h>
const int MAXN=1e4+10;
using namespace std;
int vis[MAXN<<2][29],vul;
int a[MAXN],aim[29],ans[29],n,q,k;
void up(int x){
	for(int i=28;i>=0;i--)vis[x][i]=vis[x<<1][i];
	for(int i=28;i>=0;i--){
		if(!vis[x<<1|1][i])continue;
		vul=vis[x<<1|1][i];
		for(int j=28;j>=0;j--){
			if(vul&(1<<j)){
				if(vis[x][j])vul^=vis[x][j];
				else{
					vis[x][j]=vul;break;
				}
			}
		}
	}
}
void newnode(int x,int vul){
	for(int i=28;i>=0;i--){
		if(vul&(1<<i)){
			if(vis[x][i])vul^=vis[x][i];
			else{
				vis[x][i]=vul;break;
			}
		}
	}
}
void built(int rt,int l,int r){
	if(l==r){
		newnode(rt,a[l]);return ;
	}
	int mid=(l+r)>>1;
	built(rt<<1,l,mid);
	built(rt<<1|1,mid+1,r);
	up(rt);
}
bool flag;
void merge(int x){
	for(int i=28;i>=0;i--){
		if(!vis[x][i])continue;
		vul=vis[x][i];
		for(int j=28;j>=0;j--){
			if(vul&(1<<j)){
				if(aim[j])vul^=aim[j];
				else{
					aim[j]=vul;break;
				}
			}
		}
	}
}
void querty(int rt,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		if(!flag){for(int i=28;i>=0;i--)aim[i]=vis[rt][i];flag=1;}
		else merge(rt);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)querty(rt<<1,l,mid,ql,qr);
	if(qr>mid) querty(rt<<1|1,mid+1,r,ql,qr);
}
void slove(int l,int r){
	flag=0;
	querty(1,1,n,l,r);
//	cout<<l<<" "<<r<<endl;
//	for(int i=4;i>=0;i--)cout<<aim[i]<<" ";
//	cout<<endl;
	int vul=0;
	for(int i=28;i>=0;i--){
		if(ans[i]){
			if(!aim[i]||(vul&(1<<i)))continue;
			vul^=aim[i];
		}
		else vul^=aim[i];
	}
	int ans1=0;
	for(int i=28;i>=0;i--){
		if((vul&(1<<i))||(k&(1<<i)))ans1+=(1<<i);
	}
	printf("%d\n",ans1);
	return ;
}
int main(){
	int _;scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&q,&k);
		for(int i=28;i>=0;i--){
			if(!(k&(1<<i)))ans[i]=1;
		}
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int l,r;built(1,1,n);
		for(int i=1;i<=q;i++){
			scanf("%d%d",&l,&r);
			slove(l,r);
			//printf("%d\n",slove(l,r));
		}
	}
	return 0;
}
