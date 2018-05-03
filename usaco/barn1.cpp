/*
ID:greenty2
LANG:C++
TASK:barn1
*/
#include<cstdio>
#include<algorithm>
using namespace std; 
int cow[205];
int blk[205];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	int m,s,c;
	scanf("%d%d%d",&m,&s,&c);
	int a;
	int min=9999,max=0;
	for(int i=1;i<=c;i++)
	{
		scanf("%d",&a);
		cow[a]=1;
		if(a>max)max=a;
		if(a<min)min=a;
	}
	int t=0;
	for(int i=min;i<=max;i++)
	{
		if(cow[i]==1)
		continue;
		t++;
		while(cow[i]==0&&i<=s)
		{
			blk[t]++;
			i++;
		}
	}
	//for(int i=1;i<=t;i++)
	//{
	//	printf("%d\n",blk[i]);
	//}
	sort(blk+1,blk+t+1,cmp);
	int sum=0;
	for(int i=1;i<m;i++)
	{
		sum+=blk[i];
	}
	int ans=(max-min+1)-sum;
	printf("%d\n",ans);
} 
