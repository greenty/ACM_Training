/*
ID:greenty2
LANG:C++
TASK:ratios
*/
#include<bits/stdc++.h>
using namespace std;
int x[5],y[5],z[5];
/*int ss(int a,int b)
{
	if(a%b==0)
	return b;
	else
	return ss(b,a%b);
}
int gcd(int a,int b,int c)
{
	if(a<b)
    	swap(a,b);
    if(a<c)
    	swap(a,c);
    if(b<c)
    	swap(b,c);
    int m=a*b*c;
    int c1=ss(a,c);
    int c2=ss(b,c);
    int e=ss(c1,c2);
    return e;
}*/
int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	int X,Y,Z;
	cin>>X>>Y>>Z;
	//int p=gcd(X,Y,Z); 
	//cout<<p<<endl;
	//X/=p;Y/=p;Z/=p;
	for(int i=1;i<=3;i++)
	{
		cin>>x[i]>>y[i]>>z[i];	
	}
	int flag=0;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int k=0;k<=100;k++)
			{
				if(i==0&&j==0&&k==0)
				continue;
				int xx=i*x[1]+j*x[2]+k*x[3];
				int yy=i*y[1]+j*y[2]+k*y[3];
				int zz=i*z[1]+j*z[2]+k*z[3];
				double xxx=-1,yyy=-1,zzz=-1;
				if(xx!=0&&X!=0&&xx>=X)
				{
					xxx=1.0*xx/X;
				} 
				else if(xx==0&&X==0)
				{
					xxx=0;	
				}
				if(yy!=0&&Y!=0&&yy>=Y)
				{
					yyy=1.0*yy/Y;
				} 
				else if(yy==0&&Y==0)
				{
					yyy=0;	
				}
				if(zz!=0&&Z!=0&&zz>=Z)
				{
					zzz=1.0*zz/Z;
				}
				else if(zz==0&&Z==0)
				{
					zzz=0;
				}
			//	if(i==0&&j==2&&k==1)
				//{
				//	cout<<xx<<" "<<yy<<" "<<zz<<" "<<Z<<endl;
			//		cout<<xxx<<" "<<yyy<<" "<<zzz<<endl;
				//} 
				if(xxx==-1||yyy==-1||zzz==-1)
				continue;
				if(xxx==0)
					if(yyy!=0)
					xxx=yyy;
					else
					xxx=zzz;
				if(yyy==0)
					if(zzz!=0)
					yyy=zzz;
					else
					yyy=xxx;
				if(zzz==0)
					if(xxx!=0)
					zzz=xxx;
					else
					zzz=yyy;
			//	if(i==0&&j==2&&k==1)
				//{
				//	cout<<xx<<" "<<yy<<" "<<zz<<" "<<Z<<endl;
			//		cout<<xxx<<" "<<yyy<<" "<<zzz<<endl;
				//} 
				if(xxx==yyy&&yyy==zzz)
				{
					cout<<i<<" "<<j<<" "<<k<<" "<<xxx<<endl;
					flag=1; 
				}
				if(flag==1)
				break;
				
			}
			if(flag==1)
				break;
		}
		if(flag==1)
				break;
	}
	if(flag==0)
	{
		cout<<"NONE"<<endl; 
	}
} 
