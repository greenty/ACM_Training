/*
ID:greenty2
LANG:C++
TASK:milk
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct fmer{
	int c;
	int num;
};
fmer a[5005];
bool cmp(fmer x,fmer y)
{
	return x.c<y.c;
}
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int s,n;
	scanf("%d%d",&s,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].c,&a[i].num);
	}
	int cost=0;
	sort(a+1,a+n+1,cmp);
	int k;
	for(int i=1;i<=n;i++)
	{
		cost+=a[i].c*a[i].num;
		s-=a[i].num;
		if(s==0)
		break;
		if(s<0)
		{
			cost-=a[i].c*a[i].num;
			s+=a[i].num;
			cost+=a[i].c*s;
			break;
			
		}
	}
	printf("%d\n",cost);
}
