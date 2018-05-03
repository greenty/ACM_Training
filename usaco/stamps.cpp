/*
ID: greenty2
PROG: stamps
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int f[2000005];
int v[55];
int main()
{
//	freopen("stamps.in","r",stdin);
//	freopen("stamps.out","w",stdout);
	int k,n;
	cin>>k>>n;
	int c;
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		
	}
	for(int i=1;i<=2000000;i++)
	{
		f[i]=0xfffffff;
	}
	int x=1;
	for(;;x++)
	{
		for(int i=1;i<=n;i++)
		{
			f[x]=min(f[x],f[x-v[i]]+1);
			cout<<i<<" "<<f[x]<<endl;
		}
		cout<<x<<":"<<f[x]<<endl;
		system("pause");
		if(f[x]>k)
		{
			cout<<x-1<<endl;
			return 0;
		}
	}
}
