/*
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

输入描述:
 输入一个整数（int类型）

输出描述:
 这个数转换成2进制后，输出1的个数
*/

#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int cnt = 0;
        while(n > 0) {
            n = n & (n - 1);
            cnt ++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
