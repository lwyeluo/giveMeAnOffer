#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 0; i < s.length(); i ++) {
            if(s[i] <= 'Z' && s[i] >= 'A' ||
              (s[i] <= 'z' && s[i] >= 'a'))
                a ++;
            else if(s[i] == ' ')
                b ++;
            else if(s[i] <= '9' && s[i] >= '0')
                c ++;
            else
                d ++;
        }
        printf("%d\n%d\n%d\n%d\n", a, b, c, d);
    }
    return 0;
}
