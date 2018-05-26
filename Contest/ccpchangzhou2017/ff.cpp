#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
char s[25];
int n;
struct cre{
	int num;
	int id1,id2;
}wz[5];
vector<ll>vec;
ll _atoi(char t[])
{
	int nn = strlen(t);
	ll res = 0LL;
	for(int i = 0;i<nn;i++)
		res  = res * 10LL + (s[i]-'0');
	return res;
}

bool cmp(cre x,cre y)
{
	return x.id1 < y.id1;
}
void get_num(int k1,int k2,int k2,int k4)
{
	wz[1].num = k1;wz[2].num = k2;wz[3].num = k3;wz[4].num = k4;
	for(int i = 1;i<=4;i++) wz[i].id1 = i;
	sort(wz+1,wz+5);
	for(int i = 1;i<=4;i++) wz[i].id2 = i;
	char num[25];
	int _;
	_ = 0;
	vec.push_back(0);
	for(int i = 1;i<=wz[1];i++)num[_++] = s[i];
	num[_] = '\0';vec.push_back(_atoi(num));
	_ = 0;
	for(int i = wz[1]+1;i<=wz[2];i++)num[_++] = s[i];
	num[_] = '\0';vec.push_back(_atoi(num));
	_ = 0;
	for(int i =wz[2]+1;i<=wz[3];i++) num[_++] = s[i];
	num[_] = '\0';vec.push_back(_atoi(num));
	_ = 0;
	for(int i =wz[3]+1;i<=wz[4];i++) num[_++] = s[i];
	num[_] = '\0';vec.push_back(_atoi(num));
	sort(wz+1,wz+5,cmp);
}
void js()
{
	int jia = wz[1].id2,jian = wz[2].id2,cheng = wz[3].id2,chu = wz[4].id2;
	if(cheng < chu)
	{
		int nex = cheng+1;
		while(vec[nex] == -1) nex++;
		vec[cheng] = vec[cheng]*vec[nex];
		vec[nex] = -1;
		nex = chu+1;
		while(vec[nex] == -1) nex++;
		vec[chu] = vec[chu] / vec[nex];
		vec[nex] = -1;
	}
	else
	{
		int nex = chu+1;
		while(vec[nex] == -1) nex++;
		vec[chu] = vec[chu] / vec[nex];
		vec[nex] = -1;
		nex = cheng+1;
		while(vec[nex] == -1) nex++;
		vec[cheng] = vec[cheng]*vec[nex];
		vec[nex] = -1;
	}
	if(jia < jian)
	{

		int nex = jia+1;
		while(vec[nex] == -1) nex++;
		vec[jia] = vec[cheng]+vec[nex];
		vec[nex] = -1;
		nex = jian+1;
		while(vec[nex] == -1) nex++;
		vec[jian] = vec[jian] - vec[nex];
		vec[nex] = -1;
	}
	else
	{
		
		int nex = jian+1;
		while(vec[nex] == -1) nex++;
		vec[jian] = vec[jian]-vec[nex];
		vec[nex] = -1;
		nex = jia+1;
		while(vec[nex] == -1) nex++;
		vec[jia] = vec[jia] + vec[nex];
	}
    for(int i = 1;i<=5;i++)
	{
		if(vec[i]!=-1) return vec[i];
	}
}
int main()
{
	scanf("%d",&T);
	for(int _=1;_<=T;_++)
	{
		scanf("%s",s+1);
		n = strlen(s);
		ll ans = 0xffffffffffffffff;
		for(int i = 1;i<n;i++)
		for(int j = 1;j<n;j++){
			if(j == i)  continue;
		for(int k = 1;k<n;k++){
			if(k == i||k == j) continue;
		for(int l = 1;l<n;l++){
			if(l == i||l == j||l == k) continue;
			get_num(i,j,k,l);
			int tot = js();
			ans = ans > tot ? ans:tot;
		}}}
	}
}
