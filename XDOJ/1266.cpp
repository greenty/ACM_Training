#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,r,x;
LL mod[50];
const int MOD = 1e9+7;
LL c[1005][1005];
LL sum[55];
LL ans = 0LL;
inline LL read(){LL x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void ycl()
{
	c[1][0] = c[1][1] = 1;
	for(int i = 2;i<=1000;i++)
	{
		c[i][0] = 1;
		for(int j = 1;j <= i;j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
			c[i][j] = (c[i][j] % MOD + MOD) % MOD;
		}
	}
}
void csh()
{
	memset(mod,0,sizeof(mod));
	memset(sum,0,sizeof(sum));
	ans = 0;

}
inline LL get_mod(LL x)
{
	return (x%MOD+MOD)%MOD;
}
void dfs(int x,int y,long long res,long long tot)
{
	// cout<<"enter: "<<endl;
	// cout<<x<<" "<<y<<" "<<res<<" "<<tot<<endl;
	if(x == y)
	{
		if(res*2 > mod[x]+mod[0]) return ;
		LL need0 = 0;if(m%2) need0 = 1;
		LL rres = res;
		while(need0<=mod[0] && rres>=0)
		{
			LL nextot = tot*(c[mod[x]][rres*2]*c[mod[0]][need0]);
			nextot = get_mod(nextot);
			// cout<<need0<<" "<<rres<<" "<<nextot<<endl;
			ans+= nextot;
			ans = get_mod(ans);
			need0++;
			rres--;
		}
		// system("pause");
		return;
	}
	if(x + 1 == y)
	{
		if(res*2 > min(mod[x],mod[y])*2+mod[0]) return;
		LL need0 = 0;if(m%2) need0 = 1;
		LL rres = res;
		while(need0<=mod[0] && rres>=0)
		{
			LL nextot = tot*(c[mod[x]][rres]*c[mod[y]][rres]*c[mod[0]][need0]);
			nextot = get_mod(nextot);
			// cout<<need0<<" "<<rres<<" "<<nextot<<endl;
			ans+= nextot;
			ans = get_mod(ans);
			need0++;
			rres--;
		}
		// system("pause");
		return;
	}
	for(int i = min(res,mod[x]);i>=1;i--)
	{
		if((res-i)*2 > sum[x+1]*2 + sum[0]) return;
		LL nextot = tot * (c[mod[x]][i]*c[mod[y]][i]);
		// cout<<i<<endl;
		nextot = get_mod(nextot);
		dfs(x+1,y-1,res-i,nextot);
	}
}
int main()
{
	ycl();
	while(scanf("%d%d%d",&n,&m,&r)!=EOF)
	{
		for(int i = 1;i <= n;i++)
		{
			x = read();
			mod[(x%r+r)%r]++;
		}
		if(r%2 == 0)sum[r/2] = mod[r/2]/2;
		for(int i = (r-1)/2;i>=1;i--)
		{
			sum[i] = sum[i+1] + min(mod[i],mod[r-i]);
		}
		if(m%2 && mod[0] == 0) {
			puts("0");
			continue;
		} 
		if(m%2 && mod[0] == 0) {
			puts("0");
			continue;
		}
		dfs(1,r-1,m/2,1);
		if(m%2==0)
		ans--;
		ans = get_mod(ans);
		printf("%lld\n",ans);
		csh();
	}
}