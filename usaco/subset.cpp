/*
ID:greenty2
LANG:C++
TASK:subset
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sum;
long long f[1000];//把前i个数划分到一个集合，和为j的方法数 
int main()
{
	//freopen("subset.in","r",stdin);
	//freopen("subset.out","w",stdout);
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	
	if(sum%2!=0)
	{
		printf("0\n");
		return 0;
		//continue;
	}
	//printf("sum=%d\n",sum/2);
	sum/=2;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(j-i>=0)
			{
				f[j]=f[j]+f[j-i];
				if(i-1==0&&j==0) f[j]++;
			} 
			else
			f[j]=f[j];
			if(i-1==0&&j==0) f[j]++;
		} 
	}
	printf("%d",f[sum]);
}

