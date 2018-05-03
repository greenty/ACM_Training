/*
ID:greenty2
LANG:C++
TASK:runround
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long a;
int num[15];
int book[10];
int cat[15];
int cat2[15];
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%lld",&a);
	//itoa(a,num,10);
	//int len=strlen(num); 
	a++;
	//printf("::%s\n",num);
	
	for(;;a++)
	{
		memset(book,0,sizeof(book));
		memset(cat2,0,sizeof(cat2));
		memset(num,0,sizeof(num));
	//	printf("%lld\n",a);
		int len=0;
		long long aa=a;
		while(aa>0)
		{
			num[len]=aa%10;
			aa=aa/10;
			len++;
		}
		 
		for(int i=0;i<len/2;i++)
		{
			int t=num[i];
			num[i]=num[len-i-1];
			num[len-i-1]=t;
		}
	//	for(int i=0;i<len;i++)
	//	{
	//		printf("%d ",num[i]);
	//	}
	//	printf("\n");
		//system("pause");
		//printf("::%s\n",num);
		//printf("%s",num);
		memset(book,0,sizeof(book));
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(book[num[i]]>0||num[i]==0)
			{
				flag=1;
				break;
			}
			book[num[i]]++;
		}
		if(flag==1)
		{
			continue;
		}
		//system("pause");
		for(int i=0;i<len;i++)
		{
			int k=i+(num[i]);
			k=k%len;
			cat[i]=k;
			cat2[k]=num[i];
		//	printf("%d %d\n",k,i);
		}
		//for(int i=0;i<len;i++)
		//{
		//	printf("%d ",cat[i]);
		//}
		//printf("\n");
		//for(int i=0;i<len;i++)
		//{
		//	printf("%d ",cat2[i]);
		//}
	//	printf("\n");
		//system("pause");
		for(int i=0;i<len;i++)
		{
			if(cat2[i]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		//for(int i=cat[1];
		int poi=1;
		poi=cat[poi];
		int t=1;
		while(poi!=1)
		{
			//printf("hhh\n");
			poi=cat[poi];
		//	printf("%d\n",poi);
			t++;
		}
	//	printf("%d\n",t);
		if(t<len)
		{
			flag=1;
		}
		
		if(flag==1)
		{
			
			continue;
		}
		for(int i=0;i<len;i++)
		{
			printf("%d",num[i]);
		}
		printf("\n");
		break;
		//system("pause");
	}
}

