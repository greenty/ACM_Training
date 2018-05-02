/*
	
	spell 1:consider h1 > h2 ,if you can double 2 times
	        you may get h1*4 h1*2+h2*2 h2*4
			h1*4 must be largest
			it means we can double A times to a single creature to get largest answer
	spell 2:if hi < di we won't exchange them..
	maybe a creature's h - d isn't big ,but its h is large enough ,if you double it several times ,you will get better answer
	we can consider a greedy strategy : if one's h < d ans spell 2 has been run out,
	when we try to double it ,we could go back on the worst exchange (h > d but h-d is smallest), then exchange this creature
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  LL; 
struct cre{
	LL h,d;
	bool ex;
}c[200005];
int n,a,b;
LL sumd,sum2;
bool cmp(cre x,cre y)
{
	return (x.h-x.d) > (y.h-y.d);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i].h >> c[i].d;
		c[i].ex = false;
		sumd+=c[i].d;
	} 
	sum2 = sumd;
	sort(c+1,c+n+1,cmp);
	int k = n;
	for(int i = 1;i<=n;i++)
	{
		if(c[i].h - c[i].d < 0 || b == 0)
		{
			k = i-1;
			break;
		} 
		c[i].ex = true;
		sum2 = sum2 + (c[i].h - c[i].d);
		b--;
	}
	LL ans = max(sumd,sum2);
	LL bs = 1LL<<a;
	if(b == 0)
	{
		for(int i = 1;i<=n;i++)
		{
			if(c[i].ex == true) 
			{
				ans = max ( ans , sum2 - c[i].h + bs*c[i].h );
			}
			else
			{
				if(k>0)
					ans = max ( ans , sum2 - c[k].h + c[k].d - c[i].d + bs*c[i].h );
			}
		}
	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			if(c[i].ex == true)
			{
				ans = max ( ans , sum2 - c[i].h + bs*c[i].h );
			}
			else
			{
				ans = max (ans , sum2 - c[i].d + bs*c[i].h );
			}
		} 
	}
	cout<<ans<<endl;
}
