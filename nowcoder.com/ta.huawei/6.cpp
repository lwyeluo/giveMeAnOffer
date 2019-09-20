/*
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）

最后一个数后面也要有空格

详细描述：


函数接口说明：

public String getResult(long ulDataInput)

输入参数：

long ulDataInput：输入的正整数

返回值：

String



输入描述:
输入一个long型整数

输出描述:
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long n;
    vector<long> vec;
    while(scanf("%ld", &n) != EOF) {
        int i = 2;
        int tmp_n = n;
        while(i <= sqrt(n)) {
            if(tmp_n % i == 0) {
                tmp_n /= i;
                vec.push_back(i);
            } else {
                i ++;
            }
        }
        for(int i = 0; i < vec.size(); i ++) {
            printf("%d ", vec[i]);
        }
        if(tmp_n == 1)
            printf("\n");
        else
            printf("%d \n", tmp_n);
    }
    return 0;
}
