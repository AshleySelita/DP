#include <algorithm>
#include <cstdio>
int n, ans;
int a[1001][1001], f[1001][1001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; j++) {
			scanf("%d", &a[i][j]);
			f[i][j] = std::max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
			ans = std::max(f[i][j], ans);
		}
	printf("%d\n", ans);
	return 0;
}
