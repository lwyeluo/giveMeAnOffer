/*
给定n个字符串，请对n个字符串按照字典序排列。
输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        priority_queue<string, vector<string>, greater<string> > myQueue;
        string str;
        getline(cin, str);
        while(n-- > 0) {
            getline(cin, str);
            myQueue.push(str);
        }
        while(!myQueue.empty()) {
            cout << myQueue.top() << endl;
            myQueue.pop();
        }
    }
    return 0;
}
