/*
ID:greenty2
LANG:C++
TASK:numtri
*/
#include<cstdio>
#include<algorithm>
using namespace std; 
int f[1001][1001];
int map[1001][1001];
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[n][i]=map[n][i];
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+map[i][j];
		}
	}
	printf("%d\n",f[1][1]);
} 
