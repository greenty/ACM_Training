/*
ID:greenty2
LANG:C++
TASK:money
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int w[30];
long long f[10005][30];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int v,n;	
	scanf("%d%d",&v,&n);
	for(int i=1;i<=v;i++)
	{
		scanf("%d",&w[i]);
		if(w[i]>n) w[i]=0;
	}
	sort(w+1,w+v+1);
		//printf("hhh\n");
	for(int i=1;i<=v;i++)
	{
		f[0][i]=1;
		f[w[1]][i]=1;
	}

	for(int i=w[1]+1;i<=n;i++)
	{
		for(int k=1;k<=v;k++)
		{
			int c=i-w[k];
			if(c<0) f[i][k]=f[i][k-1];
			else f[i][k]=f[i][k-1]+f[c][k];	
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=v;j++)
//		{
//			printf("%d ",f[i][j]);
//		}
//		printf("\n");
//	}
	printf("%lld\n",f[n][v]);
}
