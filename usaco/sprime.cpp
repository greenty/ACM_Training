/*
ID:greenty2
LANG:C++
TASK:sprime
*/
#include<cstdio>
#include<cstdlib> 
#include<cmath>
int n;
char a[10];
int pd(int k)
{
	if(k==1)return 0;
	int c=sqrt(k);
	for(int i=2;i<=c;i++)
	{
		if(k%i==0)
		return 0;
	}
	return 1;
}
void dg(int cs)
{
	a[cs]=0;
	int k=atoi(a);
	if(pd(k)==0) return;
	//printf("%d\n",k);
	if(cs>=n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%c",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=9;i++)
	{
		a[cs]=i+'0';
		
	
		
		dg(cs+1);
		//a[cs]=0;
	}
	
	
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	
	scanf("%d",&n);
	dg(0);
} 
