#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
const double PI = acos(-1.0);
struct Complex{
	double r,i;
	Complex(double _r = 0,double _i = 0) 
	{
		r = _r;i = _i;
	}
	Complex operator +(const Complex &b){
		return Complex(r+b.r,i+b.i);
	}
	Complex operator -(const Complex &b){
		return Complex(r-b.r,i-b.i);
	}
	Complex operator *(const Complex &b){
		return Complex(r*b.r - i*b.i,r*b.i+i*b.r);
	}
}x1[400005];
long long num[400005];
void change(Complex y[],int n)
{
	int i,j,k;
	for(i = 1,j = n/2;i<n-1;i++)
	{
		if(i<j) swap(y[i],y[j]);
		k = n/2;
		while(j>=k)
		{
			j-=k;
			k/=2;
		}
		if(j<k)j+=k;
	}
}
void fft(Complex y[],int n,int on)
{
	change(y,n);
	for(int h = 2;h<=n;h<<=1)
	{
		Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
		for(int j = 0;j<n;j+=h)
		{
			Complex w(1,0);
			for(int k = j;k<j+h/2;k++)
			{
				Complex u = y[k];
				Complex t = w*y[k+h/2];
				y[k] = u+t;
				y[k+h/2] = u-t;
				w = w*wn;
			}
		}
	}
	if(on == -1)
	 for(int i = 0;i<n;i++)
		 y[i].r /=n;
}
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		memset(num,0,sizeof(num));
		memset(x1,0,sizeof(num));
		scanf("%d",&n);
		for(int i = 1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			num[a[i]]++;
		}
		sort(a+1,a+n+1);
		//FFT get num[]
		int len1 =a[n]+1;
		int len = 1;
		while(len < len1*2) len<<=1;
		for(int i = 0;i<len1;i++)
			x1[i] = Complex(num[i],0);
		for(int i = len1;i<len;i++)
			x1[i] = Complex(0,0);
		fft(x1,len,1);
		for(int i = 0;i<len;i++)
			x1[i]= x1[i]*x1[i];
		fft(x1,len,-1);
		for(int i = 0;i<len;i++)
			num[i] = (long long)(x1[i].r+0.5);
		len = 2*a[n];
		for(int i = 1;i<=n;i++) num[a[i]+a[i]]--;//same two
		for(int i = 1;i<=len;i++) num[i]/=2; //
		for(int i = 2;i<=len;i++) num[i]+=num[i-1];
		long long ans = 0LL;
		for(int i = 1;i<=n;i++) //count ans;
		{
			ans += num[len]-num[a[i]];
			ans -= (n-i)*1LL*(i-1); // one big one small
			ans -= (n-i)*1LL*(n-i-1)/2;//two  big
			ans -= (n-1);//one same
		}
		
		long long tot = n*1LL*(n-1)*1LL*(n-2)/6;
		printf("%.7lf\n",ans*1.0/tot);

	}

}
