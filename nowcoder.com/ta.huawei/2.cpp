/*
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    char sep;
    int count = 0;
    getline(cin, str);
    scanf("%c", &sep);
    for(int i = 0; i < str.length(); i ++) {
        if(str[i] == sep || str[i] == sep - 'a' + 'A'
          || str[i] == sep - 'A' + 'a')
            count += 1;
    }
    printf("%d\n", count);
    return 0;
}
