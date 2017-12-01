#include <algorithm>
#include <cstdio>
int n, v, m;
int w[51], h[51], c[51], f[401][401];
int main() {
	scanf("%d%d\n%d", &v, &m, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &w[i], &h[i], &c[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = v; j >= w[i]; --j)
			for (int k = m; k >= h[i]; --k)
				f[j][k] = std::max(f[j][k], f[j - w[i]][k - h[i]] + c[i]);
	printf("%d\n", f[v][m]);
	return 0;
}
