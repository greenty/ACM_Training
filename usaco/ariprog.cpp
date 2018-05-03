/*
ID:greenty2
LANG:C++
TASK:ariprog
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m;
int dic[200000];
//int num[100000];
int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	//int k=1;
	for(int i=0;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			dic[i*i+j*j]=1;
			//printf("%d ",i*i+j*j);
		}
	}
	//printf("\n");
	
	int M=2*m*m;
	int D=M/(n-1); 
	int FLAG=0;
	for(int d=1;d<=D;d++)
	{
		for(int k=0;k<=M;k++)
		{
			if(dic[k]==1)
			{
				int flag=0;
			//	printf("%d %d:",k,d);
				for(int i=1;i<=n;i++)
				{
				//	printf("%d ",k+i*d);
					if((k+i*d>M||dic[k+i*d]==0)&&i!=n)
					{
						flag=1;
						break;
					}
				}
				//printf("\n");
				if(flag==0)
				{
					FLAG=1;
					printf("%d %d\n",k,d);
				}
			}
		}
		
	}
	if(FLAG==0)
	{
		printf("NONE\n");
	}
}
