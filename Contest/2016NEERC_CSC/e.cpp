#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll n,k,tot = 0LL,sum = 0LL,res,circle,add,lres;
int a[100005];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n>>k;
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	ll _max,maxx = 0;
	for(int i = 1;i<=n;i++) if(maxx < a[i]) maxx = a[i],_max = i;
	if(k == 0 )
	{
		if(_max == 1) cout<<"YES"<<endl;
		else cout<<"KEK"<<endl;
		return 0;
	}
	for(int i = 1;i<=n;i++) tot+=a[i];
	for(int i = 1;i<_max;i++) lres += (a[i]-1);
	sum = n-1+a[_max];
	res = tot - sum;
	circle = k/sum;
	add = k%sum;
	if(add < _max-1)
	{
		circle--;
		add+=((n-1)+a[_max]-(_max-1));
	}
	else
	{
		add -= (_max-1);
	}
	ll rres  = res * circle + lres;
	//cout<<rres<<" "<<add<<endl;
	if(rres >= add) cout<<"YES"<<endl;
	else cout<<"KEK"<<endl;
	
}
