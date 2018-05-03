/*
ID: greenty2
PROG: agrinet
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct cre{
	int u;
	int v;
	int w;
};
cre a[10005];
int fa[105];
bool cmp(cre x,cre y)
{
	return x.w<y.w;
}
int getf(int x)
{
	if(fa[x]==x)
	return x;
	return fa[x]=getf(fa[x]);
}
int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	int n;
	cin>>n;
	int x;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			if(x==0)
			continue;
			a[++t].u=i;
			a[t].v=j;
			a[t].w=x;
		}
	}
	//cout<<"hhh  "<<t<<endl;
	sort(a+1,a+t+1,cmp);
	int ans=0;
	for(int i=1;i<=t;i++)
	{
		int fx=getf(a[i].u);
		int fy=getf(a[i].v);
		if(fx!=fy)
		{
			fa[fx]=fy;
			ans+=a[i].w;
		}
	}
	cout<<ans<<endl;
} 
