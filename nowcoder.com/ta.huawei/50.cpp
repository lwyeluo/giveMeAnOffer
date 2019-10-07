#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include <map>
#include <set>

using namespace std;

stack<int> nums;
stack<char> sigs;
map<char, char> bracket = {{')', '('}, {']', '['}, {'}', '{'}};
set<char> leftBracket = {'{', '[', '('};

int core(int num1, int num2, char sig) {
    switch(sig) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
}

void calc() {
    int num1 = nums.top();
    nums.pop();
    int num2 = nums.top();
    nums.pop();
    char sig = sigs.top();
    sigs.pop();
    int ret = core(num2, num1, sig);
    //printf("-> calc: %d%c%d=%d\n", num2, sig, num1, ret);
    nums.push(ret);
}

int main() {
    string s;
    while(getline(cin, s)) {
        while(!nums.empty()) nums.pop();
        while(!sigs.empty()) sigs.pop();

        int i = 0;
        while(i < s.length()) {
            if(isdigit(s[i])) {
                int num;
                int j = i + 1;
                while(j < s.length() && isdigit(s[j])) { j++; }
                sscanf(s.substr(i, j - i).c_str(), "%d", &num);
                if((i == 1 && s[0] == '-') ||
                   (i > 1 && s[i - 1] == '-' && leftBracket.count(s[i - 2])))
                    num = 0 - num; // 负号处理
                nums.push(num);
                i = j;
                continue;
            } else if(s[i] == '-' && i > 1 && leftBracket.count(s[i - 1])) {
                i ++; // 这是负号，不在这里处理，直接忽略
                continue;
            } else if(bracket.count(s[i])) { // 括号
                while(!sigs.empty() && sigs.top() != bracket[s[i]])
                    calc();
                sigs.pop(); // 弹出左括号
                i ++;
                continue;
            } else if(s[i] == '+' || s[i] == '-') {
                while(!sigs.empty() && (sigs.top() == '*' || sigs.top() == '/'
                              || sigs.top() == '+' || sigs.top() == '-')
                     )
                    calc();
            } else if(s[i] == '*' || s[i] == '/') {
                while(!sigs.empty() && (sigs.top() == '*' || sigs.top() == '/'))
                    calc();
            }
            sigs.push(s[i]);
            i ++;
        }
        while(!sigs.empty())
            calc();
        printf("%d\n", nums.top());
    }
    return 0;
}
