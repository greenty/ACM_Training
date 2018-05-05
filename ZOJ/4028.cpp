/*
	if f[k1] == f[k2] == f[k3]... :a[k1] >= a[k2] >=a[k3]
	 if f[x] = c and f[y] = c-1 exist ,the left nearby y(y<x) must satisfy a[y] < a[x]  
	 growp fx by integer size,update ax layer by layer 
*/
#include<bits/stdc++.h>
#define inc(i,a,b) for(int i=(a); i<=(b) ; i++)
#define dec(i,a,b) for(int i=(a); i>=(b) ; i--)
#define Memset(a,b); memset((a),(b),sizeof((a)));
using namespace std;
template <class T> inline void wt(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else wt(x / 10), putchar(x % 10 + '0');}
template <class T> inline void scan(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;
vector<int>vec[100005];
int _;
int n;int m = 0;
int l[100005];
int r[100005];
void csh()
{
	Memset(l,0);
	Memset(r,0);
	for(int i = 1;i<=m;i++)
	{
		vec[i].clear();
	}
	m = 0;
}
int main()
{
	scan(_);
	while(_--)
	{
		scan(n);
		int x;
		for(int i = 1;i<=n;i++)
		{
			scan(x);
			m = m > x ? m : x;
			vec[x].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			scan(l[i]);scan(r[i]);
		}
		
		for(int i = m;i>=2;i--)
		{
			int Max = 0x7fffffff;
			for(int j = 0;j<vec[i].size();j++)
			{
				int now = vec[i][j];
				r[now] = Max < r[now] ? Max : r[now];
				Max = r[now];
				int loc = lower_bound(vec[i-1].begin(),vec[i-1].end(),now) - vec[i-1].begin();
				if(loc > 0)
				{
					loc --;
					int nex = vec[i-1][loc];
					r[nex] = r[nex] < r[now]-1 ? r[nex] : r[now]-1;
				}  
			}	
		}
		int Max = 0x7fffffff;
	//	cout<<Max<<endl;
		for(int j = 0;j<vec[1].size();j++)
		{
			int now = vec[1][j];
			r[now] = Max < r[now] ? Max : r[now];
			Max = r[now];
		}
		for(int i = 1;i<n;i++)
		{
			wt(r[i]);
			putchar(' ');
		}
		wt(r[n]);
		putchar('\n');
		csh();
	}
}
