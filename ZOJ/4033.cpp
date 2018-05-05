/*
	This is a greedy prolem
	G1+G3 = G2+G4
	tot = n*(n+1) / 2 = G1+G2+G3+G4 = (G1+G3)*2 ,it means it has valid answer only if n%4 == 0 or n%4 == 3
	Classified discussion
	put G1 ,G3 on the left,G2,G4 on the right
	if n%4 == 0
	we had konwn 1+n = 2+(n-1) = 3+(n-2)... we can make pair, satisfied every pairs sum are equal (<1,n>¡¢<2,n-1> ....) 
	then we could put each pair left ,right,left,right....
	else if n%4 == 3
	we can let lastest integer be a separate group,then make pair (<1,n-1>,<2,n-2>  .... ),then left,right,left,right.... 
	
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
string s; 
int a[100005];
int main()
{
	scan(_);
	while(_--)
	{
		scan(n);
		cin>>s;
		if(n%4 == 0)
		{
			for(int i = 1;i<=n/2;i++)
			{
				if(i%2)
				{
					if(s[i-1] == '0') a[i-1] = 1;else a[i-1] = 3;
					if(s[n-i] == '0') a[n-i] = 1;else a[n-i] = 3;
				}
				else
				{
					if(s[i-1] == '0') a[i-1] = 2;else a[i-1] = 4;
					if(s[n-i] == '0') a[n-i] = 2;else a[n-i] = 4;
				}
			}
			for(int  i = 0;i<n;i++) cout<<a[i];
			cout<<endl;
		}	
		else if(n%4 == 3)
		{
			for(int i = 1;i<=n/2;i++)
			{
				if(i%2)
				{
					if(s[i-1] == '0') a[i-1] = 1;else a[i-1] = 3;
					if(s[n-i-1] == '0') a[n-i-1] = 1;else a[n-i-1] = 3;
				}
				else
				{
					if(s[i-1] == '0') a[i-1] = 2;else a[i-1] = 4;
					if(s[n-i-1] == '0') a[n-i-1] = 2;else a[n-i-1] = 4;
				}
			}
			if(s[n-1] == '0') a[n-1] = 2;
			else a[n-1] = 4;
			for(int i = 0;i<n;i++)
			cout<<a[i];
			cout<<endl;
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
}
