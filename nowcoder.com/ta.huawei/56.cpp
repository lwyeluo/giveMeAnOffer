#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int cnt = 0;
        for(int i = 2; i <= n; i ++) {
            int sum = 1;
            for(int j = 2; j <= i/2; j ++) {
                if(i % j == 0)
                    sum += j;
            }
            if(sum == i) {
                cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
