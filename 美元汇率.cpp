#include <algorithm>
#include <cstdio>
int n, a;
double fc[101][2], fn[101][2];
int main() {
	scanf("%d", &n);
	fc[0][0] = fn[0][0] = 100;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		fc[i][0] = std::max(fc[i - 1][1], fn[i - 1][1]) / a * 100;
		fc[i][1] = std::max(fc[i - 1][0], fn[i - 1][0]) / 100 * a;
		fn[i][0] = std::max(fc[i - 1][0], fn[i - 1][0]);
		fn[i][1] = std::max(fc[i - 1][1], fn[i - 1][1]);
	}
	printf("%.2f\n", std::max(fn[n][0], fc[n][0]));
	return 0;
}
