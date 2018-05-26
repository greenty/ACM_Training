#include <bits/stdc++.h>
using namespace std;
int js[5];
int n;
int a[2][10005];
int main()
{
	//ios::sync_with_stdio(false);
	int _;
	cin>>_;
	while(_--)
	{
		cin>>n;
		int x;
		js[0] = js[1] = js[2] = 0;
		for(int i = 1;i<=2;i++) for(int j = 1;j<=n;j++){
			cin>>x;
			js[x%3]++;
		}
		if(js[1] == 0 || js[2] == 0) {
			if(js[0]<=n)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
			continue;
		}
		if(js[0]<2 || js[0] > n) {
			cout<<"NO"<<endl;
			continue;
		}
		memset(a,-1,sizeof(a));
				int l = 1;
				int r = (n-js[0])*2+1;
				int flag = 0;
				while(r>0)
				{
				//	cout<<l<<" "<<r<<" "<<js[1]<<" "<<js[2]<<endl;
					if(l<=js[1] && r<=js[2])
					{
						flag  = 1;
						break;
					}
					l+=2;
					r-=2;
				}
				if(flag ) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;

	}
}