#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <map>
typedef long long ll;
const int MAXN = 100001;
const int MAXM = 200001;
const int N = 10000;
std::map<int, int> ma;
struct edge{
    int to, next;
}edge[MAXN << 1];
int n, m, lastans, u, v, top, tot, cnt, w, tmp, f;
int T[MAXN], head[MAXN], bin[18] = {1}, fa[MAXN][18], st[MAXN], ed[MAXN], dep[MAXN], 
segtree[MAXN << 6], lson[MAXN << 6], rson[MAXN << 6], lazy[MAXN << 6];
char opt, buf[N], *p = buf, *end = buf;
inline char Get_char() {
    if(p == end) {
        if(feof(stdin)) return (0);
        p = buf; end = buf + fread(buf, 1, N, stdin);
    }
    return *(p++);
}
template<class Tmp> inline void Get_int(Tmp &x) {
    x = 0; char c(0);
    while(!isdigit(c = Get_char()));
    do {x = (x << 1) + (x << 3) + (c ^ 48);}
    while(isdigit(c = Get_char()));
    return ;
}
inline void Add_edge(int u, int v) {
    edge[++top].to = v;
    edge[top].next = head[u];
    head[u] = top;
    
    edge[++top].to = u;
    edge[top].next = head[v];
    head[v] = top;
}
inline void dfs(int now) {
    st[now] = ++cnt;
    for (int i = 1; i <= 17; ++i)
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    for (int i = head[now]; i; i = edge[i].next) 
        if((tmp = edge[i].to) != fa[now][0]) {
            fa[tmp][0] = now;
            dep[tmp] = dep[now] + 1;
            dfs(tmp);
        }
    ed[now] = cnt;
}
inline int lca(int x, int y) {
    if(dep[x] < dep[y]) std::swap(x, y);
    for (int i = 17; i >= 0; --i)
        if(dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
    if(x == y) return x;
    for (int i = 17; i >= 0; --i)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
inline void pushdown(int now, int l, int r) {
    if(!lazy[now]) return ;
    tmp = lazy[now]; lazy[now] = 0;
    if(!lson[now]) lson[now] = ++tot;
    if(!rson[now]) rson[now] = ++tot;
    segtree[lson[now]] = segtree[lson[now]] + l * tmp; lazy[lson[now]] = lazy[lson[now]] + tmp;
    segtree[rson[now]] = segtree[rson[now]] + r * tmp; lazy[rson[now]] = lazy[rson[now]] + tmp;
    return ;
}
inline void update(int &now, int l, int r, int x, int y, int w) {
    if(r < x || l > y) return ;
    if(now == 0) now = ++tot;
    if(x <= l && y >= r) {
        segtree[now] = segtree[now] + (r - l + 1) * w;
        lazy[now] = lazy[now] + w;
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(now, (mid - l + 1), (r - mid));
    update(lson[now], l, mid, x, y, w);
    update(rson[now], mid + 1, r, x, y, w);
    segtree[now] = segtree[lson[now]] + segtree[rson[now]];
    return ;
}
inline int Query(int now, int l, int r, int goal) {
    if(!now) return 0;
    if(l == r) return segtree[now];
    int mid = (l + r) >> 1;
    pushdown(now, (mid - l + 1), (r - mid));
    if(goal <= mid) return Query(lson[now], l, mid, goal);
    else return Query(rson[now], mid + 1, r, goal);
}
int main() {
    for (int i = 1; i <= 17; ++i) bin[i] = bin[i - 1] << 1;
    Get_int(n); Get_int(m);
    for (int i = 1; i <= n; ++i) Get_int(T[i]);
    for (int i = 1; i < n; ++i) 
        Get_int(u), Get_int(v), Add_edge(u, v);
    dep[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; ++i)
        update(ma[T[i]], 1, n, st[i], ed[i], 1);
    for (int i = 1; i <= m; ++i) {
        opt = Get_char();
        if('C' == opt) {
            Get_int(u); Get_int(w);
            u = u ^ lastans; w = w ^ lastans;
            update(ma[T[u]], 1, n, st[u], ed[u], -1);
            update(ma[w], 1, n, st[u], ed[u], 1);
            T[u] = w;
        }
        else {
            Get_int(u); Get_int(v); Get_int(w);
            u = u ^ lastans; v = v ^ lastans; w = w ^ lastans;
            f = lca(u, v);
            lastans = Query(ma[w], 1, n, st[u]) + Query(ma[w], 1, n, st[v])
            - Query(ma[w], 1, n, st[f]) * 2 + (T[f] == w);
            printf("%d\n", lastans);
        }
    }
    return 0;
}
