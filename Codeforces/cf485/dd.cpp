#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define eps 1e-12
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid (x+y>>1)
#define NM 500005
#define nm 500005
#define pi 3.1415926535897931
const ll inf=1000000007;
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}


struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int n,m,w,p,a[NM],_x,_y,d[NM][105];
queue<int>q;
ll s;

int main(){
    n=read();m=read();p=read();w=read();
    inc(i,1,n)a[i]=read();
    inc(i,1,m){_x=read();_y=read();add(_x,_y);add(_y,_x);}
    inc(k,1,p){
	inc(i,1,n)if(a[i]==k)q.push(i),d[i][k]=1;
	while(!q.empty()){
	    int t=q.front();q.pop();
	    link(t)if(!d[j->t][k])d[j->t][k]=d[t][k]+1,q.push(j->t);
	}
    }
    inc(i,1,n){
	s=0;
	sort(d[i]+1,d[i]+1+p);
	//inc(j,1,p)printf("%d ",d[i][j]);putchar('\n');
	inc(j,1,w)s+=d[i][j]-1;
	printf("%I64d ",s);
    }
    return 0;
}
