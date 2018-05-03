/*
ID:greenty2
LANG:C++
TASK:concom 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
bool book[105][105]={0};
int a[105][105]={0};
int n,m=0;
void dfs(int i,int j)
{
	if(book[i][j]) return ;
	book[i][j]=true;
	for(int k=1;k<=m;k++)
	{
		a[i][k]+=a[j][k];
		if (a[i][k]>50) 
		dfs(i,k);
	} 
}
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	
	scanf("%d",&n);
	int x,y,w;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		a[x][y]+=w;
		if(x>m)m=x;
		if(y>m)m=y;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]>50)
			{
				dfs(i,j);
			}
		} 
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(book[i][j]&&i!=j)
			{
				printf("%d %d\n",i,j);
			}
		}

	
	}
}

