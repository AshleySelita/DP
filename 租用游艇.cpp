#include <algorithm>
#include <cstdio>
#include <cstring>
int a[201][201];
int n;
int main() {
    memset(a, 127, sizeof a);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            scanf("%d", &a[i][j]);
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);
    printf("%d\n", a[1][n]);
    return 0;
}