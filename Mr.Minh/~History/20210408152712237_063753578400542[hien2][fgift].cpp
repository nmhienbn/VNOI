#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "fgift"
#define maxn 1000000000
#define maxm 300005

using namespace std;

int n, m, a[maxm], res=-maxn, sum=0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n >> m;
    f(i, 1 , m) cin >> a[i];
    f(i, 1, *max_element(a+1, a+m+1)){
        sum=0;
        f(j, 1, m) sum+=(a[j]-1)/i + 1;
        if (sum<=n) {res=max(res, i); break;}
    }
    cout << res;
}