#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int _;scanf("%d",&_);
	int Case=0;
	while(_--){
		int n,k;scanf("%d%d",&n,&k);
		printf("Case #%d: ",++Case);
		if(k==1){
			for(int i=1;i<=n;i++){
				if(i==1)printf("%d",i);
				else printf(" %d",i);
			}
			printf("\n");
			continue;
		}
		a[1]=2*k;a[2]=k;int cnt=2;
		for(int i=k+1;i<=n;i++)if(k*2!=i)a[++cnt]=i;
		for(int i=1;i<k;i++)if(k*2!=i)a[++cnt]=i;
		for(int i=1;i<=n;i++){
			if(i==1)printf("%d",a[i]);
			else printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
