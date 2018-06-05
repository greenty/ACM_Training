#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i++)
#define link(x) for(edge*j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define succ(x) (1<<(x))
#define sqr(x) ((x)*(x))
#define lowbit(x) (x&(-x))
#define eps 1e-8
#define pi 3.1415926
#define NM 1005
#define nm 1000005
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}


struct edge{int t;edge*next;}e[nm],*h[NM],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int n,m,a[NM],b[NM],c[NM],d[NM],match[NM],v[NM],s,_x;
char aa[NM][10],bb[NM][10];

bool dfs(int x){
	link(x)if(v[j->t]!=_x){
		v[j->t]=_x;
		if(!match[j->t]||dfs(match[j->t])){match[j->t]=x;return true;}
	}
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();m=read();
	inc(i,1,n){
		scanf("%s",aa[i]);
		inc(j,0,2)a[i]+=aa[i][j]-'0';
		inc(j,3,5)b[i]+=aa[i][j]-'0';
	}
	inc(i,1,m){
		scanf("%s",bb[i]);
		inc(j,0,2)c[i]+=bb[i][j]-'0';
		inc(j,3,5)d[i]+=bb[i][j]-'0';
	}
	inc(i,1,n)inc(j,1,m)if(a[i]==d[j]||b[i]==c[j])add(i,j);
	inc(i,1,n)if(dfs(_x=i))s++;
	printf("%d\n",s);
	inc(i,1,m)if(match[i])if(d[i]==a[match[i]])printf("AT %s %s\n",aa[match[i]],bb[i]);else printf("TA %s %s\n",bb[i],aa[match[i]]);
	return 0;
}
