/*
	Enumerate two point which not parallel to the axis of coordinate ,as a diagonal line of a rectangle.
	calculate two other points .Judge whether them exist.
	Enumerate two rectangles as shown previously. Judge whether the 8 points exist and different.
	Enumerate 5 situation to Judge whether two rectangles disjoint or contain,if answer is yes ,total + 1
*/
#include <bits/stdc++.h>
using namespace std;
struct cre{
	int x,y;
}a[50];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n;
int maps[500][500];
set<int>st;
void csh()
{
	memset(maps,0,sizeof(maps));
	st.clear();
}
int main( )
{
	while(1)
	{
		cin>>n;
		if(!n) return 0;
		for(int i = 1;i<=n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			maps[a[i].x][a[i].y] = i;
		}
		int ans = 0;
		inc(i,1,n) inc(j,i+1,n) inc(k,i+1,n) inc(t,k+1,n)
		{
			if(i != k && i!=t && j!=k && j!=t)
			{
				cre a1 = (cre){min(a[i].x,a[j].x) , min(a[i].y,a[j].y)};
				cre a2 = (cre){max(a[i].x,a[j].x) , max(a[i].y,a[j].y)};
				cre b1 = (cre){min(a[k].x,a[t].x) , min(a[k].y,a[t].y)};
				cre b2 = (cre){max(a[k].x,a[t].x) , max(a[k].y,a[t].y)};
				if(a1.x == a2.x || a1.y == a2.y || b1.x == b2.x || b1.y == b2.y) continue;
				int c1 = maps[a[i].x][a[i].y];int c2 = maps[a[j].x][a[j].y];
				int c3 = maps[a[i].x][a[j].y];int c4 = maps[a[j].x][a[i].y];
				int c5 = maps[a[k].x][a[k].y];int c6 = maps[a[t].x][a[t].y];
				int c7 = maps[a[k].x][a[t].y];int c8 = maps[a[t].x][a[k].y];
				st.clear();
				st.insert(c1);st.insert(c2);st.insert(c3);st.insert(c4);
				st.insert(c5);st.insert(c6);st.insert(c7);st.insert(c8);
				if(st.find(0) !=st.end()) continue;
				if(st.size() < 8) continue;
				if(b1.x > a2.x)
				{
					int tot = (a2.x - a1.x) * (a2.y - a1.y);
					tot+= (b2.x - b1.x) * (b2.y - b1.y);
					if(tot > ans) ans = tot;
				}
				else if(a1.x > b2.x)
				{
					int tot = (a2.x - a1.x) * (a2.y - a1.y);
					tot+= (b2.x - b1.x) * (b2.y - b1.y);
					if(tot > ans) ans = tot;
				}
				else if(a2.y < b1.y)
				{
					int tot = (a2.x - a1.x) * (a2.y - a1.y);
					tot+= (b2.x - b1.x) * (b2.y - b1.y);
					if(tot > ans) ans = tot;
				}
				else if(b2.y < a1.y)
				{
					int tot = (a2.x - a1.x) * (a2.y - a1.y);
					tot+= (b2.x - b1.x) * (b2.y - b1.y);
					
					if(tot > ans) ans = tot;
				}
				else if(a1.x < b1.x && a2.x > b2.x && a1.y < b1.y &&a2.y > b2.y )
				{
					int tot = (a2.x - a1.x) * (a2.y - a1.y);
					if(tot>ans) ans = tot;
				}
				else if(b1.x < a1.x && b2.x > a2.x && b1.y < a1.y &&b2.y > a2.y )
				{
					int tot = (b2.x - b1.x) * (b2.y - b1.y);
					if(tot>ans) ans = tot;
				}
			}
		}
		if(ans == 0) cout<<"imp"<<endl;
		else cout<<ans<<endl;
		csh();
		
	}
}
