/*
ID:greenty2
LANG:C++
TASK:wormhole 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib> 
using namespace std;
struct map{
	int x;
	int y;
};
map p[20];
int a[20];
int partner[20];
int book[20];
int book2[20];
int n;
int next[20];
//int px[20],py[20];
bool cmp(map c,map v)
{
	if(c.y==v.y)
	return c.x<v.x;
	return c.y<v.y;
}
int sum;
/*int pd()
{}*
	for(int i=1;i<n;i+=2)
	{
		if(p[a[i]].x==p[a[i+1]].x)
		{
			return 1;
		}
	}
	int p1,p2,q1,q2;
	for(int i=1;i<=n/2;i++)
	{
		for(int j=i;j<=n/2;j++)
		{
			if(i!=j)
			{
				p1=2*i-1;
				p2=p1+1; 
				q1=2*j-1;
				q2=q1+1;
				//printf("****%d %d %d %d",p1,p2,q1,q2);
				//printf("***%d %d %d %d\n",a[p1],a[p2],a[q1],a[q2]);
				//printf("**%d %d\n**%d %d\n**%d %d\n**%d %d\n\n",p[a[p1]].x,p[a[q1]].x,p[a[p2]].x,p[a[q2]].x,p[a[p1]].y,p[a[q1]].y,p[a[p2]].y,p[a[q2]].y);
				if((p[a[p1]].x==p[a[q1]].x)&&(p[a[p2]].x==p[a[q2]].x)&&(p[a[p1]].y<p[a[q1]].y)&&(p[a[p2]].y>p[a[q2]].y))
				{
					return 1;
				}
				int t=q1;
				q1=q2;
				q2=t;
				if((p[a[p1]].x==p[a[q1]].x)&&(p[a[p2]].x==p[a[q2]].x)&&(p[a[p1]].y<p[a[q1]].y)&&(p[a[p2]].y>p[a[q2]].y))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}*/
int enter(int po)
{
	int t=po;
	int now=1;
	while(1)
	{
		if(now==1)
		{
			book2[t]=1;
	
			t=partner[t];
			now=0;
		}
		if(now==0)
		{
			if(next[t]==0)
				return 0;
			t=next[t];
			if(book2[t]==1)
				return 1;
			book2[t]=1;
			now=1;
		}
	}
}
int pd()
{
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		memset(book2,0,sizeof(book2));		
		flag=enter(i);
		if(flag==1)return 1;
	} 
	return 0;
}
void hs(int cs)
{
	if(cs>n)
	{
			for(int i=1;i<n;i+=2)
		{
			partner[a[i]]=a[i+1];
			partner[a[i+1]]=a[i];
		}
		sum+=pd();
		return;
	}
	if(cs%2!=0)
	{
		if(cs>1)
		{
		for(int i=a[cs-2];i<=n;i++)
		{
			if(book[i]==0)
			{
				book[i]=1;
				a[cs]=i;
				hs(cs+1);
				book[i]=0;
			} 
		}
		return;
		}
		for(int i=1;i<=n;i++)
		{
			if(book[i]==0)
			{
				book[i]=1;
				a[cs]=i;
				hs(cs+1);
				book[i]=0;
			} 
		}
		return ; 
	}
	if(cs%2==0)
	{
		for(int i=a[cs-1]+1;i<=n;i++)
		{
			if(book[i]==0)
			{
			book[i]=1;
			a[cs]=i;
			hs(cs+1);
			book[i]=0;
			}
		}
		return;
	}
} 
int main()
{
	//freopen("wormhole.in","r",stdin);
	//freopen("wormhole.out","w",stdout);
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y); 
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(p[i].y==p[i+1].y)
		{
			next[i]=i+1;
		}
	}
	//for(int i=1;i<=n;i++)
	//{
//		printf("**%d\n",next[i]);
//	}
//	system("pause");
//		for(int i=1;i<=n;i++)
	//{
//	printf("%d %d\n",p[i].x,p[i].y);
//	}
	hs(1);
	printf("%d\n",sum);
}
