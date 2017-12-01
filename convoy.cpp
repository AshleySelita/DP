#include <algorithm>
#include <cstdio>
#define re register
#define lson(i) (i << 1)
#define rson(i) (i << 1 | 1)
#define ll long long
const int MAXN = 1001;
const int INF = 2147483647;
int s, n, u, v, mini[MAXN], segtree[MAXN << 2];
double f[MAXN];
ll si[MAXN], w;
inline void build(int now, int l, int r){
    if(l == r) {segtree[now] = mini[r]; return ;}
    int mid = (l + r) >> 1;
    build(lson(now), l, mid);
    build(rson(now), mid + 1, r);
    segtree[now] = std::min(segtree[lson(now)], segtree[rson(now)]);
    return ;
}
inline int query(int now, int l, int r, int a, int b) {
    if(r < a || l > b) return INF;
    if(a <= l && r <= b) return segtree[now];
    int mid = (l + r) >> 1;
    return std::min(query(lson(now), l, mid, a, b), query(rson(now), mid + 1, r, a, b));
}
int main() {
    //freopen("convoy.in", "r", stdin);
    scanf("%lld%d%d", &w, &s, &n);
    for (re int i = 1; i <= n; ++i) {
        scanf("%d%d", &u, &v);
        si[i] = si[i - 1] + u;
        mini[i] = v;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + double(s) / mini[i];
        for (int j = i - 2; j >= 0; --j)
            if(si[i] - si[j] <= w) f[i] = std::min(f[i], f[j] + double(s) / query(1, 1, n, j + 1, i));
            else break;
    }
    printf("%.1lf\n", f[n] * 60.0);
}
