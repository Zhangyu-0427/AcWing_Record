#include <stdio.h>
#include <stdlib.h>

struct Order {
    int l;
    int r;
}s[500010];

int cmp(const void* a, const void* b) {
    int a_ = ((struct Order*)a)->r;
    int b_ = ((struct Order*)b)->r;
    return a_ - b_;
    // a和b相减的结果作为其是否要进行交换的前提
    // 例如 a = nums[0] = 4, b = nums[1] = 3;
    // 则 a - b = 4 - 3 = 1 > 0 ; 
    // 在本例中 if( ( a - b ) ) == if( 1 ) 则a与b进行交换操作就
    // 保证了如果前面的数大于后面的数就进行交换，即按升序排序
}

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i].l, &s[i].r);
    }

    // 快排
    qsort(s, n, sizeof(s[0]), cmp);

    int res = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].l > last) {
            res++;
            last = s[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}