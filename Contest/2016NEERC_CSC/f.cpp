#include <bits/stdc++.h>
#define link(x) for(edge*j=h[x];j;j=j->next)
const int MAXN=1e3+10;
#define nm 2000005
int fa[MAXN];
using namespace std;
struct edge{int t;edge*next;}e[nm],*h[MAXN],*o=e;
void add(int x,int y){o->t=y;o->next=h[x];h[x]=o++;}
int find1(int x){
	if(x==fa[x])return x;
	return fa[x]=find1(fa[x]);
}
int du[MAXN];
queue<int>que;
bool flag;
int ans[MAXN],du1[MAXN];
void dfs(int v,int num){
	if(flag)return ;
	if(num>=2){
		flag=1;return ;
	}
	link(v)dfs(j->t,num+1);
}
typedef struct node{
	int u,v;
}node;
node d[nm];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i,ans[i]=-1;
	int u,v;char ch;int cnt=0;
	for(int i=1;i<=m;i++){
		scanf("%d%c%d",&u,&ch,&v);
		//printf("%d %c %d\n",u,ch,v);
		if(ch=='='){
			int t1=find1(u);int t2=find1(v);
			if(t1==t2)continue;
			if(t1>t2)swap(t1,t2);
			fa[t2]=t1;
			continue;
		}
		if(ch=='<'){
			d[++cnt].u=u;d[cnt].v=v;
			//du[v]++;du1[u]++;vec[u].push_back(v);
		}
 		else{
			d[++cnt].u=v;d[cnt].v=u;
		}
	}
	for(int i=1;i<=cnt;i++){
		int t1=find1(d[i].u);int t2=find1(d[i].v);
		add(t1,t2);
		du[t2]++;du1[t1]++;
	}
	for(int i=1;i<=n;i++){
		if(!du[i]){
			flag=0;dfs(i,0);
			if(flag) que.push(i),ans[i]=0;
		}
	}
	while(!que.empty()){
		int t=que.front();que.pop();
		link(t){
			if(ans[j->t]>=0&&ans[j->t]<=2)continue;
			if(du1[j->t]>0){
				ans[j->t]=1;
				int k=j->t;
				link(k)ans[j->t]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]<0||ans[i]==3){
		//	cout<<i<<"==== "<<find1(i)<<endl;
			ans[i]=ans[find1(i)];
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0)printf("B");
		else if(ans[i]==1)printf("R");
		else if(ans[i]==2)printf("W");
		else printf("?");
	}
	puts("");
	return 0;
}
