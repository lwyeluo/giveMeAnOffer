/*
计算字符串最后一个单词的长度，单词以空格隔开。
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_LEN 2048

int main() {
    string str;
    getline(cin, str);
    size_t len = str.length();
    for (int i = len - 1; i >= 0; i --) {
    	if(str[i] == ' ') {
    	    cout << (len - i - 1) << endl;
            return 0;
    	}
    }
    cout << len << endl;
    return 0;
}
