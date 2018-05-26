#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T;
char s[25];
struct cre{
	int wz;
	char op;
	int nex,pre;
	friend bool operator <  (cre a,cre b)
	{
		return a.wz < b.wz;
	}
}o[10];
int shu[10];
char num[25];
int n;
LL js(int jia,int jian,int cheng,int chu)
{
	//cout<<jia<<" "<<jian<<" "<<cheng<<" "<<chu<<endl;
	o[0].nex = 1;
	o[1].wz = jia;o[1].op = 'j';
	o[2].wz = jian;o[2].op = 'J';
	o[3].wz = cheng;o[3].op = 'c';
	o[4].wz = chu;o[4].op = 'C';
	sort(o+1,o+5);
	o[1].nex = 2;o[1].pre = 0;
	o[2].nex = 3;o[2].pre = 1;
	o[3].nex = 4;o[3].pre = 2;
	o[4].nex = 5;o[4].pre = 3;
	o[5].nex = 6;o[5].pre = 4;
	o[6].pre = 5;
	int _ = 0;
	for(int i = 0;i<o[1].wz;i++) num[_++] = s[i];
	num[_]='\0';
	shu[1] = atoi(num);
	_ = 0;
	for(int i = o[1].wz;i<o[2].wz;i++) num[_++] = s[i];
	num[_] = '\0';
	shu[2] = atoi(num);
	_ = 0;
	for(int i = o[2].wz;i<o[3].wz;i++) num[_++] = s[i];
	num[_] = '\0';
	shu[3] = atoi(num);
	_ = 0;
	for(int i = o[3].wz;i<o[4].wz;i++) num[_++] = s[i];
	num[_] = '\0';
	shu[4] = atoi(num);
	_ = 0;
	for(int i = o[4].wz;i<n;i++) num[_++] = s[i];
	num[_] = '\0';
	shu[5] = atoi(num);
	int now = o[0].nex;
	cout<<"1::"<<endl;
	for(int i= 1;i<=5;i++)
	{
		cout<<shu[i]<<" ";
	}
	cout<<endl;
	while(now!=6)
	{
	//	cout<<"now = "<<now<<endl;
		if(o[now].op == 'c'){
			shu[o[now].pre]   = shu[now] * shu[o[now].pre];

			o[o[now].pre].nex = o[now].nex;
			o[o[now].nex].pre = o[now].pre; 
		}
		else if(o[now].op == 'C'){
			cout<<":::"<<shu[now]<<" "<<shu[o[now].nex]<<endl;
			shu[o[now].pre]   = shu[o[now].pre] / shu[now];
			o[o[now].pre].nex = o[now].nex;
			o[o[now].nex].pre = o[now].pre; 
		}
		now = o[now].nex;
	}
	now = o[0].nex;
	cout<<"2::"<<endl;
	while(now !=6)
	{
		cout<<shu[now]<<" ";
		now = o[now].nex;
	}
	cout<<endl;
	//cout<<"hh2"<<endl;
	now = o[0].nex;
	while(now!=6)
	{
		
		if(o[now].op == 'j'){
			shu[o[now].pre]   = shu[now] + shu[o[now].nex];
			o[o[now].pre].nex = o[now].nex;
			o[o[now].nex].pre = o[now].pre; 
		}
		else if(o[now].op == 'J'){
			shu[o[now].pre]   = shu[now] - shu[o[now].nex];
			o[o[now].pre].nex = o[now].nex;
			o[o[now].nex].pre = o[now].pre; 
		}
		now = o[now].nex;
	}
	cout<<shu[o[0].nex]<<endl;
	cout<<"over"<<endl;
	getchar();
	//system("pause");
	return shu[o[0].nex];
}
int main()
{
	scanf("%d",&T);
	for(int _ = 1;_<=T;_++)
	{
		scanf("%s",s);
		 n = strlen(s);
		LL ans = 0xffffffffffffffff;
		for(int i = 1;i<n;i++){
			for(int j = 1;j<n;j++){
				if(j == i) continue;
				for(int k = 1;k<n;k++){
					if(k == i || k == j) continue;
					for(int c = 1;c<n;c++){
						if(c == k || c == j || c == i) continue;
							LL tot = js(i,j,k,c);
							ans = ans > tot ? ans:tot;
					}
				}
			}
		}
		cout<<"ans  = " <<ans<<endl;
	}
}
