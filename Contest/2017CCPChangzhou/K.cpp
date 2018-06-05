#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e5+10;
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[MAXN],b[MAXN],n,m;ll vul;
bool check(ll t){
	ll ans=0;
	for(int i=1;i<=n;i++){
		//ans+=(t-b[i])/a[i];
		if(t-b[i]<0)ans+=(t-b[i])/a[i]-1;
		else ans+=(t-b[i])/a[i];
	}
	if(ans>=vul)return 1;
	return 0;
}
ll slove(){
	ll l=1;ll r=2e9,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	int _=read();
	while(_--){
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		int op,x,y;
		for(int i=1;i<=m;i++){
			op=read();
			if(op==1){
				x=read();y=read();a[x]=y;}
			else if(op==2){
				x=read();y=read();b[x]=y;
			}
			else{
				vul=read();
				printf("%lld\n",slove());
			}
		}
	}
	return 0;
}
