/**
 *　　　　　　　　┏┓　　 　┏┓
 * 　　　　　　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　　　┃　　　　　　　┃ 　
 * 　　　　　　　┃　　　━　　 　┃
 * 　　　　　　　┃　＞　　　＜　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┃...　⌒　... 　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┗━┓　　　┏━┛
 * 　　　　　　　　　┃　　　┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃  　　　　　　
 * 　　　　　　　　　┃　　　┃
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┗━━━┓
 * 　　　　　　　　　┃　　　　　　　┣┓
 * 　　　　　　　　　┃　　　　　　　┏┛
 * 　　　　　　　　　┗┓┓┏━┳┓┏┛
 * 　　　　　　　　　　┃┫┫　┃┫┫
 * 　　　　　　　　　　┗┻┛　┗┻┛
 */ 
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
#define NM 2005
#define nm 1000005
#define pi 3.1415926535897931
using namespace std;
const int inf=1000000007;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}


int d[10][10][10][10][10],f[10][10][10][10][10];
int a[NM],b[NM],n,ans;
void up(int&x,int y){if(x>y)x=y;}


int main(){
	n=read();
	inc(i,1,n)a[i]=read(),b[i]=read();
	inc(j,1,9)inc(t1,0,9)inc(t2,0,9)inc(t3,0,9)inc(t4,0,9)d[j][t1][t2][t3][t4]=inf;
	d[1][0][0][0][0]=0;
	inc(i,1,n+1){
		inc(k,1,4)
		inc(j,1,9)inc(t1,0,9)inc(t2,0,9)inc(t3,0,9)inc(t4,0,9)if(d[j][t1][t2][t3][t4]<inf){
			if(t1)up(d[t1][0][t2][t3][t4],d[j][t1][t2][t3][t4]+abs(j-t1)+1);
			if(t2)up(d[t2][t1][0][t3][t4],d[j][t1][t2][t3][t4]+abs(j-t2)+1);
			if(t3)up(d[t3][t1][t2][0][t4],d[j][t1][t2][t3][t4]+abs(j-t3)+1);
			if(t4)up(d[t4][t1][t2][t3][0],d[j][t1][t2][t3][t4]+abs(j-t4)+1);
		}
		//inc(j,1,9)printf("%d ",d[j][0][0][0][0]);putchar('\n');
		if(i>n)break;
		inc(j,1,9)inc(t1,0,9)inc(t2,0,9)inc(t3,0,9)inc(t4,0,9)f[j][t1][t2][t3][t4]=inf;
		inc(j,1,9)inc(t1,0,9)inc(t2,0,9)inc(t3,0,9)inc(t4,0,9){
			if(!t1)up(f[a[i]][b[i]][t2][t3][t4],d[j][t1][t2][t3][t4]+abs(j-a[i])+1);
			if(!t2)up(f[a[i]][t1][b[i]][t3][t4],d[j][t1][t2][t3][t4]+abs(j-a[i])+1);
			if(!t3)up(f[a[i]][t1][t2][b[i]][t4],d[j][t1][t2][t3][t4]+abs(j-a[i])+1);
			if(!t4)up(f[a[i]][t1][t2][t3][b[i]],d[j][t1][t2][t3][t4]+abs(j-a[i])+1);
		}
		inc(j,1,9)inc(t1,0,9)inc(t2,0,9)inc(t3,0,9)inc(t4,0,9)d[j][t1][t2][t3][t4]=f[j][t1][t2][t3][t4];
	}
	ans=inf;
	inc(i,1,9)up(ans,d[i][0][0][0][0]);
	return 0*printf("%d\n",ans);
}