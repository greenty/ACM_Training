#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,p,w;
vector<int>edge[100005];
int dp[100005][105];
int a[100005];
queue<int>q;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>p>>w;
	for(int i = 1;i<=n;i++) cin>>a[i];
	int x,y;
	for(int i = 1;i<=m;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int k = 1;k<=p;k++)
	{
		for(int i = 1;i<=n;i++) 
		{
			if(a[i] == k) {
				q.push(i);
				dp[i][k] = 1;
			}
		}
			while(!q.empty())
			{
				int now = q.front();q.pop();
				for(auto it = edge[now].begin();it!=edge[now].end();it++)
				{
					if(dp[*it][k] == 0){
						dp[*it][k] = dp[now][k] +1;
						q.push(*it);							
					} 

				}
			}
		
	}
	for(int i = 1;i<=n;i++)
	{
		int ans = 0;
		sort(dp[i]+1,dp[i]+1+p);
		for(int j = 1;j<=w;j++)
		{
			ans+=dp[i][j]-1;
		}
		cout<<ans<<" ";

	}
	cout<<endl;
}
