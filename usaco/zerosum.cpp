/*
ID:greenty2
LANG:C++
TASK:zerosum
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[10];
int num[10]; 
char fh[10];
void dg(int cs)
{
	if(cs>=n)
	{
		for(int i=1;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("---------\n");
		//int sum=0;
		int t=0;
		for(int i=1;i<=n;i++)
		{
			
			t++;
			num[t]=i;
			int flag=0;
			if(a[i-1]==2)
			{
				flag=1;
			}
			while(a[i]==3)
			{
				i++;
				num[t]*=10;
				num[t]+=i;
			}
			if(flag==1)
			{
				num[t]=-num[t];
			}
			
		}
	//	for(int i=1;i<n;i++)
	//	{
	//		printf("%d ",a[i]);
	//	}
	//	printf("\n");
		int sum=0;
		for(int i=1;i<=t;i++)
		{
			sum+=num[i];
			//printf("%d ",num[i]);
		}
	//	printf("\n\n");
		if(sum==0)
		{
			//int k=1;
			//char c;
			for(int i=1;i<=n;i++)
			{
				printf("%d",i);
				if(a[i]==1)printf("+");
				if(a[i]==2)printf("-");
				if(a[i]==3)printf(" ");
			}
			printf("\n");	
		} 
		return;
	}
	for(int i=1;i<=3;i++)
	{
		a[cs]=i;
		dg(cs+1);
	}
}
int main()
{
	//freopen("zerosum.in","r",stdin);
//	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	dg(1);
}

