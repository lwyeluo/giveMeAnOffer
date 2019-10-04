#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        string ciper = "";
        for(int i = 0; i < str.length(); i ++) {
            if(str[i] >= 'A' && str[i] < 'Z')
                ciper += str[i] - 'A' + 'a' + 1;
            else if(str[i] == 'Z')
                ciper += 'a';
            else if(str[i] >= 'a' && str[i] < 's')
                ciper += (str[i] - 'a') / 3 + '2';
            else if(str[i] >= 's' && str[i] < 'z')
                ciper += (str[i] - 'b') / 3 + '2';
            else if(str[i] == 'z')
                ciper += '9';
            else if(str[i] >= '0' && str[i] <= '9')
                ciper += str[i];
        }
        cout << ciper << endl;
    }
    return 0;
}
