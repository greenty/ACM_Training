#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll A[2000005];
ll L[1000005],R[1000005];  
ll cunt;
const ll inf = 0x7fffffffffffffff;
void Merge(int Left,int Middle,int Right)  
{  
    int n1=Middle-Left+1;  
    int n2=Right-Middle;  
  
    for(int i=1;i<=n1;i++)  
        L[i]=A[Left+i-1];  
    for(int i=1;i<=n2;i++)  
        R[i]=A[Middle+i];  
  
    L[n1+1]=inf;  
    R[n2+1]=inf;  
  
    int i=1;  
    int j=1;  
    for(int k=Left;k<=Right;k++)  
    {  
        if(L[i]<=R[j])  
            A[k]=L[i++];  
  
        else  
        {  
            A[k]=R[j++];  
            cunt+=n1-i+1;                   
        }  
    }  
}  
  
void Merge_sort(int Left,int Right)  
{  
    int Middle;  
    if(Left<Right)  
    {  
        Middle=(Left+Right)/2;   
        Merge_sort(Left,Middle);                        
        Merge_sort(Middle+1,Right);                  
        Merge(Left,Middle,Right);              
	}  
}  
int main()
{
	cin>>n;
	cunt = 0LL;
	for(int i = 1;i<=n;i++)
	{
		cin>>A[i];
	}
	Merge_sort(1,n);
	ll t1=3*n;ll t2=7*n+1;
	cunt%=2;t1%=2;t2%=2;
	if(cunt==t1)cout<<"Petr"<<endl;
	else cout<<"Um_nik"<<endl;
	return 0;
}
