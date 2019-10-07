#include <stdio.h>

int main() {
    int start;
    while(scanf("%d", &start) != EOF) {
        double sum = start;
        double each = (double)start / 2;
        for(int i = 2; i <= 5; i ++) {
            sum += each * 2;
            each /= 2;
        }
        printf("%g\n%g\n", sum, each);
    }
    return 0;
}
