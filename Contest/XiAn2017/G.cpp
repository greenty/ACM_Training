#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e5+10;
const ll mod=1e9+7;
using namespace std;
ll a[MAXN],num[21][MAXN];
int main(){
	int _;scanf("%d",&_);
	while(_--){
		int n,q;scanf("%d%d",&n,&q);
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<=20;i++){
			ll t0=0,t1=0;
			for(int j=1;j<=n;j++){
				if(a[j]&(1<<i))num[i][j]=num[i][j-1]+t0+1,swap(t0,t1),t1++;
				else num[i][j]=num[i][j-1]+t1,t0++;
			}
		}
		for(int i=0;i<2;i++){
			for(int j=1;j<=n;j++)cout<<num[i][j]<<" ";
			cout<<endl;
		}
		int l,r;
		for(int i=1;i<=q;i++){
			scanf("%d%d",&l,&r);
			ll ans=0;
			for(int j=0;j<=20;j++){
				ans=(ans+(num[j][r]-num[j][l-1])*(1<<j)%mod)%mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
