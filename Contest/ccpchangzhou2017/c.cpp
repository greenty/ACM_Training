#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long  a[100005];
int main()
{
	int T;
	scanf("%d",&T);
	for(int _ = 1;_<=T;_++)
	{
		int n;scanf("%d",&n);
		for(int i = 1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		a[0] = 0;
		long long sum = 1;
		long long t2 = 1LL,t1;
		for(int i = n-1;i>=1;i--)
		{
			long long d = a[i] - a[i-1];
			long long d2 = a[i+1] - a[i];
			if((d*t2)%d2 == 0) t1 = d*t2/d2;
			else
			t1 = d*t2/d2+1;
			sum+=t1;
			t2 = t1;
		}
		printf("Case #%d: %lld\n",_,sum);
	}
}
