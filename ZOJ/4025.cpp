/*
	let c[i] = s[i] - d[i];
	if we change the K,c[i] change will k
	so we can count the largest number of same integers,it is the answer.
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
int _;
int n;
int d[100005];
int s[100005];
int main()
{
	scan(_);
	while(_--)
	{
		scan(n);
		for(int i = 1;i<=n;i++) scan(d[i]);
		for(int i = 1;i<=n;i++)
		{
			 scan(s[i]);
			 s[i] = s[i] - d[i];
		}
		sort(s+1,s+n+1);
		int ans = 0;
		int count = 1;
		for(int i = 2;i<=n;i++) 
		{
			if(s[i]!=s[i-1])
			{
				ans = ans > count ? ans:count;
				count = 0;
			}
			count++;
		}
		ans = ans > count ? ans:count;
		count = 0;
		cout<<ans<<endl;
	}
}
