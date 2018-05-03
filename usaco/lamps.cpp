/* 
ID:greenty2
LANG:C++
TASK:lamps
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int stan[105];
int minnum[9]={0,1,2,1,1,2,1,2,0};
int tab[9][7]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,1,1,1,0},{0,0,1,0,1,0,1},{0,0,1,1,0,1,1},{0,1,0,0,1,0,0},{0,1,0,1,0,1,0},{0,1,1,0,0,0,1},{0,1,1,1,1,1,1}};
int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	int n,c;
	scanf("%d%d",&n,&c);
	//cretab();
	memset(stan,-1,sizeof(stan));
	int a;
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
		break;
		stan[a]=1;
	}
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
		break;
		stan[a]=0;
	}
	int flag1=0;
	for(int i=1;i<=8;i++)
	{
		int flag2=1;
		for(int j=1;j<=n;j++)
		{
			if(stan[j]==-1)
			continue;
			int tmp=j%6;
			if(tmp==0) tmp=6;
			if(stan[j]!=tab[i][tmp])
			{
				flag2=0;
				break;
			}
		}
		if(flag2==1&&c>=minnum[i])
		{
			flag1=1;
			for(int j=1;j<=n;j++)
			{
				int tmp=j%6;
				if(tmp==0)tmp=6;
				printf("%d",tab[i][tmp]);
			}
			printf("\n");
		}
	}
	if(flag1==0)
	{
		printf("IMPOSSIBLE\n");
	}
	
	
}

