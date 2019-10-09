#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int print(int n) {
    vector<vector<int> > v(n + 1, vector<int>(2 * n + 1, 0));
    for(int i = 1; i <= n; i++) {
        v[i][1] = 1;
        for(int j = 2; j <= i; j ++) {
            v[i][j] = v[i - 1][j - 2] + v[i - 1][j - 1] + v[i - 1][j];
        }
        for(int j = i + 1; j <= 2 * i - 1; j ++) {
            v[i][j] = v[i][2 * i - j];
        }
    }
    for(int i = 1; i <= n; i ++)
        if(v[n][i] % 2 == 0)
            return i;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", print(n));
    }
    return 0;
}
