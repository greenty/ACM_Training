#include <bits/stdc++.h>
#define ll long long
const int MAXN=1e6+10;
using namespace std;
vector<int>vec;
vector<int>vv[MAXN];
int nex[MAXN];
int a[MAXN];
void intx(){
	int len=vec.size();int i=0,j=-1;
	nex[0]=-1;
	while(i<len){
		if(j==-1||vec[i]==vec[j]){
		 nex[++i]=++j;
		}
		else j=nex[j];
	}
}
int kmp(int pos){
	int i=0;int j=0;int len1=vv[pos].size();
	int len2=vec.size();
	if(len1<len2)return 0;
	int ans=0;
	while(i<len1){
		if(j==-1||vv[pos][i]==vec[j]) i++,j++;
		else j=nex[j];
		if(j>=len2)ans++,j=nex[j];
	}
	return ans;
}
int main(){
	int _;scanf("%d",&_);int Case=0;
	while(_--){
		int n,m,p;scanf("%d%d%d",&n,&m,&p);
		int t;memset(nex,0,sizeof(nex));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&t),vec.push_back(t);
		for(int i=1;i<=p;i++){
			vv[i].push_back(a[i]);
			for(int j=p+i;j<=n;j+=p){
				vv[i].push_back(a[j]);
			}
		}
		intx();int ans=0;
		for(int i=1;i<=min(p,n);i++){
			ans+=kmp(i);
		}
		printf("Case #%d: ",++Case);
		printf("%d\n",ans);
		vec.clear();
		for(int i=1;i<=p;i++)vv[i].clear();
	}
	return 0;
}
