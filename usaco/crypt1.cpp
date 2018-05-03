/*
ID:greenty2
LANG:C++
TASK:crypt1
*/
#include<cstdio>
#include<cstring> 
#include<cstdlib> 
int num[10];
int n;
int a[5];
int b[5];
int c[5];
int book[10];
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		book[num[i]]=1;
	}
	for(int i1=1;i1<=n;i1++)
	{
		
		for(int i2=1;i2<=n;i2++)
		{
			for(int i3=1;i3<=n;i3++)
			{
				for(int j1=1;j1<=n;j1++)
				{
					for(int j2=1;j2<=n;j2++)
					{
						memset(a,0,sizeof(a));
						a[3]+=num[i3]*num[j2];
						if(a[3]>=10)
						{
							a[2]+=a[3]/10;
							a[3]=a[3]%10;
						}
						a[2]+=num[i2]*num[j2];
						if(a[2]>=10)
						{
							a[1]+=a[2]/10;
							a[2]=a[2]%10;
						}
						a[1]+=num[i1]*num[j2];
						if(a[1]>=10)
						continue;
						memset(b,0,sizeof(b));
						b[2]+=num[i3]*num[j1];
						if(b[2]>=10)
						{
							b[1]+=b[2]/10;
							b[2]=b[2]%10;
						}
						b[1]+=num[i2]*num[j1];
						//		if(num[i1]==3&&num[i2]==7&&num[i3]==7&&num[j1]==2&&num[j2]==1)
						//{
						//	printf("%d\n",b[1]);
						//	system("pause");
						//}
						if(b[1]>=10)
						{
									
							b[0]+=b[1]/10;
							//if(num[i1]==3&&num[i2]==7&&num[i3]==7&&num[j1]==2&&num[j2]==1)
						//{
						//	printf("%d\n",b[1]);
						//	system("pause");
						//}
							b[1]=b[1]%10; 
						//		if(num[i1]==3&&num[i2]==7&&num[i3]==7&&num[j1]==2&&num[j2]==1)
						//{
						//	printf("%d %d\n",b[1],b[0]);
						//	system("pause");
						//}
						}
						b[0]+=num[i1]*num[j1];
						if(b[0]>=10)
						continue;
						int flag=0;
						for(int i=1;i<=3;i++)
						{
							if(book[a[i]]==0)
							{
								flag=1;
								break;
							}
						}
						if(flag==1)continue;
						for(int i=0;i<=2;i++)
						{
							if(book[b[i]]==0)
							{
								flag=1;
								break;
							}
						} 
						if(flag==1) continue;
						memset(c,0,sizeof(c));
						c[3]+=a[3];
						if(c[3]>=10)
						{
							c[2]+=c[3]/10;
							c[3]=c[3]%10;
						}
						c[2]=a[2]+b[2];
						
						if(c[2]>=10)
						{
							
							c[1]+=c[2]/10;
							c[2]=c[2]%10;
						
						}
						c[1]+=a[1]+b[1];
						if(c[1]>=10)
						{
							c[0]+=c[1]/10;
							c[1]=c[1]%10;
						}
						c[0]+=b[0];
						if(c[0]>=10) continue;
						for(int i=0;i<=3;i++)
						{
							if(book[c[i]]==0)
							{
								flag=1;
								break;
							}
						}
						if(flag==1) continue;
					/*	printf("  %d %d %d\n",num[i1],num[i2],num[i3]);
						printf("    %d %d\n",num[j1],num[j2]);
						printf("-----------------------------------------------------\n");
						for(int i=0;i<=3;i++)
						{
							printf("%d ",a[i]);
						}
						printf("\n");
						for(int i=0;i<=2;i++)
						{
							printf("%d ",b[i]);
						}
						printf("\n-----------------------------------------------------\n");
						for(int i=0;i<=3;i++)
						{
							printf("%d ",c[i]);
						}
						printf("\n");
						printf("=========================================================	\n\n");*/
						sum++;
					}
				}
			}
		} 
	}
	printf("%d\n",sum);
} 

