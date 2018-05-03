	/*
ID: greenty2
PROG: fracdec
LANG: C++
*/
	#include<bits/stdc++.h>
	using namespace std;
	int book[100][100000];
	int pos[100]; 
	int p1[100005];
	int p2[100005];
	int main()
	{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);	
		int a,b;
		cin>>a>>b;
		int ans1=a/b;int t=0;
		p1[++t]=b;
		p2[t]=a;
		pos[b]++; 
		book[b][pos[b]]=a;
		a=a%b;
		int flag=1;
		int d;
		if(a==0)
		{
			cout<<ans1<<".0"<<endl;
			return 0;
		}
		
		while(1)
		{
			
			
		//	system("pause");
			int x=a*10/b;
			p1[++t]=x;
			a=a*10%b;
			p2[t]=a;
		//	cout<<x<<" "<<a<<endl;/////////////
			int flag2=0;
			if(a==0)
			{
				flag=0;
				break;
			}
		
			for(int i=1;i<=pos[x];i++)
			{
				if(book[x][i]==a)
				{
					flag2=1;
					break;
				}
			}
			if(flag2==1)
			{
				for(int i=1;i<=t;i++)
				{
					if(p1[i]==x&&p2[i]==a)
					{
						d=i;
						goto stop;
					}
				}
			}
			
			pos[x]++; 
			book[x][pos[x]]=a;
			
		}
		stop:
			cout<<ans1<<".";
			if(flag==0)
			{
				for(int i=2;i<=t;i++)
				{
					cout<<p1[i];
				}
				cout<<endl;
				return 0;
			}
			else
			{
				for(int i=2;i<d;i++)
				{
					cout<<p1[i];
				}
				cout<<"(";
				int dd=d;
				if(d<2)
				dd=d+1; 
				for(int i=dd;i<t;i++)
				{
					cout<<p1[i];
				}
				if(d<2)
				cout<<p1[d];
				cout<<")"<<endl;
			}
	}
