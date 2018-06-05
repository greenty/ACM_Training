#include<bits/stdc++.h>
using namespace std;
int _;
string s;
int book[30];
int main()
{
	cin>>_;
	while(_--)
	{
		cin>>s;
		int n = s.size();
		memset(book,0,sizeof(book));
		for(int i = 0;i<n;i+=2)
		{
			book[s[i]-'a']++;
		}
		int ans = 99999999;
		for(int i = 0;i<26;i++)
		{
			ans = min (ans,(n+1)/2-book[i]);
		}
		memset(book,0,sizeof(book));
		for(int i = 1;i<n;i+=2)
		{
			book[s[i]-'a']++;
		}
		int ans2 = 9999999;
		for(int i = 0;i<26;i++)
		{
			ans2 = min(ans2,n-(n+1)/2-book[i]);
		}
		cout<<ans+ans2<<endl;
	}
}
