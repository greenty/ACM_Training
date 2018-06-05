#include <bits/stdc++.h>
const int MAXN=2e5+10;
using namespace std;
typedef struct node{
	int l,r,sum;
}node;
node d[MAXN*45];
int a[MAXN],vis[MAXN],rt[MAXN];
int cnt;
void update(int &x,int y,int l,int r,int t,int vul){
	x=++cnt;d[x]=d[y];d[x].sum+=vul;
	if(l==r)return ;
	int mid=(l+r)>>1;
	if(t<=mid)update(d[x].l,d[y].l,l,mid,t,vul);
	else update(d[x].r,d[y].r,mid+1,r,t,vul);
}
int ans=0;
void querty(int x,int l,int r,int ql,int qr){
//	cout<<l<<" "<<r<<" "<<d[x].sum<<endl;
	if(ql<=l&&r<=qr){ans+=d[x].sum;return ;}
	int mid=(l+r)>>1;
	if(ql<=mid)querty(d[x].l,l,mid,ql,qr);
	if(qr>mid)querty(d[x].r,mid+1,r,ql,qr);
}
int main(){
	int _;scanf("%d",&_);
	for(int i=1;i<=_;i++){
		int n,m;scanf("%d%d",&n,&m);
		cnt=0;memset(d,0,sizeof(d));memset(vis,0,sizeof(vis));
		memset(rt,0,sizeof(rt));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		rt[n+1]=0;
		for(int i=n;i>=1;i--){
			//cout<<vis[a[i]]<<endl;
			if(!vis[a[i]])update(rt[i],rt[i+1],1,n,i,1);
			else{
				update(rt[i],rt[i+1],1,n,vis[a[i]],-1);
				update(rt[i],rt[i],1,n,i,1);
			}
			vis[a[i]]=i;
		}
		int l,r,num,res=0,lx,rx;
		printf("Case #%d:",i);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&l,&r);
			lx=min((l+res)%n+1,(r+res)%n+1);
			rx=max((l+res)%n+1,(r+res)%n+1);
			l=lx;r=rx;
			if(l>r)swap(l,r);
		//	cout<<l<<" "<<r<<endl;
		//	cout<<d[rt[r]].sum<<endl;
			ans=0;querty(rt[l],1,n,l,r);
			//cout<<ans<<endl;
			num=ans;
		//	cout<<num<<"----"<<endl;
			//cout<<l<<" "<<r<<" "<<ans<<endl;
			if(num==1){
				res=l;
				printf(" %d",l);continue;
			}
			lx=l,rx=r;int ans1;
			//num1=num;
		//	cout<<num<<endl;
			num=(num+1)/2;
		//	cout<<num<<endl;
			while(lx<=rx){
				int mid=(lx+rx)>>1;
				ans=0;querty(rt[l],1,n,l,mid);
				if(ans>=num)ans1=mid,rx=mid-1;
				else lx=mid+1;
			}
			res=ans1;
			printf(" %d",res);
		}
		printf("\n");
	}
	return 0;
}
