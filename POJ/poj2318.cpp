#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define inc(i,l,r) for(int i = l;i<=r;i++)
#define dec(i,l,r) for(int i = l;i>=r;i--)
typedef long long ll;

struct Point{
	int x,y;
}toy[5005];
struct Line{
	Point a,b;
}b[5005];
int count[5005];
int n,m,xl,yu,xr,yd;
ll js_d(int pi,int li)
{
	int A = b[li].b.y - b[li].a.y;
	int B = b[li].a.x - b[li].b.x;
	ll C = b[li].b.x*1LL*b[li].a.y - b[li].a.x*1LL*b[li].b.y;
	ll D = A*1LL*toy[pi].x + B*1LL*toy[pi].y +C;
	cout<<"Point = "<<toy[pi].x<<" "<<toy[pi].y<<endl;
	cout<<"line = "<<b[li].a.x<<" "<<b[li].a.y<<" "<<b[li].b.x<<" "<<b[li].b.y<<endl;

	cout<<"D = "<<D<<endl;
	getchar();
	return D;
}
	
int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n == 0) return 0;
		scanf("%d%d%d%d%d",&m,&xl,&yu,&xr,&yd);
		
		int u,d;
		inc(i,1,n) {
			scanf("%d%d",&u,&d);
			b[i].b.x = u;b[i].b.y = yu;
			b[i].a.x = d;b[i].a.y = yd;
		}
		inc(i,1,m){
			scanf("%d%d",&toy[i].x,&toy[i].y);
		}
		int tot = 1;
		for(int i = 1;i<=n;i++)
		{
			while(tot<=m && js_d(tot,i) < 0){
				count[i-1]++;
				tot++;
			}
		}
		for(int i = tot;i<=m;i++) count[n]++;
		for(int i = 0;i<=n;i++)
		{
			cout<<i<<": "<<count[i]<<endl;
		}
		memset(count,0,sizeof(int)*(n+2));
	}
}



