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
#define inc(i,a,b) for(int i=(a); i<=(b) ; i++)
#define dec(i,a,b) for(int i=(a); i>=(b) ; i--)
#define Memset(a,b); memset((a),(b),sizeof((a)));
using namespace std;
template <class T> inline void print(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else print(x / 10), putchar(x % 10 + '0');}
template <class T> inline void scan(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;
int a[200005],dp[200005],n;
int pre[200005];
map<int,int>mp;
int main( )
{
	cin>>n;
	for( int i=1;i<=n;i++) scan( a[i]);
	dp[1] = 1;
	mp[a[1]] = 1;
	int len = 1;
	pre[n+1] = 1;
	int maxlen = 1;
	for( int i = 2;i<=n;i++)
	{
		mp[a[i]] = i;
		if( mp.find( a[i]-1)!=mp.end( ))
		{
			int j = mp[a[i]-1];
			dp[i] = dp[j]+1;
			pre[i] = j;
			if( dp[i]>maxlen)
			{
				maxlen = dp[i];
				pre[n+1] = i;
			}
		}
		else
		{
			dp[i] = 1;
		}
	}
	int ans = 0;
	int now = n+1;
	vector<int>vec;
	while( pre[now]!=0)
	{
		now = pre[now];
		vec.push_back(now);
		ans++;
	}
	print( ans);
	puts( "");
	for( auto it = vec.rbegin( );it!=vec.rend( );it++)
	{
		int c = *it;
		print( c);putchar( ' ');
	}
	puts( "");
}


/*
 * Tutorial
 * map<x,y>数字x出现的位置Y
 * a[] 给定数组
 * dp[i] 以第i个字符结尾的最长长度
 * pre[i] 第i个字符的前一个字符（模拟链表）
 *
 * 初始化
 * dp[1] = 1;
 * mp[a[1]] =1;
 * maxlen = 1;
 * pre[n+1] = 1; 相当于头指针
 * for( i：2	~ n)
 *	每次把最新的值扔进map里，找a[i]-1 是否存在
 *	如果存在，那就把他的pre指向map映射的位置j，dp[i] = dp[j]+1 并且判断一下dp[i]是不是大于maxlen,是就更新maxlen，并把头指针指向他 pre[n+1] = i;
 * 如果不存在 那就dp[i] = 1;
 * 最后答案就从n+1 沿着pre往前找
 * */

