/*
ID: greenty2
PROG: humble
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int f[105];
int pre[105];
int ef(int s,int t,int p,long long d)
{
//	cout<<s<<" "<<t<<endl;
	
	int m=(s+t)/2;
	long long c1=a[m]*f[p],c2;
	if(s>t)
	return m;
	if(m>0)
	{
		c2=a[m-1]*f[p];
	}
	else
	c2=0;
	if(c1>d&&c2<=d)
	{
		return m;
	}
	if(c1>d)
	return ef(s,m,p,d);
	else
	return ef(m+1,t,p,d);
} 
int main()
{
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
	}
//	sort(f+1,f+n+1);
	a[0]=1;
	a[1]=f[1];
	//cout<<k<<endl;
//	ef(0,24695,6,634894848);
//	system("pause");
//	system("pause");
	for(int i=2;i<=k;i++)
	{
		
		
		long long d=a[i-1];
	//	cout<<d<<endl;
		int min=0x7fffffff;
		
		for(int p=1;p<=n;p++)
		{
			/*for(int j=0;j<i;j++)
			{
					//	cout<<j<<" "<<p<<" "<<a[j]*f[p]<<endl;
				if(a[j]*f[p]>d&&(j==0||a[j-1]*f[p]<=d))
				{
			
					if(min>a[j]*f[p])
					min=a[j]*f[p];
					break;
				}	
			}*/
	//		if(i==24695)
	//		cout<<p<<' '<<d<<endl;
			int v=ef(pre[p],i,p,d);
			pre[p]=v;
			long long vv=a[v]*f[p];
			if(min>vv)
			{
				min=vv;
			}
		}
		a[i]=min;
		//if(i>24000)
		//cout<<i<<endl;	
//		for(int j=1;j<=i;j++)
//	{
//		cout<<a[j]<<" ";
//	}
//	cout<<endl;
	//system("pause");
	}
	cout<<a[k]<<endl;
} 
