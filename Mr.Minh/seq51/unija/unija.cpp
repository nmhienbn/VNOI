#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "unija"
const int maxn = 1e6 + 5;
using namespace std;

int n, now;
ll res;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    fid(i, n, 1){
        now = max(now, a[i].second);
        res += 1ll * now * (a[i].first - a[i - 1].first);
    }
    cout << res;
}
