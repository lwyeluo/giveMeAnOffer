#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i ++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int mid = n / 2;
        int k, l;
        for(int i = 0; i < mid; i ++) {
            k = mid - i;
            l = mid + i;
            if(isPrime(k) && isPrime(l)) {
                printf("%d\n%d\n", k, l);
                break;
            }
        }
    }
    return 0;
}
