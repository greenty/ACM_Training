#include <bits/stdc++.h>
using namespace std;
vector<int>vec[65];
int n;
int now = 0;
void init()
{
	cin>>n;
	int x;
	for(int ii = 1; ii<= n;ii++)
	{
		cin>>x;
		now^=x;
		int xx = x;
		char c;
		int i = 0;
		while(x!=0)
		{
			i++;
			x /=2;
		}
	//	cout<<i<<endl;
		vec[60-i+1].push_back(xx);
	}
}
vector<int>ans;

int main()
{
	init();
	for(int i = n;i>=1;i--)
	{
		int nn = now;
		int siz = 60;
		int ok = 0;
		while(nn)
		{
			int x = nn%2;
		//	cout<<x<<" "<<siz<<endl;
		//	system("pause");
			if(x == 1)
			{
				if(!vec[siz].empty())
				{
					int k = vec[siz].back();
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