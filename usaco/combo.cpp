/*
ID:greenty2
LANG:C++
TASK:combo
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
int lock1[5];
int lock2[5];
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
	{
		scanf("%d",&lock1[i]);
	}
	for(int j=1;j<=3;j++)
	{
		scanf("%d",&lock2[j]);
	}
	int sum=0;
	for(int i1=1;i1<=n;i1++)
	{
		for(int i2=1;i2<=n;i2++)
		{
			for(int i3=1;i3<=n;i3++)
			{
				//if(i1==4&&i2==1&&i3==1)
				//{
				//	printf("%d %d\n%d %d\n%d %d\n",lock1[1],i1,lock1[2],i2,lock1[3],i3);
				//	system("pause");
				//}
				if((lock1[1]-i1<=2&&lock1[1]-i1>=-2)||(lock1[1]-(i1-n)<=2)||((i1+n)-lock1[1]<=2))
				{
						if((lock1[2]-i2<=2&&lock1[2]-i2>=-2)||(lock1[2]-(i2-n)<=2)||((i2+n)-lock1[2]<=2))	
						{
							
							if((lock1[3]-i3<=2&&lock1[3]-i3>=-2)||(lock1[3]-(i3-n)<=2)||((i3+n)-lock1[3]<=2))
							{
								//printf("%d %d %d\n",i1,i2,i3);
								sum++;
								continue;
							}
						}
				}			
				if((lock2[1]-i1<=2&&lock2[1]-i1>=-2)||(lock2[1]-(i1-n)<=2)||((i1+n)-lock2[1]<=2))
				{
						if((lock2[2]-i2<=2&&lock2[2]-i2>=-2)||(lock2[2]-(i2-n)<=2)||((i2+n)-lock2[2]<=2))	
	 					{
							if((lock2[3]-i3<=2&&lock2[3]-i3>=-2)||(lock2[3]-(i3-n)<=2)||((i3+n)-lock2[3]<=2))
							{
								//printf("%d %d %d\n",i1,i2,i3);
								sum++;
								continue;
							}
						}
				}
				
			}
			//printf("\n");
		}	
		//printf("----------\n");
	}
	printf("%d\n",sum);
} 
