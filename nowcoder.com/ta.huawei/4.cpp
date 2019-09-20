/*
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组
*/

#include <stdio.h>
#include <string.h>

int main() {
    //freopen("input.txt", "r", stdin);

    char str[105];
    char output[9];
    char fill[9] = "00000000";
    while(scanf("%s", str) != EOF) {
        int len = strlen(str);
        for(int i = 0; i < len; i += 8) {
            memset(output, 0, sizeof(output));
            if(i + 8 > len) {
                memcpy(output, str + i, len - i);
                memcpy(output + len - i, fill, 8 - len + i);
            } else {
                memcpy(output, str + i, 8);
            }
            printf("%s\n", output);
        }
    }
    return 0;
}
