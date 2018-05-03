/*
ID:greenty2
LANG:C++
TASK:humble
*/
#include<stdio.h>
using namespace std;
int s[100005],pri[105],pre[105],n,k,temp=1;
int main(void)
{
    freopen("humble.in","r",stdin);
    freopen("humble.out","w",stdout);
    scanf("%d%d",&k,&n);
    for(int i=0;i<k;i++)
        scanf("%d",&pri[i]);
    s[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
            for(;pre[j]<i;pre[j]++)
            if(s[pre[j]]*pri[j]>temp)
            {
                if(s[i]==0 || s[pre[j]]*pri[j]<s[i])
                    s[i]=s[pre[j]]*pri[j];
                break;
            }
        temp=s[i];
    }
    printf("%d\n",s[n]);
    return 0;
}
