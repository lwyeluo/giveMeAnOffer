/*
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。

输入描述:
输入N个字符，字符在ACSII码范围内。

输出描述:
输出范围在(0~127)字符的个数。

示例1
输入
abc
输出
3
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        set<int> mySet;
        for(int i = 0; i < str.length(); i ++) {
            mySet.insert(str[i]);
        }
        printf("%d\n", mySet.size());
    }
    return 0;
}
