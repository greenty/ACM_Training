#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	double xx = log(x)*1.0/x;
	double yy = log(y)*1.0/y;
	if(fabs(xx-yy)<1e-8) cout<<"="<<endl;
	else if(xx > yy) cout<<">"<<endl;
	else cout<<"<"<<endl;
}
