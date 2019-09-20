/*
题目描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

示例1
输入
0xA
输出
10
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        int len = str.length();
        int i = len - 1;
        int val = 0, inc = 1, fin = 0;
        while(i > 1) {
            if(str[i] >= 'A' && str[i] <= 'F')
                val = str[i] - 'A' + 10;
            else
                val = str[i] - '0';
            fin += inc * val;
            inc <<= 4;
            i --;
        }
        printf("%d\n", fin);
    }
    return 0;
}
