/*
        According to the sample 1,we can know that "ab" can be transformed into "ba" , it means "a" "b" can exchange position
        So, "a" "b" position won't affect the result,we only need to consider the number of "a" and "b";  
        We can add or delete "aa" "bb" "abab",so we can't add or delete "c" ,it means S,T can be divided into several parts by "c"
        1.If the number of "c" is differete —— No
        2.For every part,The difference between the number of "a"("b") in S, and the number of "a"("b") in T, 
          is not equal to the multiplier of 2 —— No     
*/
#include <bits/stdc++.h>
using namespace std;
template <class T> inline void print(T x){if (x<0)putchar('-'),x=-x;if (x<10)putchar(x + '0');else wt(x / 10), putchar(x % 10 + '0');}
template <class T> inline void scan(T&x){bool f=0; char ch;for(ch=getchar();ch<=32;ch=getchar());if (ch=='-')f=1,ch=getchar();for(x=0;ch>32;ch=getchar()) x =(x<<3)+(x<<1)+ch-'0';if(f) x=-x;}
const int INF = 0x3f3f3f3f;
typedef  long long LL;typedef  unsigned long long ULL;typedef  long double LDB;
string s,t;
vector<string>a;
vector<string>b;
int main()
{
        ios::sync_with_stdio(false);
        while(cin>>s>>t)
        {
                int c1 = 0;
                for(int i = 0;i<s.size();i++) if(s[i] == 'c') c1++;
                for(int i = 0;i<t.size();i++) if(t[i] == 'c') c1--;
                if(c1 != 0 ) {
                        cout<<"No"<<endl;
                        continue;
                }
                a.clear(); b.clear();
                s+='c'; t+='c';
                int n = 0,m = 0;
                string k1 = "",k2 = "";
                while(n <s.size() && m < t.size() )
                {
                        while(s[n]!='c'){
                                k1+=s[n];
                                n++;
                        }
                        while(t[m]!='c'){
                                k2+=t[m];
                                m++;
                        }
                        a.push_back(k1);
                        b.push_back(k2);
                        k1 = "";k2 = "";
                        n++;m++;
                }
                n = a.size();
                int flag = 0;
                for(int i = 0;i<n;i++)
                {
                        int xa = 0,xb = 0;
                        for(int j = 0;j<a[i].size();j++)
                        {
                                if(a[i][j] == 'a') xa++;
                                else xb++;
                        }
                        for(int j = 0;j<b[i].size();j++)
                        {
                                if(b[i][j] == 'a') xa--;
                                else xb--; 
                        }
                        if(xa%2 || xb%2) {
                                flag = 1;
                                break;
                        }
                } 
                if(flag == 0) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
        }
}