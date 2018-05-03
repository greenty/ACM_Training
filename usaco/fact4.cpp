/*
ID:greenty2
LANG:C++
TASK:fact4
*/
#include<bits/stdc++.h>
using namespace std;
int cl(int a)
{
	int p=a%10;
	while(p==0)
	{
		a=a/10;
		p=a%10;
	} 
	a=a%100000;
	return a;
}
int main()
{
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	int n;
	cin>>n;
	int f=1;
	for(int i=2;i<=n;i++)
	{
		int k=f*i;
		f=cl(k);
	//	cout<<i<<"::"<<k<<"::"<<f<<endl;
	}
	cout<<f%10<<endl;
	
}
