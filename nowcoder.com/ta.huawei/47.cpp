#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF) {
        int start, s_value;
        int end, e_value;
        scanf("%d %d", &start, &s_value);
        printf("%d %d\n", start, s_value);
        while(--m) {
            scanf("%d %d", &end, &e_value);
            if(end == start)
                continue;
            for(int i = 1; i < end - start; i ++)
                printf("%d %d\n", i + start, 
                       s_value+(e_value-s_value)/(end-start)*i);
            printf("%d %d\n", end, e_value);
            start = end;
            s_value = e_value;
        }
    }
    return 0;
}
