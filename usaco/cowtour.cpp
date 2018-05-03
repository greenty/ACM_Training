/*
ID: greenty2
PROG: cowtour
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
int x[155],y[155];
int n;
int maps[155][155];
double all_dis[155][155],dis[155][155];
double far[155];
double get_dis(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main()
{
	 freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	 char c;
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		scanf(" %c",&c);
	 	//3	cout<<i<<" "<<j<<" "<<c<<endl;
	 		maps[i][j]=c-'0';
	 	}
	 }
	 
	 for(int i=1;i<n;i++)
	 {
	 	maps[i][i]=1;
	 	for(int j=i+1;j<=n;j++)
	 	{
	 		all_dis[i][j]=get_dis(i,j);
	 		if(maps[i][j])
	 			dis[i][j]=all_dis[i][j];
	 		else
	 			dis[i][j]=INF;
	 		dis[j][i]=dis[i][j];
	 	}
	 }
	
	 floyd(); 
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=1;j<=n;j++)
	 	{
	 		if(dis[i][j]<INF)
	 		{
	 			far[i]=max(far[i],dis[i][j]);
	 		}
	 	}
	 }
	 
	 double ans=INF;
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=i+1;j<=n;j++)
	 	{
	 			if(maps[i][j]==0&&dis[i][j]==INF)
	 			{
	 			double now=far[i]+all_dis[i][j]+far[j];
	 			if(now>=ans)
	 				continue;
	 			for(int k=1;k<=n;k++)
					now=max(now,far[k]);
            		ans=now;
            	}
	 	}
	 	
	 }
	 printf("%.6lf\n",ans);
}

