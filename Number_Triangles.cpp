#include <algorithm>
#include <cstdio>
int n, ans;
int a[1001][1001], f[1001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j >= 1; --j) {
			f[j] = std::max(f[j], f[j - 1]) + a[i][j]
		}
}
