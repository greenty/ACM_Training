#include <bits/stdc++.h>
using namespace std;
int a,b,c,n;
int sa,sb,sc;
int C[200005];
int d[10];
int check(int x)
{
	int aa = a,bb = b,cc = c;
	if(sb+sb > sa + sc)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a>=2 && (sa+sa)*C[i]>=x){
				a-=2;
			}
			else if(a >=1 && b>=1 &&(sa+sb)*C[i]>=x){
				a--;b--;
			}
			else if(a>=1 && c>=1 && (sa+sc)*C[i]>=x){
				a--;c--;
			}
			else if(b>=2&&(sb+sb)*C[i]>=x){
				b-=2;
			}
			else if(b>=1 && c>=1 &&(sb+sc)*C[i]>=x){
				b--;c--;
			}
			else if(c>=2&&(sc+sc)*C[i]>=x){
				c-=2;
			}
			else
			{
				a = aa;b = bb;c = cc;
				return 0;
			}
		}
		a = aa;b = bb;c = cc;
		return 1;

	}
	else
	{
		for(int i = 1;i<=n;i++)
		{
			if(a>=2 && (sa+sa)*C[i]>=x){
				a-=2;
			}
			else if(a >=1 && b>=1 &&(sa+sb)*C[i]>=x){
				a--;b--;
			}
			else if(b>=2&&(sb+sb)*C[i]>=x){
				b-=2;
			}
			else if(a>=1 && c>=1 && (sa+sc)*C[i]>=x){
				a--;c--;
			}
			else if(b>=1 && c>=1 &&(sb+sc)*C[i]>=x){
				b--;c--;
			}
			else if(c>=2&&(sc+sc)*C[i]>=x){
				c-=2;
			}
			else
			{
				a = aa;b = bb;c = cc;
				return 0;
			}
		}
		a = aa;b = bb;c = cc;
		return 1;

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>c;
	cin>>sa>>sb>>sc;
	n = (a+b+c)/2;
	for(int i = 1;i<=n;i++) cin>>C[i];
	sort(C+1,C+n+1);
		int l = 1,r = 2000000000;
		int ans = 0;
		while(l<=r)
		{
			int mid = (l+r)>>1;
			if(check(mid)){
				ans = mid;
				l = mid+1;
			}
			else
				r = mid-1;
		}
		cout<<ans<<endl;

}
