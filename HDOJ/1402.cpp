#include<bits/stdc++.h>
using namespace std;
char s[50005];
int a[2][50005];
int sum[100005];
const double PI = acos(-1);
struct Complex
{
    double r, i;
    Complex(double _r = 0, double _i = 0) :r(_r), i(_i) {}
    Complex operator +(const Complex &b) {
        return Complex(r + b.r, i + b.i);
    }
    Complex operator -(const Complex &b) {
        return Complex(r - b.r, i - b.i);
    }
    Complex operator *(const Complex &b) {
        return Complex(r*b.r - i*b.i, r*b.i + i*b.r);
    }
}x[2][200005];
void change(Complex y[], int n) // 二进制平摊反转置换 O(logn)
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
	while(scanf("%s",s)!=EOF)
	{
		int na = strlen(s);
		for(int i=0,j =na-1;i<j;i++,j--)
		swap(s[i],s[j]);
		for(int i = 0;i<na;i++) a[0][i] = s[i]-'0';
		scanf("%s",s);
		int nb = strlen(s);
		for(int i=0,j =nb-1;i<j;i++,j--) swap(s[i],s[j]);
		for(int i = 0;i<nb;i++) a[1][i] = s[i]-'0';
		int len = 1;
		while(len < 2*max(na,nb)) len<<=1;
		for(int i = 0;i<na;i++) x[0][i] = Complex(a[0][i],0);
		for(int i = na;i<len;i++) x[0][i] = Complex(0,0);
		for(int i = 0;i<nb;i++) x[1][i] = Complex(a[1][i],0);
		for(int i = nb;i<len;i++) x[1][i] = Complex(0,0);
		fft(x[0],len,1);
		fft(x[1],len,1);
		for(int i = 0;i<len;i++)
			x[0][i] = x[0][i] * x[1][i];
		fft(x[0],len,-1);
		for(int i = 0;i<len;i++)
			sum[i] = (long long)(x[0][i].r+0.5);
		len = na+nb;
	    int c = 0;
		for(int i = 0;i<len;i++)
		{
			int now = c+sum[i];
			c = now/10;
			now %=10;
			sum[i] = now;
		}
		int flag = 0;
		int i = len-1;
		while(sum[i] == 0 && i >=0) i--;
		if(i == -1) putchar('0');
		for(;i>=0;i--)
		{
			printf("%d",sum[i]);
		}
		puts("");
	}
}
