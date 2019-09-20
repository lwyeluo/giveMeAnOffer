/*
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

输入描述:
输入一个int型整数

输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

示例1
输入
9876673
输出
37689
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        set<char> mySet;
        string output = "";
        for(int i = str.length() - 1; i >= 0; i --) {
            if(mySet.count(str[i]))
                continue;
            mySet.insert(str[i]);
            output += str[i];
        }
        cout << output << endl;
    }
    return 0;
}
