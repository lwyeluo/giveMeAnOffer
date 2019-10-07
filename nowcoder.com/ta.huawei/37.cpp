#include <stdio.h>

int main() {
    int month;
    while(scanf("%d", &month) != EOF) {
        int a = 1, b = 0, c = 0; // 分别为一个月、两个月、三个月兔子数
        while(month-- > 1) {
            c += b;
            b = a;
            a = c;
        }
        printf("%d\n", a+b+c);
    }
    return 0;
}
