//                                                    __----~~~~~~~~~~~------___
//                                   .  .   ~~//====......          __--~ ~~
//                   -.            \_|//     |||\\  ~~~~~~::::... /~
//                ___-==_       _-~o~  \/    |||  \\            _/~~-
//        __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
//    _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
//  .~       .~       |   \\ -_    /  /-   /   ||      \   /
// /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
// |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
//          '         ~-|      /|    |-~\~~       __--~~
//                      |-~~-_/ |    |   ~\_   _-~            /\
//                           /  \     \__   \/~                \__
//                       _--~ _/ | .-~~____--~-/                  ~~==.
//                      ((->/~   '.|||' -_|    ~~-/ ,              . _||
//                                 -_     ~\      ~~---l__i__i__i--~~_/
//                                 _-~-__   ~)  \--______________--~~
//                               //.-~~~-~_--~- |-------~~~~~~~~
//                                      //.-~~~--\
//                  神兽保佑
//                代码无BUG!
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
int lt[100005];
int dt[100005];
int n,m,cl,ce,v;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>cl>>ce>>v;
	For(i,1,cl)	cin>>lt[i]; 
	For(i,1,ce)	cin>>dt[i];
	int q;cin>>q;
	int a,b,c,d;
	while(q--)
	{
		int ans = INT_MAX;
		cin>>a>>b>>c>>d;
		if(a == c)
		{
			cout<<abs(b-d)<<endl;
			continue;
		}
		int ll,rr;
		if(cl)
		{
			rr = lower_bound(lt+1,lt+cl+1,b) - lt;
			if(rr>cl || lt[rr] != b) ll= rr-1;
			else ll  = rr;
			if(ll == rr)
			{
				
				int k = abs(c-a);
				k+=abs(d-b);
				ans = ans < k ? ans : k;
			}
			else
			{
				ll = lt[ll];
				rr = lt[rr];
				if(ll > 0 && ll<=m)
				{
					
					int k = abs(b-ll);
					k+=abs(c-a);
					k+=abs(d-ll);
					ans = ans < k ? ans : k;
				//	cout<<"lt"<<" "<<ll<<" "<<k<<endl; 
				}
				if(rr>0 && rr <= m)
				{
					int k = abs(rr-b);
					k+=abs(c-a);
					k+=abs(d -rr);
					ans = ans < k ? ans : k;
				//	cout<<"lt"<<" "<<rr<<" "<<k<<endl; 
				}
				
			}
		}
		
		if(ce)
		{
			rr = lower_bound(dt+1,dt+ce+1,b) - dt;
			if(lt[rr] != b) ll= rr-1;
			else ll  = rr;
			if(ll == rr)
			{
				
				int k = abs(c-a)/v;
				if(k*v < abs(c-a)) k++;
				k+=abs(d-b);
				ans = ans < k ? ans : k;
			}
			else
			{
				ll = dt[ll];
				rr = dt[rr];
				if(ll > 0 && ll<=m)
				{
					int k = b-ll;
					int p =abs(c-a)/v;
					if(p*v< abs(c-a)) p++;
					k+=p;
					k+=abs(d-ll);
					ans = ans < k ? ans : k;
			//		cout<<"dt"<<" "<<ll<<" "<<k<<endl; 
				}
				if(rr>0 && rr <= m)
				{
					int	k = rr-b;
					int p =abs(c-a)/v;
					if(p*v< abs(c-a)) p++;
					k+=p;
					k+=abs(rr-d);
					ans = ans < k ? ans : k;//cout<<"dt"<<" "<<rr<<" "<<k<<endl; 
				}	
			}
		}
		cout<<ans<<endl;
	}
	
}