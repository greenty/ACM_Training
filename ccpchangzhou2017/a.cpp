#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL a[100005];
int main()
{
	int _;scanf("%d",&_);
	for(int T=1;T<=_;T++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
		LL sum = 0;
		for(int i = 1;i<=n;i++) sum+=a[i];
		if(sum % m!=0) {
			printf("Case #%d: -1\n",T);
			continue;
		}
		LL c = sum/m;
		LL op = 0;
		LL k = 0;
		for(int i = 1;i<=n;i++)
		{
			//cout<<k<<endl;
			if(k!=0) op++;
			k+=a[i];
			op +=  0 > (((k-1)/c+1)-1) ? 0 : (((k-1)/c+1)-1);
			k%=c;
		//	cout<<k<<endl;
		}
		printf("Case #%d: %lld\n",T,op);
	}

}
