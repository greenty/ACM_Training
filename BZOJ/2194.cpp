#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],b[100005];
ll d[400005];
const double PI = acos(-1);
struct Complex{
	double i,r;
	Complex(double _r = 0,double _i = 0) {	r = _r;i = _i;	}

	Complex operator + (const Complex &b){
		return Complex(r+b.r,i+b.i);
	}
	Complex operator - (const Complex &b){
		return Complex(r-b.r,i-b.i);
	}
	Complex operator * (const Complex &b){
		return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
	}
}ax[400005],bx[400005];
void change(Complex y[], int n)
{
	int i, j, k;
	for (i = 1,j = n / 2;i < n - 1;i++)
	{
	    if (i < j)swap(y[i], y[j]);
	    k = n / 2;
	    while (j >= k)
	    {
	        j -= k;
		    k /= 2;
		 }
		if (j < k)j += k;
	}
}
void fft(Complex y[], int n, int on) 
{
	change(y, n);
	for (int h = 2;h <= n;h <<= 1)
	{
	    Complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
	    for (int j = 0;j < n;j += h)
	    {
	        Complex w(1, 0);
	        for (int k = j;k < j + h / 2;k++)
			{
				Complex u = y[k];
				Complex t = w*y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w = w*wn;
			}
		}
	}
	if (on == -1)
		for (int i = 0;i < n;i++)
			y[i].r /= n;
}

int main()
{
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%d%d",&a[i],&b[n-i-1]);
	int len = 1;
	while(len < 2*n) len <<=1;
	for(int i = 0;i<n;i++)
	{
		ax[i] = Complex(a[i],0);
		bx[i] = Complex(b[i],0);
	}
	for(int i = n;i<len;i++) 
		ax[i] = bx[i] = Complex(0,0); 
	fft(ax,len,1);
	fft(bx,len,1);
	for(int i = 0;i<len;i++)
		ax[i] = ax[i] * bx[i];
	fft(ax,len,-1);
	for(int i = 0;i<len;i++)
		d[i] = (ll)(ax[i].r+0.5);
	len = n*2-2;
	for(int i = n-1;i>=0;i--)
		printf("%lld\n",d[len-i]);

}
