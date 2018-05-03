/*
ID:greenty2
LANG:C++
TASK:ttwo 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char map[11][11];
bool book[11][11][5][11][11][5];
void move(int &s,int &t,int &d)
{
	if(d==1)
	{
		if(s-1>=1&&map[s-1][t]!='*')
		{
			s--;
		}
		else
		{
			d++;
			
		}
		return ;
	}
	if(d==2)
	{
		if(t+1<=10&&map[s][t+1]!='*')
		{
			t++;
		}
		else
		{
			d++;
		}
		return ;
	}
	if(d==3)
	{
		if(s+1<=10&&map[s+1][t]!='*')
		{
			s++;
		}
		else
		{
			d++;
		}
		return ;
	}
	if(d==4)
	{
		if(t-1>=1&&map[s][t-1]!='*')
		{
			t--;
		}
		else
		{
			d=1;
		}
		return ; 
	}
}
int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	int s1,t1,s2,t2;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			scanf(" %c",&map[i][j]);
			
			
		} 
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(map[i][j]=='F')
			{
				s1=i;
				t1=j;
			}
			if(map[i][j]=='C')
			{
				s2=i;
				t2=j;
			}
		}
	}
	int d1=1,d2=1;
	book[s1][t1][d1][s2][t2][d2]=true;
	int ans=0;
	int flag=0;
	while(s1!=s2||t1!=t2)
	{
		ans++;
		move(s1,t1,d1);
		move(s2,t2,d2);
	//	printf("%d::\n%d %d %d \n\n",ans,s1,t1,d1);
		//system("pause");
		if(book[s1][t1][d1][s2][t2][d2]==false)
		{
			book[s1][t1][d1][s2][t2][d2]=true;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("0\n");
	else
	printf("%d\n",ans);
	
}

