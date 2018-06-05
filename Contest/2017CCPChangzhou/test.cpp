#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge*j=h[x];j;j=j->next)
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define succ(x) (1<<(x))
#define NM 1005
#define nm 100005
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const ll inf=998244353;


vector<int>b[NM];
int n,m,a[nm],d[nm],_x,_y,_t,tot;
ll c[NM][NM];
int trunc(int x,int y){
	if(x>=0)return x/y;
	if(x%y==0)return x/y;
	return x/y-1;
}

int main(){
	int _=read();while(_--){
		n=read();m=read();tot=1000;
		inc(i,1,n)a[i]=read();
		inc(i,1,n)b[a[i]].push_back(d[i]=read());
		inc(i,1,tot){
			inc(j,0,i-1){
				int t=b[i].size();
				inc(k,0,t-1)c[i][j]+=trunc(j-b[i][k],i);
			}
		}
		while(tot--){
			_t=read();_x=read();
			if(_t==3){
				ll ans=0;
				inc(i,1,tot)ans+=_x/i+c[i][_x%i];
				printf("%lld\n",ans);
			}else if(_t==2){
				_y=read();
				int t=b[a[_x]].size()-1;
				inc(i,0,t)if(b[a[_x]][i]==d[_x]){
					int _t=b[a[_x]][i];
					inc(j,0,i-1)c[i][j]=c[i][j]-trunc(j-_t,i)+trunc(j-_y,i);
					b[a[_x]][i]=_y;
					break;
				}
			}else if(_t==1){
				_y=read();
				int t=b[a[_x]].size()-1;
				for(auto x = b[a[_x]].begin();x != b[a[_x]].end();x++ ){
					if((*x)==d[_x])b[a[_x]].erase(x);
					break;
				}
				a[_x]=_y;
			}
		}
	}
	return 0;
}
