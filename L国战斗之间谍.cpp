#include <algorithm>
#include <cstdio>
int n, m, x;
int a[101], b[101], c[101], f[1010][1010];
int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = m; j <= b[i]; ++j)
			for (int k = x; k <= c[i]; ++k)
				f[j][k] = std::max(f[j][k], f[j - b[i]][k - c[i]] + a[i]);
	printf("%d\n", f[m][x]);
	return 0;
}
