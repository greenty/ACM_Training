#include <bits/stdc++.h>
using namespace std;
inline int Cin(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return f*x;}
const int N = 1e5+5;
int a[N],f[N],g[N],n,LIS[N],mp[N],L; // key == g == L-f的时候 value == 相应最小的 a
int book[N];
int b_s(int n,int val)
{
    int l = 1,r = n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(LIS[mid] == val) return mid;
        else if(LIS[mid]>val) l = mid+1;
        else r = mid;
    }
    return l;
}
int get_LIS(int arr[],int type)
{
    int i,j,siz = 1;
    if(type) { // LDS
        i = n;
        while(a[i] == 0&& i>0) i--;
        LIS[1] = a[i];arr[i] = 1;
        for(i = i-1;i>=1;i--)
        {

            if(a[i] == 0) continue;
            if(a[i] >=LIS[1]) j = 1;
            else if(a[i] < LIS[siz]) j = ++siz;
            else j = b_s(siz,a[i]);
            LIS[j] = a[i];arr[i] = j;
        }
    }
    else { //LIS
        i = 1;
        while(a[i] == 0&& i<=n )i++;
        LIS[1] = a[i];arr[i] = 1;
    //    cout<<"siz = "<<siz<<endl;
        for(i = i+1;i<=n;i++)
        {
            
            if(a[i] == 0) continue;
    //        cout<<"::"<<a[i]<<" "<<LIS[siz]<<endl;
            if(a[i] <=LIS[1]) j=1;
            else if(a[i] > LIS[siz]) j = ++siz;
            else j = lower_bound(LIS+1,LIS+siz+1,a[i]) - LIS;
            LIS[j] = a[i];arr[i] = j;
        }
    //    cout<<"siz => "<<siz<<endl;
        // for(int i = 1;i<=n;i++)
        //     cout<<arr[i]<<"::";
        // cout<<endl;
    }
    return siz;
}
void update_mp(int l,int r)
{
    for(int i = l;i <= r;i++)
    {
        //cout<<i<<"::"<<g[i]<<endl;
        if(mp[g[i]] == -1) mp[g[i]] = a[i];
        else mp[g[i]] = mp[g[i]] < a[i] ? mp[g[i]] : a[i];
    }
    return;
}
void get_book()
{
    int pre = 0;
    memset(mp,-1,(n<<2)+8);
    mp[0] = 0;
    for(int i = 1;i<=n;i++)
    {
        if(a[i] == 0){
            update_mp(pre+1,i-1);
            pre = i;
            while(a[i+1] == 0 && i+1<=n) {
                pre = ++i;
            }
    //        cout<<i<<" "<<L<<" "<<mp[L]<<endl;
            if(mp[L] !=-1 && mp[L] < n){
                book[mp[L]+1]++;
                book[n+1]--;
            }
        }
        else{
            int need = L - f[i];
            // cout<<i<<" "<<f[i]<<" "<<need<<" "<<mp[need]<<endl;
            if(pre && mp[need] != -1 && mp[need] < a[i]){ // 存在g[j] = L - f[i] 
                book[mp[need]+1]++;
                book[a[i]]--;
            }
        }
    }
}
long long solve()
{
    long long res = 0LL;
    for(int i = 1;i<=n;i++)
    {
        book[i]+=book[i-1];
    //    cout<<"::"<<L<<" "<<book[i]<<endl;
            res+=L*i;
        if(book[i]) res+=i;
    }
//    cout<<endl;
    return res;
}
void csh()
{
    memset(f,0,(n<<2)+8);
    memset(g,0,(n<<2)+8);
    memset(book,0,(n<<2)+8);
}
int main()
{
    //ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 1;i<=n;i++) a[i] = Cin();
        get_LIS(f,1);; // nlogn
        L = get_LIS(g,0);; //nlogn
        get_book();
        long long ans = solve(); //n
        printf("%lld\n",ans);
        csh();
    }
}

