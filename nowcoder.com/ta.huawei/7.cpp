/*
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

输入描述:
输入一个正浮点数值

输出描述:
输出该数值的近似整数值
*/

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n;
    while(scanf("%f", &n) != EOF) {
        printf("%d\n", (int)round(n));
    }
    return 0;
}
