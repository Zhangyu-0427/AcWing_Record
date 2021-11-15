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
    // a��b����Ľ����Ϊ���Ƿ�Ҫ���н�����ǰ��
    // ���� a = nums[0] = 4, b = nums[1] = 3;
    // �� a - b = 4 - 3 = 1 > 0 ; 
    // �ڱ����� if( ( a - b ) ) == if( 1 ) ��a��b���н���������
    // ��֤�����ǰ��������ں�������ͽ��н�����������������
}

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s[i].l, &s[i].r);
    }

    // ����
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