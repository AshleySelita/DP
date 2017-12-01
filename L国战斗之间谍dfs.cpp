#include <algorithm>
#include <cstdio>
int n, m, x, ans;
int a[101], b[101], c[101], gett[101];
inline void dfs(int now, int met, int pwr, int cost) {
	if(now > n) return ;
	if(pwr >= b[now] && cost >= c[now]){
		ans = std::max(ans, met + a[now]);
		dfs(now + 1, met + a[now], pwr - b[now], cost - c[now]);
	}
	dfs(now + 1, met, pwr, cost);
	return ;
}
int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	dfs(1, 0, m, x);
	printf("%d\n", ans);
	return 0;
}
