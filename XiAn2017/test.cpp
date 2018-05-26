#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;i++)



using namespace std;





int main(){
	int _=read();while(_--){
		n=read();m=read();
		inc(i,1,n)a[i]=read();
		inc(i,1,m)b[i].x=read(),b[i].y=read();
		sort(b+1,b+1+m);
		_t=1;
		inc(i,1,20){
			c0=c1=0;cnt=0;
			inc(i,1,n){
				if(cnt)c1++;else c0++;
				cnt^=a[i]%2;a[i]>>=1;
			}
			_x=1;
			inc(i,1,m){
				while(_x<b[i].x)
			}
		}
	}
}
