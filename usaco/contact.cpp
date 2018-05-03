/*
ID:greenty2
LANG:C++
TASK:contact
*/
#include<bits/stdc++.h>
using namespace std;
int book[8192][13];
string s;
struct cre
{
	int lenth;
	int num;
	int tot;
};
void printss(int x,int m)
{
	string ss;
	while(x!=0)
	{
		ss+=(x%2)+'0';
		x=x/2;
	}
//	cout<<"::"<<ss<<endl;
	int len=ss.size();
	ss.resize(m,'0');
	reverse(ss.begin(), ss.end());
	cout<<ss<<" "; 
	return;
}
bool cmp(cre x,cre y)
{
	if(x.tot==y.tot)
	{
		if(x.lenth==y.lenth)
			return x.num<y.num;
		return x.lenth<y.lenth;
	}
	return x.tot>y.tot;
}
cre book2[20000];
int zh(string ss)
{
	int len=ss.size();
	int ans=0;
//	cout<<"::"<<ss<<endl;
	reverse(ss.begin(), ss.end());
	for(int i=0;i<len;i++)
	{
		ans+=((ss[i]-'0')*pow(2,i));
	}
	return ans;
}
int main()
{
	int a,b,N;
	cin>>a>>b>>N;
	cin>>s;
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	int len=s.size();;
	for(int i=0;i<len-b+1;i++)
	{
		string ss;
		ss.assign(s,i,b);
	//	cout<<ss<<endl;
		int k=zh(ss);
	//	cout<<k<<endl;
		book[k][b]++;
		
	}
	for(int i=b-1;i>=a;i--)
	{
		int n=pow(2,i)-1;
		for(int j=0;j<=n;j++)
		{
			book[j][i]=book[2*j][i+1]+book[2*j+1][i+1];
		//	cout<<":::"<<j<<" "<<i<<" "<<book[j][i]<<endl;
		}
		string sss;
		sss.assign(s,len-i,i);
		int k=zh(sss);
		book[k][i]++; 
	}
	int t=0;
	for(int i=a;i<=b;i++)
	{
		int n=pow(2,i)-1;
		for(int j=0;j<=n;j++)
		{
			t++;
			book2[t].lenth=i;
			book2[t].num=j;
			book2[t].tot=book[j][i];
			
		}
	}
	sort(book2+1,book2+t+1,cmp);
	int now=99999999;
	int tt=0;
	for(int i=1;i<=t;i++)
	{
		if(now>book2[i].tot)
		{
			tt++;
			if(tt>N)
			break;
			now=book2[i].tot;
			if(i!=1)
			cout<<endl;
			cout<<now<<endl;
		}
		printss(book2[i].num,book2[i].lenth);
	}
	
	
} 
