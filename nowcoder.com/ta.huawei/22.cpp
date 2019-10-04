#include <stdio.h>

int num(int remain, int full) {
    if(remain <= 1)
        return full;
    if(remain == 2) // 要一个喝完再换
        return full + 1;
    full += remain / 3;
    remain = remain % 3 + remain / 3;
    return num(remain, full);
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        printf("%d\n", num(n, 0));
    }
    return 0;
}
