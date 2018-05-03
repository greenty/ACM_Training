/*
ID:greenty2
LANG:C++
TASK:holstein
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int v,g;
int a[20];
int ex[30],sl[20][30];
int tot[30];
int ans[20],len=9999;
void dg(int cs)
{
	if(cs<=len)
	{	
		//printf("hhh\n");
		memset(tot,0,sizeof(tot));
		for(int i = 1;i < cs;i++)
		{
			
			for(int j=1;j<=v;j++)
			{
				tot[j]+=sl[a[i]][j];
			}
		//printf("%d ",a[i]);
		}
	//	printf("\n");
		int flag=0;
	//	for(int i=1;i<=v;i++)
	//	{
	//		printf("%d ",tot[i]);
	//	}printf("\n\n");
		for(int i=1;i<=v;i++)
		{
		//	printf("%d ",tot[i]);
			if(tot[i]<ex[i])
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
		//for(int i=1;i<=v;i++)
		//{
		//	printf("%d ",tot[i]);
		//}//printf("\n");
			len=cs;
			for(int i=1;i<cs;i++)
			{
				ans[i]=a[i];
			//	printf("гд%d ",ans[i]);
			}
			//printf("\n\n");
		}
	}
	//printf("\n");
	if(cs > g) return ;
	for(int i = a[cs-1]+1;i <= g;i++)
	{
		a[cs]=i;
		dg(cs+1);
	} 
} 
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&v);
	 for(int i=1;i<=v;i++)
	 {
	 	scanf("%d",&ex[i]);
	 }
	 scanf("%d",&g);
	 for(int i=1;i<=g;i++)
	 {
	 	for(int j=1;j<=v;j++)
	 	{
	 		scanf("%d",&sl[i][j]);
	 	}
	 } 
	dg(1);
	printf("%d ",len-1);
	for(int i=1;i<len-1;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d",ans[len-1]);
	printf("\n");
}

