#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string calc(string s1, string s2, bool isAdd) {
    int n = s1.length(), m = s2.length();
    for(int i = 1; i <= n - m; i ++)
        s2 = string("0") + s2;
    for(int i = 1; i <= m - n; i ++)
        s1 = string("0") + s1;
    int len = max(n, m);
    int inc = 0, tmp = 0;
    string res = "";
    for(int i = len - 1; i >= 0; i --) {
        tmp = isAdd ? s1[i] + s2[i] - 2 * '0' + inc : s1[i] - s2[i] - inc;
        if(tmp < 0) {
            int t = 0 - tmp;
            inc = t / 10 + 1;
            res = to_string(t % 10) + res;
        } else if(tmp >= 10) {
            inc = tmp / 10;
            res = to_string(tmp % 10) + res;
        } else {
            inc = 0;
            res = to_string(tmp) + res;
        }
    }
    if(inc > 0) {
        if(isAdd)
            res = to_string(inc) + res;
        else
            res = string("-") + to_string(10-inc) + res;
    }
    return res;
}

int main() {
    string s1, s2;
    while(cin >> s1 >> s2) {
        string res = "";
        if(s1[0] == '-' && s2[0] == '-')
            res = res + "-" + calc(s1.substr(1), s2.substr(1), true);
        else if(s1[0] == '-')
            res = calc(s2, s1.substr(1), false);
        else if(s2[0] == '-')
            res = calc(s1, s2.substr(1), false);
        else
            res = calc(s1, s2, true);
        cout << res << endl;
    }
    return 0;
}
