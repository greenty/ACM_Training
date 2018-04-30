#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<list>
#define For(i,a,b) for(int i=(a); i<=(b) ; i++)
#define _For(i,a,b) for(int i=(a); i>=(b) ; i--)
#define Memset(a,b); memset((a),(b),sizeof((a)));
using namespace std;
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;
inline LL CinLL(){LL x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int Cin(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return f*x;}
LL n,m,r;
LL a[100005];
LL sum[100005];
LL _sum[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>m>>r;
	For(i,1,n) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	_For(i,n,1) sum[i] = sum[i+1] + a[i];
	For(i,1,n) _sum[i] = sum[n-i+1];
	int ans = 1000000;
	for(int i = 1;i<=n-1;i++)
	{

			double p =( m*a[i] - r*a[i] )*1.0 / r;
			int pp = p;
		//	cout<<"pp = "<<pp<<endl;
			int j = lower_bound(_sum+1,_sum+n+1,pp) - _sum;
			if(_sum[j] > pp || j > n) j--;
			if(j == 0)
			{
				ans = ans < n-1 ? ans:n-1;
			}
			j = n-j+1;
			if(j>i)
			{
				ans = ans < (j-i-1)+(i-1) ? ans : (j-i-1)+(i-1);
			}
			else
			{
				ans = ans < i-1 ? ans : i-1;
			}
	}
	else
	cout<<ans<<endl;

}