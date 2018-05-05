/*
	greedy problem
	if a>b c>d
	we can prove a*c + b*d > a*d + b*c   
	sort by (f >,s <)
	choose the first m element,caltulate ans
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
struct cre{
	string s;
	LL f;
}a[105];
int n,m;
bool cmp(cre x,cre y)
{
	if(x.f == y.f) return x.s < y.s;
	return x.f > y.f;
}
int main()
{
	int _;scan(_);
	while(_--)
	{
		scan(n);scan(m);
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].s;
			scan(a[i].f);
		}
		sort(a+1,a+n+1,cmp);
		LL ans = 0LL;
		for(int i = 1;i<=m;i++)
		{
			ans+=(a[i].f * (m-i+1));
		
		}
		cout<<ans<<" ";
		for(int i =1;i<m;i++)
		{
			cout<<a[i].s<<" ";
		}
		cout<<a[m].s<<endl;
	}
}
