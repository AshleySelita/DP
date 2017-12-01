#include <algorithm>
#include <cstdio>
int a[1001], f[1001];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int tmp = i, yue = 2;
        while((tmp ^ 1)) {
            if(!(tmp % yue)) a[i] = a[i] + yue, yue++;
            else yue++;
        }
        a[i]++;
    }
    for (int i = 1; i <= n; ++i) 
        for (int j = n; j >= i; --j)
            f[j] = std::max(f[j], f[j - i] + a[i]);
    return 0;
}