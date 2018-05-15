/*
	DFS 
	The id number of the point of a triangle are in order to avoid 1 2 3 and 2 1 3
	The first points of  triangles are in order to avoid 1 2 3 ,4 5 6  and 4 5 6,1 2 3
	3 layers in one recursion. 
*/
#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool cmp(int x,int y)
{
	return x > y;
}
int ans[20];
double anss = 0.0;
double tri[20];
int book[20];
int m;
void csh()
{
	anss = 0.0;
	memset(book,0,sizeof(book));memset(ans,0,sizeof(ans));memset(a,0,sizeof(a));memset(tri,0,sizeof(tri));
}
double js(int x)
{
	int aa  = ans[x],bb = ans[x-1] , cc = ans[x-2];
	double pp = (aa+bb+cc) /2.0;
	return sqrt(pp * (pp-aa) *(pp-bb) * (pp -cc ));
}
void dfs(int cs,int be)
{
	double tot = 0.0;
	for(int i = 1;i<=cs/3;i++)	tot+=tri[i];
	if( tot > anss) anss = tot;
	if(cs >m) return ;
	for(int i = be;i<=n;i++)for(int j = i+1;j<=n;j++)for(int k = j+1;k<=n;k++)
		if(book[i] == 0 && book[j] == 0 && book[k] == 0)
		{
			if(a[k] + a[j] <= a[i]) continue;
			ans[cs] = a[i];ans[cs+1] = a[j];ans[cs+2] = a[k];
			tri[(cs+2)/3] = js (cs+2);
			book[i] = book[j] = book[k] = 1;
			dfs(cs+3,i+1);
			book[i] = book[j] = book[k] = 0;
		}
}
int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) return 0;
		for(int  i =1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		m = n/3*3;
		dfs(1,1);
		printf("%.2f\n",anss+eps);
		csh();
	}
}