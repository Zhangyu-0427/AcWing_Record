#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        int a[101];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        // 理解题意简单模拟即可
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) res++;
            else {
                if (i - 1 >= 0 && a[i - 1] && i + 1 < n && a[i + 1]) res++;
            }
        }
        printf("%d\n", res);
    }
}