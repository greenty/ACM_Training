#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
set<ll>st;
int n;
ll s[3005],c[3005];
ll dp[3005][4];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>s[i];
	for(int i = 1;i<=n;i++) cin>>c[i];
	memset(dp,0x3f,sizeof(dp));	
	dp[0][0] = 0;
	for(int i = 1;i<=n;i++)
	{
		dp[i][0] = 0;
		dp[i][1] = c[i];
	}
	ll ans = inf;
	for(int i = 2;i<=n;i++)
	{
		for(int j = 1;j<=3;j++)
		{
			for(int k = 1;k<i;k++)
			{
				if(s[i]<=s[k]) continue;
				dp[i][j] = min(dp[k][j-1]+c[i],dp[i][j]);
			}
		}
		ans = ans < dp[i][3]?ans :dp[i][3];
	}
	
	if(ans == inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}
