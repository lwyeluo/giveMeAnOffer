#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool check(string s) {
    unsigned long ip_long;
    unsigned short ip_arr[4];
    int ret;
    if(s.find(".") == string::npos) {
        ret = sscanf(s.c_str(), "%lu", &ip_long);
        if(ret != 1) return false;
        for(int i = 3; i >= 0; i --) {
            ip_arr[i] = ip_long & 0xff;
            ip_long >>=8;
        }
        printf("%u.%u.%u.%u\n", ip_arr[0], ip_arr[1], ip_arr[2], ip_arr[3]);
    } else {
        ret = sscanf(s.c_str(), "%u.%u.%u.%u", &ip_arr[0], &ip_arr[1],
                         &ip_arr[2], &ip_arr[3]);
        if(ret != 4) return false;
        ip_long = ip_arr[0];
        for(int i = 1; i < 4; i ++) {
            ip_long <<= 8;
            ip_long += ip_arr[i];
        }
        printf("%lu\n", ip_long);
    }
    return true;
}

int main() {
    string s;
    while(getline(cin, s)) {
        check(s);
    }
    return 0;
}
