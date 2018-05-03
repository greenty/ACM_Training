/*
ID:greenty2
LANG:C++
TASK:hamming
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int map[10][10];
int a[70][10];
int t=1;
int part1,part2;
int n,b,d;
void dg(int dis,int head)
{
	if(part2==0)
	{
		int flag=0;
		int k1=head;
		for(int i=1;i<=t;i++)
		{
			if(map[k1][a[i][1]] < dis)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			t++;
			a[t][1]=k1;
			if(t==n)
			{
				return;
			}
		}
	}
	if(part2==1)
	{
		for(int k1=0;k1<=7;k1++)
		{
			int flag=0;
			int k2=head;
			for(int i=1;i<=t;i++)
			{
				if( map[k1][a[i][1]] +map[k2][a[i][2]]< dis)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				t++;
				a[t][1]=k1;
				a[t][2]=k2;
				if(t==n)
				{
					return;
				}
			}
		}
	}
	if(part2==2)
	{
		for(int k2=0;k2<=7;k2++)
		{
			for(int k1=0;k1<=7;k1++)
			{
				int flag=0;
				int k3=head;
				for(int i=1;i<=t;i++)
				{
					if( map[k1][a[i][1]]+map[k2][a[i][2]]+map[k3][a[i][3]]<dis)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					t++;
					a[t][1]=k1;
					a[t][2]=k2;
					a[t][3]=k3;
					if(t==n)
					{
						return;
					}
				}
			}
		}
	}
}
void cdmap()
{
	map[0][1]=1;map[0][2]=1;map[0][3]=2;map[0][4]=1;map[0][5]=2;map[0][6]=2;map[0][7]=3;
	            map[1][2]=2;map[1][3]=1;map[1][4]=2;map[1][5]=1;map[1][6]=3;map[1][7]=2;
	                        map[2][3]=1;map[2][4]=2;map[2][5]=3;map[2][6]=1;map[2][7]=2;
	                                    map[3][4]=3;map[3][5]=2;map[3][6]=2;map[3][7]=1;
	                                                map[4][5]=1;map[4][6]=1;map[4][7]=2;
	                                                			map[5][6]=2;map[5][7]=1;
	                                                						map[6][7]=1;
	 for(int i=1;i<=7;i++)
	 	for(int j=0;j<i;j++)
	 		map[i][j]=map[j][i];                     						
}
int main()
{
//	freopen("hamming.in","r",stdin);
//	freopen("hamming.out","w",stdout);

	scanf("%d%d%d",&n,&b,&d);
	cdmap();
	 part1=b%3;
	 part2=b/3;
	if(part1==0)
	{
		dg(d,0); 
	}
	if(part1==1)
	{
		dg(d,0);
		if(t<n)
		dg(d,1);
	}
	if(part1==2)
	{
		dg(d,0);
			if(t<n)
		dg(d,1);
			if(t<n)
		dg(d,2);
			if(t<n)
		dg(d,3);
	}
	if(part1!=0)
	part2++;
	for(int i=1;i<=t;i++)
	{
		int sum=0;
		for(int j=1;j<=part2;j++)
		{
			sum+=a[i][j]*pow(8,j-1);
		}
		if(i<t&&i%10!=0)
		printf("%d ",sum);
		else
		printf("%d\n",sum); 	
	}
	
	
}
 
