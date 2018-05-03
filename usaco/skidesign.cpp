/*
ID:greenty2
LANG:C++
TASK:skidesign
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	int n;
	scanf("%d",&n);
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//sum+=a[i]*1.0/n;
	}
    int ans=99999999;
	for(int i=17;i<=100;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]<i-17)
			{
				sum+=pow((i-17-a[j]),2);
				continue;
			}
			if(a[j]>i)
			{
				sum+=pow(a[j]-i,2);
			}
		}
		if(sum<ans)ans=sum;
	} 
	printf("%d\n",ans);
} 

