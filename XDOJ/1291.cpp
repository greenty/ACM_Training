#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int _;cin>>_;
	while(_--)
	{
		cin>>s;
		if(s[0] == 'o') cout<<"yi"<<endl;
		else if(s[0] == 't'&& s[1] == 'w') cout<<"er"<<endl;
		else if(s[0] == 't'&& s[1] == 'h') cout<<"san"<<endl;
		else if(s[0] == 'f'&& s[1] == 'o')cout<<"si"<<endl;
		else if(s[0] == 'f'&& s[1] == 'i')cout<<"wu"<<endl;
		else if(s[0] == 's'&& s[1] == 'i') cout<<"liu"<<endl;
		else if(s[0] == 's'&& s[1] == 'e') cout<<"qi"<<endl;
		else if(s[0] == 'e') cout<<"ba"<<endl;
		else if(s[0] == 'n') cout<<"jiu"<<endl;
		else cout<<"shi"<<endl;
	}
}