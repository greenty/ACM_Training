#include<bits/stdc++.h>
using namespace std;

struct cre{
	string name;
	double k1,k2;
}a[505];
int n;
bool cmp(cre x,cre y)
{
	if(x.k2 == y.k2) return x.k1 < y.k1;
	return x.k2<y.k2;
}
struct cre2{
	double ans1;
	int name[5];
}ans;
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].k1>>a[i].k2;
	}
	sort(a+1,a+n+1,cmp);
	ans.ans1 = 999999999;
	for(int i = 1;i<=n;i++)
	{
		double t = 0;
		if(i <=4){
			for(int j = 1;j<=4;j++)
			{
				if(j == i) t+=a[j].k1;
				else t+=a[j].k2;
			}
		}
		else{
			t+=a[i].k1;
			for(int j = 1;j<=3;j++)
			{
				t+=a[j].k2;
			}
		}
		if(t<ans.ans1)
		{
			ans.ans1 = t;
			ans.name[1] = i;
			if(i<=4)
			{
			int tot = 1;
				for(int j = 1;j<=4;j++)
				{
					if(j!=i)
					ans.name[++tot] = j;
				}
			} 
			else
			{
				for(int j = 1;j<=3;j++)
				{
					ans.name[j+1] = j;
				}
			}

		}
	}
	printf("%.6lf\n",ans.ans1);
	for(int i = 1;i<=4;i++)
	{
		cout<<a[ans.name[i]].name<<endl;
	}
}
