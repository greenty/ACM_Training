/*
ID:greenty2
LANG:C++
TASK:nocows
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int f[105][205];
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++)
	{
		f[i][0]=1;
		f[i][1]=1;
	} 
	for(int i=2;i<=c;i++)
	{
		for(int j=1;j<=n;j+=2)
		{
			for(int k=0;k<j-1;k++)
			{
			//	printf("%d %d %d\n",i,j,k);
				f[i][j]+=f[i-1][k]*f[i-1][j-k-1];
				f[i][j]%=9901;
			} 
			
		}
	}
	int ans=f[c][n]-f[c-1][n];
	if(ans<0) ans+=9901; 
	printf("%d\n",ans);
	/*for(int i=1;i<=c;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}*/
	
}

