#include <algorithm>
#include <cstdio>
#include <cstring>
int a[201][201], f[201];
int n;
int main() {
    memset(f, 127, sizeof f);
    memset(a, 127, sizeof a);
    f[1] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            scanf("%d", &a[i][j]), a[j][i] = a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            f[i] = std::min(f[i], f[i - j] + a[j][i]);
    printf("%d\n", f[n]);
    return 0;
}