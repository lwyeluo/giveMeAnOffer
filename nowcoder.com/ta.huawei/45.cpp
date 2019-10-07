#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    while(scanf("%d", &n) != EOF) {
        while(n --) {
            cin >> s;
            vector<int> cnt(26, 0);
            for(int i = 0; i < s.length(); i ++)
                cnt[s[i] - 'a'] ++;
            sort(cnt.begin(), cnt.end());
            int k = 26, sum = 0;
            for(size_t i = 25; i >= 0; i --) {
                if(cnt[i] == 0)
                    break;
                sum += k * cnt[i];
                k --;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
