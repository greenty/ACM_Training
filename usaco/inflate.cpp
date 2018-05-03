/*
ID: greenty2
PROG: inflate
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct cre{
	int c;
	int w;
};
cre a[10005];
int f[10005];
int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w>>a[i].c;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i].c;j<=m;j++)
		{
			f[j]=max(f[j],f[j-a[i].c]+a[i].w);
		}
	}
	cout<<f[m]<<endl;
	
	
	
	
}

