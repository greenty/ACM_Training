#include<bits/stdc++.h>
using namespace std;
string s[6];
typedef long long ll;
ll dp[105][2][2][2][2][2];
int n;
string tmp;
const ll MOD = 1e9+7;
ll yh[105][15];
void c()
{
	yh[1][0] = 1;yh[1][1] = 1;
	for(int i = 2;i<=100;i++)
	{
		for(int j = 0;j<=min(i,10);j++) yh[i][j] = yh[i-1][j-1] + yh[i-1][j],yh[i][j] %=MOD;

	}
}
int main()
{
	c();
	while(cin>>tmp)
	{
		s[1] = "0";
		s[1] += tmp;
		for(int i = 2;i<=5;i++) {
			s[i] = "0";
			cin>>tmp;
			s[i] +=tmp;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0][0][0] = 1ll;
		for(int i = 1;i<=100;i++)
		{
			//cout<<i<<endl;
			for(int i1 = 0;i1 <= 1;i1++) for(int i2 = 0;i2<=1;i2++)
			for(int i3 = 0;i3 <=1 ;i3++) for(int i4 = 0;i4<=1;i4++) for(int i5 = 0;i5<=1;i5++)
			dp[i][i1][i2][i3][i4][i5] = dp[i-1][i1][i2][i3][i4][i5];
			if(s[1][i] == '1')
			{
				for(int i1 = 0;i1<=1;i1++) for(int i2 = 0;i2<=1;i2++)
				for(int i3 = 0;i3<=1;i3++) for(int i4 = 0;i4<=1;i4++)
				{
				//cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;	
					dp[i][1][i1][i2][i3][i4] += dp[i-1][0][i1][i2][i3][i4];
					dp[i][1][i1][i2][i3][i4] %= MOD;
				}	

			}
			//cout<<i<<endl;
			if(s[2][i] == '1')
			{
				for(int i1 = 0;i1<=1;i1++) for(int i2 = 0;i2<=1;i2++)
				for(int i3 = 0;i3<=1;i3++) for(int i4 = 0;i4<=1;i4++)
					dp[i][i1][1][i2][i3][i4] += dp[i-1][i1][0][i2][i3][i4],
					dp[i][i1][1][i2][i3][i4] %= MOD;
			}
			//cout<<i<<endl;
			if(s[3][i] == '1')
			{
				for(int i1 = 0;i1<=1;i1++) for(int i2 = 0;i2<=1;i2++)
				for(int i3 = 0;i3<=1;i3++) for(int i4 = 0;i4<=1;i4++)
					dp[i][i1][i2][1][i3][i4] += dp[i-1][i1][i2][0][i3][i4],
					dp[i][i1][i2][1][i3][i4] %= MOD;
			}
			//cout<<i<<endl;
			if(s[4][i] == '1')
			{
				for(int i1 = 0;i1<=1;i1++) for(int i2 = 0;i2<=1;i2++)
				for(int i3 = 0;i3<=1;i3++) for(int i4 = 0;i4<=1;i4++)
					//[0]dp[i1][i2][i3][1][i4] = max(dp[i1][i2][i3][1][i4],dp[i1][i2][i3][0][i4] +1) ;
					dp[i][i1][i2][i3][1][i4] += dp[i-1][i1][i2][i3][0][i4],
					dp[i][i1][i2][i3][1][i4] %= MOD;
			}
			//cout<<i<<endl;
			if(s[5][i] == '1')
			{
				for(int i1 = 0;i1<=1;i1++) for(int i2 = 0;i2<=1;i2++)
				for(int i3 = 0;i3<=1;i3++) for(int i4 = 0;i4<=1;i4++)
//					dp[i1][i2][i3][i4][1] = max(dp[i1][i2][i3][i4][1],dp[i1][i2][i3][i4][0] +1) ;
					dp[i][i1][i2][i3][i4][1] += dp[i-1][i1][i2][i3][i4][0],
					dp[i][i1][i2][i3][i4][1] %= MOD;
			}
			//cout<<i<<endl;
			
		}
		ll ans = dp[100][1][1][1][1][1];
		ans %= MOD;
		for(int i = 95;i>90;i--) ans *= i,ans%=MOD;
		ans*=yh[90][5];
		ans%=MOD;
		ans*=yh[85][5];
		//ans*=531192758;
		ans %= MOD;
		cout<<ans<<endl;
	}
	return 0;
}
