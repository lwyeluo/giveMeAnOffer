#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

bool isPrime(int x) {
    for(int i = 2; i <= sqrt(x); i ++)
        if(x % i == 0)
            return false;
    return true;
}

int n, m;
int odd[105], even[105];
bool used[105];
int matched_odd[105];
bool edge[105][105];

bool match(int x) {
    for(int i = 0; i < m; i ++) {
        if(edge[x][i] && used[i] == false) {
            used[i] = true;
            if(matched_odd[i] == -1 || match(matched_odd[i])) {
                matched_odd[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        int num;
        n = 0, m = 0;
        while(t--) {
            scanf("%d", &num);
            if(num % 2 == 1)
                odd[n++] = num;
            else
                even[m++] = num;
        }
        // edge
        memset(edge, 0, sizeof(edge));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(isPrime(odd[i] + even[j]))
                    edge[i][j] = true;
        // match
        int total = 0;
        memset(matched_odd, -1, sizeof(matched_odd));
        for(int i = 0; i < n; i ++) {
            memset(used, 0, sizeof(used));
            if(match(i))
                total += 1;
        }
        printf("%d\n", total);
    }
    return 0;
}
