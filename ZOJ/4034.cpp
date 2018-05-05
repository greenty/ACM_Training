/*
	implementation problem
	Classified discussion
	see the code ...
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
int n,m;
char c;
int a[500005];
int main()
{
	int _;
	scan(_);
	while(_--)
	{
		scan(n);scan(m);
		int pos = 0;
		for(int i = 1;i<=n;i++)
		{
			scanf(" %c",&c);
			if(c!='W') 
			scan(a[i]);
			if(c == 'B') a[i] += m;
			else if(c == 'D') a[i] +=( 2*m );
			else if(c == 'W') pos = i;
		}
	//	cout<<"hh"<<endl;
		a[n+1] = 3*m+1;
		if(pos == 0)
		{
			if(a[1]>a[2])
			{
				cout<<1<<endl;
			}
			else
			cout<<3*m - n +1 <<endl;
			continue; 
		}
		else
		{
			if(pos == 1)
			{
				cout<<3*m-n+1<<endl;
				continue;
			}
			else
			{
				int ans = 0;
				if(pos == 2)
				{
					if(a[1] > a[3])
					{ 
						cout<<1<<endl;
					}
					else
					{
						cout<<a[3] - a[1]<<endl;
					}
					continue;
				}
				else
				{
					if(a[1] > a[2])
						ans = 1;
					else
						ans = (a[pos+1] - a[pos-1]-1);
					cout<<ans<<endl;
				}
			}
		}
		
	}
	
}
