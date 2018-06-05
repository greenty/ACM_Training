#include<bits/stdc++.h>
using namespace std;
struct cre{
	int fz,fm;
}a[10],b[10];
void csh()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
}
int n;
void hj(cre &x)
{
	int __ = __gcd(x.fz,x.fm);
	x.fz/=__;
	x.fm/=__;
}
cre add(cre p,cre q)
{
	cre c;
	c.fm = p.fm*q.fm;
	c.fz = p.fz*q.fm+p.fm*q.fz;
	hj(c);
	return c;
}
cre div(cre p,cre q)
{
	cre c;
	c.fm = p.fm*q.fz;
	c.fz = p.fz*q.fm;
	hj(c);
	return c;
}
int main()
{
	int T;cin>>T;
	for(int _ = 1;_<=T;_++)
	{
		csh();
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].fz;
			a[i].fm = 1;
		}
		for(int i  =1;i<=n;i++)
		{
			cin>>b[i].fz;
			b[i].fm = 1;
		}
		cre res;
		res.fz = b[n].fz;
		res.fm = a[n].fz;
	//	cout<<res.fz<<" "<<res.fm<<endl;
		hj(res);
		for(int i = n-1;i>=1;i--)
		{
			res = add(res,a[i]);
			res = div(b[i],res);
	//	cout<<res.fz<<" "<<res.fm<<endl;
		}
		printf("Case #%d: %d %d\n",_,res.fz,res.fm);
	}
}

