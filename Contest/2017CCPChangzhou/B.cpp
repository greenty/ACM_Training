#include <bits/stdc++.h>
#define ll long long
const ll mod=998244353;
const int MAXN=1e5+10;
using namespace std;
ll mu[MAXN],p[MAXN],q[MAXN];
ll ksm(ll a,ll b){
	ll ans=1;ll t=a;
	while(b){
		if(b&1)ans=ans*t%mod;
		b=b>>1;t=t*t%mod;
	}
	return ans;
}
int main(){
	int _;scanf("%d",&_);
	while(_--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld",&p[i],&q[i]),mu[i]=ksm(p[i],mod-2);
		ll t=1;
		for(int i=1;i<=n;i++)t=t*mu[i]%mod;
		ll t1=1;
		for(int i=1;i<=n;i++){
			ll t2=q[i]*(p[i]-1)%mod;
			t2=(t2+p[i])%mod;
			t1=t2*t1%mod;
		}
		t1=t1*t%mod;
		ll ans=1;
		for(int i=1;i<=n;i++){
			ll t2=ksm(p[i],q[i]);
			ans=ans*t2%mod;
		}
		ans=ans*t1%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
