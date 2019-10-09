#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            if(i % 7 == 0)
                cnt ++;
            else {
                string s = to_string(i);
                if(s.find("7") != string::npos)
                    cnt ++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
