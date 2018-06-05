#include<bits/stdc++.h>
using namespace std;
int n;
int prime[2000005],tot;
bool v[20000005];
int m;
#define inc(i,l,r) for(int i = l;i<=r;i++)
void get_ss()
{
	m=2e7;tot=0;v[1]=true;
	for(int i = 2;i<=m;i++)
	{
		if(!v[i])prime[++tot]=i;
		inc(j,1,tot){
			if(i*prime[j]>m)break;
			v[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	get_ss();
	cin>>n;
	int js = 0;
	for(int i = 1;i<=tot;i++)
	{
		if(prime[i]>n) break;
		if(n%prime[i] == 0)
		{
			js++;
			while(n%prime[i] == 0)
			{
				n /=prime[i];
			}
		}
	}
	if(js == 3) printf("YES\n");
	else printf("NO\n");
}
