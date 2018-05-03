/*
ID:greenty2
LANG:C++
TASK:pprime
*/
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<cstdlib> 
int a,b;
int lena,lenb;
char s[100];
int prime(int n)
{
	int k=sqrt(n);
	for(int i=2;i<=k;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	scanf("%d%d",&a,&b);
	sprintf(s,"%d",b);
	//printf("%s",s);
	lenb=strlen(s);
	sprintf(s,"%d",a);
	lena=strlen(s);
	//printf("%d %d",lena,lenb);
	for(int i=lena;i<=lenb;i++)
	{
		if(i==1)
		{
			for(int j=a;j<=9;j++)
			{
				if(prime(j))
				printf("%d\n",j);
			}
			continue;
		}
		if(i%2==0)
		{
			int len=i/2;
			int st=pow(10,len-1);
			int et=pow(10,len);
			for(int j=st;j<et;j++)
			{
				sprintf(s,"%d",j);
				//printf("s:%s\n",s);
				for(int k=0;k<len;k++)
				{
					s[2*len-k-1]=s[k];
				}
				s[2*len]=0;
				int t=atoi(s);
				//printf("t:%d\n",t);
				if(t<a)
				{
					continue;
				}
				if(t>b)
				{
					return 0;
				}
				if(prime(t))
				{
					printf("%d\n",t);
				}
			}
			continue;
		}
		if(i%2!=0)
		{
			int len=i/2;
			int st=pow(10,len-1);
			int et=pow(10,len);
			for(int j=st;j<et;j++)
			{
				sprintf(s,"%d",j);
				for(int p=0;p<=9;p++)
				{
					s[len]=p+'0';
					for(int k=0;k<len;k++)
					{
						s[2*len-k]=s[k];
					}
					s[2*len+1]=0;
					int t=atoi(s);
					if(t<a)
					continue;
					if(t>b)
					return 0;
					if(prime(t))
					{
						printf("%d\n",t);
					}
				}
			}
		}
		
	}
} 
