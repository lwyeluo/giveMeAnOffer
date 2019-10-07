#include <stdio.h>

void GetResult(int Num, int * pResult) {
    int start = 1, step = 0;
    for(int i = 0; i < Num; i ++) {
        start += i;
        step = 2 + i;
        *pResult++ = start;
        for(int j = 1; j < Num - i; j ++) {
            *pResult = *(pResult - 1) + (step + j - 1);
            pResult++;
        }
        *pResult++ = 0;
    }
}

int main() {
    int num;
    while(scanf("%d", &num) != EOF) {
        int len = num * (num + 1) / 2 + num;
        int *pResult = new int[len];
        GetResult(num, pResult);
        for(int i = 0; i < len; i ++) 
            if(pResult[i] == 0) printf("\n");
            else printf("%d ", pResult[i]);
        delete[] pResult;
    }
    return 0;
}
