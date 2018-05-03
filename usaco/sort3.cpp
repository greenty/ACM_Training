/*
ID:greenty2
LANG:C++
TASK:sort3
*/
#include<cstdio>
#include<algorithm>
using namespace std; 
int a[1005],b[1005];
int book[1005];
int s[5],e[5];
int n;
int turn[5][5];
int main()
{
//	freopen("sort3.in","r",stdin);
//	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int t=1;
	if(b[t]==1) s[1]=t;
	while(b[t]==1&&t<=n)
	{
		t++;
	}
	if(b[t-1]==1) e[1]=t-1;
	if(b[t]==2) s[2]=t;
	while(b[t]==2&&t<=n)
	{
		t++;
	}
	if(b[t-1]==2) e[2]=t-1;
	if(b[t]==3)s[3]=t;
	if(b[n]==3)e[3]=n;
	//for(int i=1;i<=3;i++)
	//{
	//	printf("%d %d\n",s[i],e[i]);
	//}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=3;k++)
		{
			if(i<=e[k]&&i>=s[k])
			{
				turn[k][a[i]]++;
				break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=3;j++)
		{
			int k=min(turn[i][j],turn[j][i]);
			ans+=k;
			turn[i][j]-=k;
			turn[j][i]-=k;
		}
	}
	turn[1][1]=0;
	turn[2][2]=0;
	turn[3][3]=0;
	int sum=0; 
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			sum+=turn[i][j];
		}
	}
	sum=(sum/3)*2;
	ans+=sum;
	printf("%d\n",ans);
	
}
