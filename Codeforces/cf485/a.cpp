#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string ans[10];
map<string,string>mp;
int main()
{
	mp["purple"] = "Power";
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["yellow"] = "Mind";
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>s;
		mp[s] = "0";
	}
	int tot= 0;
	for(auto it = mp.begin();it!=mp.end();it++)
	{
		if(!((*it).second =="0"))
		{
			ans[++tot] = (*it).second;	
		}
	}
	cout<<tot<<endl;
	for(int i = 1;i<=tot;i++)
	{
		cout<<ans[i]<<endl;
	}
}
