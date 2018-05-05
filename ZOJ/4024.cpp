/*
	water problem
	find the bigest number's id :loc
	if id == 1 or id == n  No
	else
	force to judge wether 1 ~ loc strictly increasing and loc ~ n strictly decreasing
*/
#include<bits/stdc++.h>
#define inc(i,a,b) for(int i=(a); i<=(b) ; i++)
#define dec(i,a,b) for(int i=(a); i>=(b) ; i--)
#define Memset(a,b); memset((a),(b),sizeof((a)));
using namespace std;
template <class T> inline void print(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else wt(x / 10), putchar(x % 10 + '0');}
template <class T> inline void scan(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;
int n;
int a[100005];
int main()
{
	int _;
	scan(_);
	while(_--)
	{
		scan(n);
		for(int i = 1;i<=n;i++) scan(a[i]);
		int maxx = 0,maxid;
		for(int i = 1;i<=n;i++)
		{
			if(maxx < a[i])
			{
				maxx = a[i];
				maxid = i;
			}
		}
	//	cout<<maxid<<endl;3
		if(maxid == 1 || maxid == n)
		{
			cout<<"No"<<endl;
		}
		else
		{
			int flag = 0;
			for(int i = 1;i<=maxid;i++)
			{
				if(a[i]<=a[i-1]) 
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				for(int i = maxid;i<n;i++)
				{
					if(a[i]<=a[i+1])
					{
						flag = 1;
						break;
					}
				}
			}
			if(flag == 0)
			{
				cout<<"Yes"<<endl;
			}
			else
			cout<<"No"<<endl;
		}
	}
}
