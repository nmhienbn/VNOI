#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "lperm"
const int maxn = 5e4+5;

using namespace std;

struct pii {
    int f, s;
    bool operator < (const pii& x) const {
        return f < x.f;
    }
};

int n, k, bit[maxn*2], b[maxn];
ll res;
pii a[maxn];

void update(int x){
    while (x <= n){
        bit[x]++;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i].f;
        a[i].s = i;
    }
    sort(a+1, a+n+1);
    int id = 0;
    b[a[1].s] = ++id;
    fi(i, 2, n){
        if (a[i].f != a[i-1].f){
            id++;
        }
        b[a[i].s] = id;
    }
    fi(i, 1, n){
        res += get(b[i]+k) - get(b[i]);
        update(b[i]);
    }
    cout << res;
}
