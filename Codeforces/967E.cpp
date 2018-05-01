#include <bits/stdc++.h>
using namespace std;
vector<long long>vec[65];
long long n;
long long now = 0;
void init()
{
	cin>>n;
	long long x;
	for(long long ii = 1; ii<= n;ii++)
	{
		cin>>x;
		now^=x;
		long long xx = x;
		char c;
		long long i = 0;
		while(x!=0)
		{
			i++;
			x /=2;
		}
	//	cout<<i<<endl;
		vec[60-i+1].push_back(xx);
	}
}
vector<long long>ans;

int main()
{
	init();
	for(long long i = n;i>=1;i--)
	{
		long long nn = now;
		long long siz = 60;
		long long ok = 0;
		while(nn)
		{
			long long x = nn%2;
		//	cout<<x<<" "<<siz<<endl;
		//	system("pause");
			if(x == 1)
			{
				if(!vec[siz].empty())
				{
					long long k = vec[siz].back();
					ans.push_back(k);
					vec[siz].pop_back();
					ok = 1;
					now = now^k;
					break;
				}
			}
			nn/=2;
			siz--;
		}
		if(ok == 0)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(auto it = ans.rbegin();it!=ans.rend();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	
}
