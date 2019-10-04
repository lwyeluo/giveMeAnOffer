#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    char str[25];
    int num[26];
    while(scanf("%s", str) != EOF) {
        memset(num, 0, sizeof(num));
        int len = strlen(str);
        for(int i = 0; i < len; i ++)
            num[str[i] - 'a'] ++;
        int min = INT_MAX;
        for(int i = 0; i < 26; i ++)
            if(min > num[i] && num[i] != 0)
                min = num[i];
        for(int i = 0; i < len; i ++)
            if(num[str[i] - 'a'] != min)
                printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}
