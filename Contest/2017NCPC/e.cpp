#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
	int x,y;
	friend bool operator != (const Point &a,const Point &b)
	{
		if(a.x ==b.x &&a.y ==b.y) return false;
		return true;
	}
	friend bool operator == (const Point &a,const Point &b)
	{
		if(a.x == b.x&&a.y == b.y) return true;
		return false;
	}
};
struct Edge{
	Point p1,p2;
	int w;
	friend bool operator < (const Edge &x,const Edge &y)
	{
		return x.w < y.w;
	}
}edge[2500000];
int n_edge;
int n,m;
int a[505][505];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
Point fa[505][505];
vector<Point>e[505][505];
Point getf(Point a)
{
	if(a == fa[a.x][a.y]) return a;
	return fa[a.x][a.y]=getf(fa[a.x][a.y]);
}
queue<Point>que;
int sx,sy;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++) cin>>a[i][j];
	
	for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++)
	{
		for(int d = 0;d<8;d++)
		{
			int ii  = i + dx[d],jj = j + dy[d];
			if(ii <1 || ii > n || jj < 1 || jj > m) continue;
			edge[++n_edge].w = max(a[i][j],a[ii][jj]);
			edge[n_edge].p1  ={ii,jj};
			edge[n_edge].p2 = {i,j};
		}
	}
	sort(edge+1,edge+n_edge+1);
	for(int i = 1;i<=n;i++) for(int j = 1;j<=m;j++) fa[i][j] = {i,j};
	for(int i = 1;i<=n_edge;i++)
	{
		Point fx = getf(edge[i].p1);
		Point fy = getf(edge[i].p2);
		if(fx!=fy)
		{
			fa[fx.x][fx.y] = fy;
			e[edge[i].p1.x][edge[i].p1.y].push_back(edge[i].p2);
			e[edge[i].p2.x][edge[i].p2.y].push_back(edge[i].p1);
		}
	}
	memset(fa,0,sizeof(fa));
	cin>>sx>>sy;
	que.push({sx,sy});
	while(!que.empty())
	{
		Point now = que.front();
		que.pop();
		for(auto it = e[now.x][now.y].begin();it!=e[now.x][now.y].end();it++)
		{
			Point nex = (*it);
			if(nex == fa[now.x][now.y]) continue;
			fa[nex.x][nex.y] = now;
			a[nex.x][nex.y] = max(a[nex.x][nex.y] , a[now.x][now.y]);
			que.push(nex);
		}

	}
	ll ans = 0LL;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			if(a[i][j] < 0 ) ans+=(-a[i][j]);
		}
	}
	cout<<ans<<endl;
}
