/*
ID:greenty2
LANG:C++
TASK:castle
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
//int wall[10][5];
int book[55][55];
int bj[55][55]; 
int map[55][55];
int n,m;
int era[2505],maxera=0;
int max2era=0;
int t=0;
int w1,w2;
/*void createwall()
{
	wall[1][1]=0;wall[1][2]=0;wall[1][3]=1;wall[1][4]=0;
	wall[2][1]=0;wall[2][2]=0;wall[2][3]=0;wall[2][4]=1;
	wall[4][1]=1;wall[4][2]=0;wall[4][3]=0;wall[4][4]=0;
	wall[8][1]=0;wall[8][2]=1;wall[8][3]=0;wall[8][4]=0;
}*/
void fill(int x,int y)
{
	
	int k[10];
	int p=map[x][y];
	memset(k,0,sizeof(k));
	if(p>=8)
	{
		k[8]=1;
		p-=8;
	}
	if(p>=4)
	{
		k[4]=1;
		p-=4;
	}
	if(p>=2)
	{
		k[2]=1;
		p-=2;
	}
	if(p>=1)
	{
		k[1]=1;
		p-=1;
	}
//	printf("%d(%d,%d)::西：%d 北：%d 东：%d 南%d\n",map[x][y],x,y,k[1],k[2],k[4],k[8]);
	if(k[4]==0)
	{
		if(y<m&&book[x][y+1]==0)
		{
			era[t]++;
			book[x][y+1]=t;
			fill(x,y+1); 
		}
	}
	if(k[8]==0)
	{
		if(x<n&&book[x+1][y]==0)
		{
			era[t]++;
			book[x+1][y]=t;
			fill(x+1,y);
		}
	}
	if(k[2]==0)
	{
		if(x>1&&book[x-1][y]==0)
		{
			era[t]++;
			book[x-1][y]=t;
			fill(x-1,y); 
		}
	}
	if(k[1]==0)
	{
		if(y>1&&book[x][y-1]==0)
		{
			era[t]++;
			book[x][y-1]=t;
			fill(x,y-1);
		}
	}
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	//createwall();

	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(book[i][j]==0)
			{
				
				t++;
				era[t]=1;
				book[i][j]=t;
				fill(i,j);
				if(era[t]>maxera)
				maxera=era[t];
				
			}
		}
			
	}
/*	for(int ii=1;ii<=n;ii++)
				{
							for(int jj=1;jj<=m;jj++)
			{
				printf("%d ",book[ii][jj]);
				}
				printf("\n");
				}
				//printf("------------------------------------\n");*/
	printf("%d\n",t);
	printf("%d\n",maxera);
	for(int j=1;j<=m;j++)
	{
		for(int i=n;i>=1;i--)
		{
			if(i>1)
			if(book[i][j]!=book[i-1][j])
			{
				int t=era[book[i][j]]+era[book[i-1][j]];
				if(max2era<t)
				{
					w1=book[i][j];
					w2=book[i-1][j];
					max2era=t;
				}
			}
			if(j<m)
			if(book[i][j]!=book[i][j+1])
			{
				int t=era[book[i][j]]+era[book[i][j+1]];
				if(max2era<t)
				{
					w1=book[i][j];
					w2=book[i][j+1];
					max2era=t;
				}
			}
			
		}
		
	}
	printf("%d\n",max2era);
	//printf("ww%d %d\n",w1,w2);
/*	int xx=0,yy=0,tt=0;
	int flag=0;
	for(int j=1;j<m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(book[i][j])
			if((book[i][j]==w1&&book[i][j+1]==w2) || (book[i][j]==w2&&book[i][j+1]==w1))
			{
				
				flag=1;
				tt++;
				xx+=i;
				yy=j;	
			}
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==1)
	{
		int kk=xx/tt;
		if(xx%tt!=0)
		kk++;
		printf("%d %d E\n",kk,yy);
		return 0;
	}
	xx=0,yy=0,tt=0;
	for(int i=n;i>1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if((book[i][j]==w1&&book[i-1][j]==w2) || (book[i][j]==w2&&book[i-1][j]==w1))
			{
				
				flag=1;
				tt++;
				xx=i;
				yy+=j;	
			}
		}
		if(flag==1)
		break;
	}*/
	//printf("%d %d \n",xx,yy/tt);
	int flag=0;
	int xx,yy;
	for(int j=1;j<=m;j++)
	{
		for(int i=n;i>=1;i--)
		{
			if((book[i][j]==w1&&book[i-1][j]==w2) || (book[i][j]==w2&&book[i-1][j]==w1))
			{
				
				flag=1;
				xx=i;
				yy=j;
				break;
			}
			if(j<m)
			if((book[i][j]==w1&&book[i][j+1]==w2) || (book[i][j]==w2&&book[i][j+1]==w1))
			{
				
				flag=2;
				//tt++;
				xx=i;
				yy=j;
				break;	
			}
		}
		if(flag>0)
		{
			break;
		}
	}
	if(flag==1)
	{
		printf("%d %d N\n",xx,yy);
	}
	if(flag==2)
	{
		printf("%d %d E\n",xx,yy);
	}
	
}

