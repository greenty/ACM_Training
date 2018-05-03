/*
ID:greenty2
LANG:C++
TASK:preface
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int map[8][10][8];//1<<a-1,ÏµÊý,×ÖÄ¸ 
int sum[10];
void crmap(int a,int c1,int c2,int c3)
{
	map[a][1][c1]=1;
	map[a][2][c1]=2;
	map[a][3][c1]=3;
	map[a][4][c1]=1;map[a][4][c2]=1;
	map[a][5][c2]=1;
	map[a][6][c1]=1;map[a][6][c2]=1;
	map[a][7][c1]=2;map[a][7][c2]=1;
	map[a][8][c1]=3;map[a][8][c2]=1;
	map[a][9][c1]=1;map[a][9][c3]=1;
}
void createmap()
{
	crmap(1,1,2,3);
	crmap(3,3,4,5);
	crmap(5,5,6,7);
	map[7][1][7]=1;
	map[7][2][7]=2;
	map[7][3][7]=3;
}
void cl(int a)
{
	int aa=a;
	int t=-1;
//	printf("%d:\n",a);
	while(aa!=0)
	{
		t+=2;
		int k=aa%10;
//		printf("%d %d ::%d %d %d\n",t,k,map[t][k][t],map[t][k][t+1],map[t][k][t+2]);
		sum[t]+=map[t][k][t];
		sum[t+1]+=map[t][k][t+1];
		sum[t+2]+=map[t][k][t+2];  
		aa=aa/10;
	}
//	printf("\n");
//	for(int i=1;i<=7;i++)
//	{
//		printf("%d ",sum[i]);
//	} 
//	printf("\n\n");
}
int main()
{
//	freopen("preface.in","r",stdin);
//	freopen("preface.out","w",stdout);
	int n;
	scanf("%d",&n);
	createmap();
	for(int i=1;i<=n;i++)
	{
		cl(i);
	}
	if(sum[1]!=0)	printf("I %d\n",sum[1]);
	if(sum[2]!=0)	printf("V %d\n",sum[2]);
	if(sum[3]!=0)	printf("X %d\n",sum[3]);
	if(sum[4]!=0)	printf("L %d\n",sum[4]);
	if(sum[5]!=0)	printf("C %d\n",sum[5]);
	if(sum[6]!=0)	printf("D %d\n",sum[6]);
	if(sum[7]!=0)	printf("M %d\n",sum[7]);
}

