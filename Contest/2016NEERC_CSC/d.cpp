#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll ksm(ll a,ll b,ll c){
	ll ans=1;ll t=a;
	while(b){
		if(b&1)ans=ans*t%mod;
		b=b>>1;t=t*t%mod;
	}
	return ans;
}
string str;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>str;int len=str.size();
	int cnt=0;
	for(int i=1;i<len;i++){
		if(str[i]=='N') continue;
		else if(str[i]=='E'){
			if(str[i-1]=='N'||str[i-1]=='S')cnt++;
		}
		else if(str[i]=='W'){
			if(str[i-1]=='N'||str[i-1]=='S')cnt++;
		}
}
	printf("%lld\n",ksm(2,cnt,mod));
	return 0;
}
