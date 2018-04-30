#include <bits/stdc++.h>
using namespace std;
#define inc(i,l,r) for(int i = l;i<=r;i++)
#define dec(i,l,r) for(int i = l;i>=r;i--)
const int N = 1e6+5;
int dp[N];
bool not_prime[N];
int prime[N];
int sss()
{
	int index = 0;
	memset(not_prime,0,sizeof(not_prime));
	for(int i = 2;i<=(int)1e6;i++)
	{
		if( !not_prime[i] ) prime[++index] = i; 
		for(int j = 1;j <= index && prime[j]*i <= (int)1e6 ;j++ )
		{
			not_prime[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	return index;
}
void ycl()
{
	int n = sss();
	dp[2] = 1;
	for(int i = 3;i <= (int)1e6;i++)
	{
		if(not_prime[i])
		{
			int c = 1;
			while(i%prime[c])c++;
			c = prime[c];
			int p = i/c;
			if(c == 2) dp[i] = dp[p] +1;
			else dp[i] = dp[2*p]+(c-2);
		}
		else dp[i] = i-1;
	}
}
int main()
{
	ycl();
	int _,x;scanf("%d",&_);
	while(_--)
	{
		scanf("%d",&x);
		printf("%d\n",dp[x]);
	}
}