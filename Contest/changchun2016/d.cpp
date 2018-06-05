#include<bits/stdc++.h>
using namespace std;
int a[] = {1,2,3,5,8,13,0};
int main()
{
	int T,n;
	cin>>T;
	for(int _  =1;_<=T;_++)
	{
		cin>>n;
		int pos = 0;
		int res = 0;
		for(int i= 1;i<=n;i++)
		{
			if(i == a[pos]){
				res++;
				pos++;
			}
		}
		printf("Case #%d: %d\n",_,n-res);
	}
}
