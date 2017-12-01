#include <algorithm>
#include <cstdio>
#include <cstring>
int n, m, k, r, ans;
int t[11], w[11], c[11], f1[51], f2[151];
int main() {
    //freopen("sss.in", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &t[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &c[i]);
    memset(f1, 0x7f, sizeof f1);
    f1[0] = 0;
    for (int i = 1; i <= m; ++i)  
        for (int j = k; j >= c[i]; --j) 
            if(f1[j] > f1[j - c[i]] + w[i])
                f1[j] = f1[j - c[i]] + w[i];
    r = r - f1[k];
    for (int i = 1; i <= n; ++i)
        for (int j = r; j >= t[i]; --j)
            f2[j] = std::max(f2[j], f2[j - t[i]] + 1);
    printf("%d\n", f2[r]);
    return 0;
}
