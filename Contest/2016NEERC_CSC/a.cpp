#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n <=k)
	{
		cout<<2<<endl;
		return 0;
	}
	int ans = (2*n)/k;
	if((2*n)%k) ans++;
	cout<<ans<<endl;
}
