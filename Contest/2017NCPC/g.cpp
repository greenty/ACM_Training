#include <bits/stdc++.h>
const int MAXN=1e5+10;
using namespace std;
typedef struct node{
	int id,ti,fa;
	friend bool operator<(node aa,node bb){
		if(aa.t1!=bb.t1)return aa.t1>bb.t1;
		if(aa.fa!=bb.fa)return aa.fa<bb.fa;
		return aa.id<bb.id;
	}
}node;
node d[MAXN];
set<node>s;
typedef struct nod{
	int f,s;
}nod;
nod a[MAXN];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i].f=0,a[i].s=0;
	int pos,vul;node ttt;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&pos,&vul);
		ttt.id=pos;ttt.ti=a[pos].f;ttt.fa=a[pos].s;
		s.erase(s.find(ttt));
		ttt.ti++;ttt.fa+=vul;a[pos].f++;a[pos].s+=vul;
		s.insert(ttt);
		ttt.id=1;ttt.ti=a[1].f;ttt.fa=a[1].s;
		int ans=s.lower_bound(ttt)-s.begin();
	}
	return 0;
}
