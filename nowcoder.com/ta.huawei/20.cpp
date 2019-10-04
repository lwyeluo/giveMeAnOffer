#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

bool check(string passwd) {
    if(passwd.length() <= 8)
        return false;
    bool flag[4];
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < passwd.length(); i ++) {
        if(passwd[i] <= 'Z' && passwd[i] >= 'A')
            flag[0] = true;
        else if(passwd[i] <= 'z' && passwd[i] >= 'a')
            flag[1] = true;
        else if(passwd[i] <= '9' && passwd[i] >= '0')
            flag[2] = true;
        else
            flag[3] = true;
    }
    int type_cnt = 0;
    for(int i = 0; i < 4; i ++)
        type_cnt += flag[i];
    if(type_cnt < 3)
        return false;
    
    for(int i = 0; i < passwd.length() - 3; i ++) {
        string idx = passwd.substr(i, 3);
        if(passwd.substr(i + 3).find(idx) != string::npos)
            return false;
    }
    return true;
}

int main() {
    string passwd;
    while(getline(cin, passwd)) {
        if(check(passwd))
            printf("OK\n");
        else
            printf("NG\n");
    }
    return 0;
}
