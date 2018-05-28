#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge*j=h[x];j;j=j->next)
#define ll long long
#define mem(a) memset(a,0,sizeof(a))
#define sqr(x) ((x)*(x))
#define mid (x+y>>1)
#define succ(x) (1<<x)
#define lowbit(x) (x&(-x))
#define pi 3.1415926
#define NM 505
#define nm 1000005
using namespace std;
const int inf=100000007;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int n,m,d[NM][NM],ans;
string s,str[NM];
int _x,_y;
map<string,int>v;


void dfs(int x,int y){
	if(x==y)return;
	inc(k,1,n)if(d[x][y]==d[x][k]+d[k][y]){
		dfs(x,k);
		cout<<str[k]<<' ';
		dfs(k,y);
		return;
	}
}


int main(){
	n=read();ans=inf;
	inc(i,1,n)inc(j,1,n)d[i][j]=inf;
	inc(i,1,n){
		cin>>s;
		v[s]=i;
		str[i]=s;
	}
	inc(i,1,n){
		cin>>s;_x=v[s];
		m=read();
		while(m--){
			cin>>s;
			while(1){
				bool f=true;
				cin>>s;
				if(s.back()==',')s.pop_back(),f=false;
				d[_x][v[s]]=1;//printf("%d %d\n",v[s],_x);
				if(f)break;
			}
		}
	}
	_x=1;_y=1;
	inc(i,1,n)if(d[i][i]==1){
		cout<<str[i]<<endl;
		return 0;
	}
	inc(k,1,n)inc(i,1,n)inc(j,1,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	bool f=false;
	inc(i,1,n)inc(j,1,n)if(d[i][j]<inf&&d[j][i]<inf&&d[i][j]+d[j][i]<d[_x][_y]+d[_y][_x]){
		_x=i;_y=j;f=true;
	}
	if(!f)return 0*printf("SHIP IT\n");
	cout<<str[_x]<<' ';dfs(_x,_y);cout<<str[_y]<<' ';dfs(_y,_x);cout<<endl;
	return 0;
}
