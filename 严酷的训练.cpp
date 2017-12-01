#include <algorithm>
#include <cstdio>
int l1, l2, n, m, k, tmp;
int pc[5001], c[5001], w[5001], f[5001];
int main() {
	scanf("%d%d", &l1, &l2);
	l1 = l2 / l1;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i) 
		scanf("%d", &pc[i]), pc[i] = pc[i] * l1;
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &c[i], &w[i]), c[i] = pc[c[i]];
	scanf("%d", &m);
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= c[i]; --j)
			f[j] = std::max(f[j], f[j - c[i]] + w[i]);
	printf("%d\n", f[m]);
	return 0;
}
