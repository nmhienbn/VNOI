#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "seq51"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], a[i] -= i;
    int j = 0;
    fi(i, 1, n){
        while (j < n && a[j + 1] >= 1 - i) j++;
        res = max(res, j - i + 1);
    }
    cout << res;
}
