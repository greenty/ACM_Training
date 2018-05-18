/*
        A * B = 2018 * C = 2 * 1009 * C
        It means A and B's prime factors contain 2 and 1009
        For a interval,define 4 states:
        00 : The number of numbers that not contain "2" and "1009"    
        01 : The number of numbers that not contain "2" but contain "1009"
        10 : The number of numbers that not contain "1009" but contain "2"
        11 : The number of numbers that contain "2" and "1009"  
        The following combination will be no repetition and no omission:
        A  B
        00 11
        01 10
        01 11
        10 01
        10 11
        11 00
        11 01
        11 10
        11 11
        calculate the 4 states ,get the answer.
*/
#include <bits/stdc++.h>
#define inc(i,a,b) for(int i=(a); i<=(b) ; i++)
#define dec(i,a,b) for(int i=(a); i>=(b) ; i--)
#define Memset(a,b); memset((a),(b),sizeof((a)));
using namespace std;
template <class T> inline void print(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else wt(x / 10), putchar(x % 10 + '0');}
template <class T> inline void scan(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;

LL a,b,c,d;
LL x[2][2],y[2][2];
LL js(int p,int q,int c)
{
        return (q/c)*1LL - ((p-1) / c)*1LL;
}
int main()
{
        ios::sync_with_stdio(false);
        while(cin>>a>>b>>c>>d)
        {
                x[1][1] = js(a,b,2018);
                x[1][0] = js(a,b,2) - x[1][1];
                x[0][1] = js(a,b,1009) - x[1][1];
                x[0][0] = b-a+1 - x[1][1] - x[0][1] - x[1][0];
                
                y[1][1] = js(c,d,2018);
                y[1][0] = js(c,d,2) - y[1][1];
                y[0][1] = js(c,d,1009) - y[1][1];
                y[0][0] = d-c+1 - y[1][1] - y[0][1] - y[1][0];
                LL ans = 0;
                ans+=x[0][0] * y[1][1];
                ans+=x[0][1] * y[1][0];
                ans+=x[0][1] * y[1][1];
                ans+=x[1][0] * y[0][1];
                ans+=x[1][0] * y[1][1];
                ans+=x[1][1] * y[0][0];
                ans+=x[1][1] * y[0][1];
                ans+=x[1][1] * y[1][0];
                ans+=x[1][1] * y[1][1];
                cout<<ans<<endl;
        }
}