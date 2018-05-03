/*
ID:greenty2
LANG:C++
TASK:comehome
*/
#include<bits/stdc++.h>
using namespace std;
int map1[100][100];
int book[30];
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	int n;
	//cout<<'z'-'A';
	cin>>n;
	char a,b;
	int k,x,y;int m='z'-'A'+1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			map1[i][j]=99999999;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>k;
		if(a<='Z')
		book[a-'A'+1]=1;
		if(b<='Z')
		book[b-'A'+1]=1;
		x=a-'A'+1;
		y=b-'A'+1;
		
		map1[x][y]=min(k,map1[x][y]);
		map1[y][x]=min(k,map1[y][x]);
	//	cout<<x<<" "<<y<<" "<<k<<endl;
	}
	 for(int k=1;k<=m;k++)
	 {
	 	for(int i=1;i<=m;i++)
	 	{
	 		for(int j=1;j<=m;j++)
	 		{
	 			if(map1[i][k]+map1[k][j]<map1[i][j])
	 			{
	 				map1[i][j]=map1[i][k]+map1[k][j];
	 			}
	 		}
	 	}
	 }
	 int p='Z'-'A'+1;
	 int min=99999999;
	 char minx=0; 
	 //cout<<map1[1][26]<<endl;
	 for(int i=1;i<26;i++)
	 { 
	// 	cout<<map1[i][p]<<endl; 
	 	if(min>map1[i][p])
	 	{
	 //		cout<<"hhh"<<endl;
	 		min=map1[i][p];
	 		minx='A'+i-1;
	 	}
	 } 
	 cout<<minx<<" "<<min<<endl;
	 
}
