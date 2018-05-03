/*
ID:greenty2
LANG:C++
TASK:palsquare
*/
#include<cstdio>
int sz[100000];
int sz2[100000];
int zh(int a,int n)
{
	int t=0;
	while(a!=0)
	{
		t++;
		sz[t]=a%n;
		a=a/n;
	}
	return t;
}
int pd(int n)
{
	for(int i=1;i<=n/2;i++)
	{
		if(sz[i]!=sz[n-i+1])
		return 0;
	}
	return 1;
}
int zh2(int a,int n)
{
	int t=0;
	while(a!=0)
	{
		t++;
		sz2[t]=a%n;
		a=a/n;
	}
	return t;
}
int pd2(int n)
{
	for(int i=1;i<=n/2;i++)
	{
		if(sz2[i]!=sz2[n-i+1])
		return 0;
	}
	return 1;
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int n;
	scanf("%d",&n);
	int js=0;
	for(int i=1;i<=300;i++)
	{
		int len=zh(i,n);
		//int flag=pd(len);
		//if(flag==0)
		//continue;
		int k=i*i;
		int len2=zh2(k,n);
		int flag=pd2(len2);
		if(flag==1)
		{
			for(int i=len;i>=1;i--)
			{ 
				if(sz[i]>=10)
				{
					char c='A';
					c+=(sz[i]-10);
					printf("%c",c);
					continue;
				}
				printf("%d",sz[i]);
			}
			printf(" ");
			for(int i=len2;i>=1;i--)
			{
				if(sz2[i]>=10)
				{
					char c='A';
					c+=(sz2[i]-10);
					printf("%c",c);
					continue;
				}
				printf("%d",sz2[i]);
			}
			printf("\n");
		}		
	} 
	return 0;
	
}

