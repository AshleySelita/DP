#include <algorithm>
#include <cstdio>
typedef long long ll;
int n, x;
int lose[1001], win[1001], use[1001], f[1001];
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &lose[i], &win[i], &use[i]);
		for (int j = x; j >= use[i]; --j)
			f[j] = std::max(f[j] + lose[i], f[j - use[i]] + win[i]);
		for (int j = 0; j < use[i]; ++j)
			f[j] = f[j] + lose[i];
	}
	printf("%lld\n", ll(f[x]) * 5);
	return 0;
}
