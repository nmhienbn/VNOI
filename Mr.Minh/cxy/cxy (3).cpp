#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "cxy"
const int maxn = 11e5+5;

using namespace std;

map<ll, int> b;
int k, L[maxn], pre[maxn], id;
ll x, y, mu, a[maxn];
queue<int> q;

void add(ll vv, int u){
    int v;
    if (b[vv] == 0) v = b[vv] = ++id, a[id] = vv;
    else v = b[vv];
    if (L[v] > L[u] + 1){
        L[v] = L[u] + 1;
        pre[v] = u;
        q.push(v);
    }
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> k >> x >> y;
    if (x == y){
        cout << 0;
        exit(0);
    }
    mu = 1;
    fi(i, 1, k) mu *= 10;
    // khoi tao queue
    b[x] = ++id; a[1] = x;
    b[y] = ++id; a[2] = y;
    fi(i, 2, 11e5) L[i] = 1e9;
    q.push(1);
    // xuli
    while (q.size()){
        int u = q.front();
        q.pop();
        if (u == 2) break;
        // bd1
        ll vv = a[u]+1;
        if (vv <= mu){
            add(vv, u);
        }
        // bd2
        ll tmp = a[u], po = 1;
        while (tmp/10 > 0){
            po *= 10;
            tmp /= 10;
        }
        vv = (a[u] - tmp*po) * 10 + tmp;
        add(vv, u);
    }
    cout << L[2] << '\n';
    int i = 2;
    vector<ll> res;
    res.pb(y);
    while (pre[i]){
        i = pre[i];
        res.pb(a[i]);
    }
    for (auto v = res.rbegin(); v != res.rend(); v++){
        cout << *v << '\n';
    }
}
