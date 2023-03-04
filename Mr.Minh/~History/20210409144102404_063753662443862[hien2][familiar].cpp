#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "familiar"
#define maxn 300005

using namespace std;

int n, res, a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater_equal<int>());
    int maxa=a[1]+1;
    f(i, 1, n) {
        if (a[i]+n >= maxa) res++;
        else break;
        maxa=max(maxa, a[i]+i);
    }
    cout << res;
}
