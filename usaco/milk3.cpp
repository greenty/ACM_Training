/*
ID:greenty2
LANG:C++
TASK:milk3
*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std; 
int book[21][21][21];
int ans[10000],cont=0;
int A,B,C;

void pull(int& x,int& y,int& Y)
{
	int k=Y-y;
	if(k>x)
	{
		y=y+x;
		x=0;
		return ;
	}
	y=Y;
	x=x-k;
	return;
}
void dg(int a,int b,int c)
{
	if(a==0)
	{
		//printf("%d %d %d\n",a,b,c);
		cont++;
		ans[cont]=c;
	}
	if(c>0)
	{
		if(a<A)
		{
			int cc=c,aa=a;
			pull(cc,aa,A);
			if(book[aa][b][cc]==0)
			{
				book[aa][b][cc]=1;
				dg(aa,b,cc);
			//	book[aa][b][cc]=0;	
			}
		}
		if(b<B)
		{
			int cc=c,bb=b;
			pull(cc,bb,B);
			if(book[a][bb][cc]==0)
			{
				book[a][bb][cc]=1;
				dg(a,bb,cc);
				//book[a][bb][cc]=1;
			}
		}
	}
		if(a>0)
	{
		if(c<C)
		{
			int cc=c,aa=a;
			pull(aa,cc,C);
			if(book[aa][b][cc]==0)
			{
				book[aa][b][cc]=1;
				dg(aa,b,cc);
				//book[aa][b][cc]=0;	
			}
		}
		if(b<B)
		{
			int aa=a,bb=b;
			pull(aa,bb,B);
			if(book[aa][bb][c]==0)
			{
				book[aa][bb][c]=1;
				dg(aa,bb,c);
			//	book[aa][bb][c]=1;
			}
		}
	}
		if(b>0)
	{
		if(a<A)
		{
			int bb=b,aa=a;
			pull(bb,aa,A);
			if(book[aa][bb][c]==0)
			{
				book[aa][bb][c]=1;
				dg(aa,bb,c);
			//	book[aa][bb][c]=0;	
			}
		}
		if(c<C)
		{
			int cc=c,bb=b;
			pull(bb,cc,C);
			if(book[a][bb][cc]==0)
			{
				book[a][bb][cc]=1;
				dg(a,bb,cc);
				//book[a][bb][cc]=1;
			}
		}
	}
	return ;
	
	
	
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);

	scanf("%d%d%d",&A,&B,&C);
	book[0][0][C]=1;
	dg(0,0,C);
	sort(ans+1,ans+cont+1);
	for(int i=1;i<cont;i++)
	{
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[cont]);
} 
