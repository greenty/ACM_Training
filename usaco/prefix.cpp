/*
ID:greenty2
LANG:C++
TASK:prefix 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char p[205][15];
int len[205];
int begin[15];
char s[200005]; 
int f[200005];
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	int n=1;
	scanf("%s",p[n]);
	while(strcmp(p[n],".")!=0)
	{
		len[n]=strlen(p[n]);
		n++;
		scanf("%s",p[n]);
		
	}
	n--;
	for(int i=n;i>1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(len[j]>len[j+1])
			{
				int t=len[j];
				len[j]=len[j+1];
				len[j+1]=t;
				char tt[15];
				strcpy(tt,p[j]);
				strcpy(p[j],p[j+1]);
				strcpy(p[j+1],tt);
			}
		}
	}
	int max,min;
	begin[len[1]]=1;
	min=len[1];
	max=len[n];
	for(int i=2;i<=n;i++)
	{
		if(len[i]!=len[i-1])
		{
			begin[len[i]]=i;
		}
	}
	int lenth=1;
	while(scanf("%c",&s[lenth])!=EOF)
	{
		if(s[lenth]!='\n')
		lenth++;
	//	printf("hhh\n");
	}
	s[lenth]='\0';
	s[0]='0';
//for(int i=1;i<=n;i++)
//	{
//		printf("%s\n",p[i]);
//	}
	//printf("::%d %s\n",lenth,s);
	lenth--;
	//printf("hhh\n");
	f[0]=1;
	int ans=0;
	for(int i=1;i<=lenth;i++)
	{
		
		for(int j=i-min;j>=i-max;j--)
		{
		//	printf("I:%d\nJ:%d\n",i,j);
		//	system("pause");
			if(j<0)
			{
				continue;
			}
			if(f[j]==1)
			{  //printf("k:%d\n",begin[i-j]); system("pause");
				for(int k=begin[i-j];;k++)
				{
				//	printf("%d %s %s %d\n",k,p[k],s+j+1,len[k]);
				    if(len[k]!=i-j)
				    break;
					if(strncmp(p[k],s+j+1,len[k])==0)
					{
						f[i]=1;
						ans=i;
						break;
					}
				}
			} 
			if(f[i]==1)
			break;
		}
	}
	//for(int i=0;i<=lenth;i++)
	//{
	//	printf("%d",f[i]);
	//}
	printf("%d\n",ans);
	
}

