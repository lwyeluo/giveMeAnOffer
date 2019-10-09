#include <iostream>
#include <string>

using namespace std;

void mp3(string s, int n) {
    if(n < 4) {
        int cur = 0;
        for(size_t i = 0; i < s.length(); i ++) {
            if(s[i] == 'U') 
                cur = (cur + n - 1) % n;
            else if(s[i] == 'D')
                cur = (cur + 1) % n;
        }
        for(int i = 1; i < n; i ++)
            cout << i << " ";
        cout << n << endl << cur + 1 << endl;
        return;
    }
    
    int start = 1, end = 4, cur = 1;
    for(size_t i = 0; i < s.length(); i ++) {
        if(s[i] == 'U') {
            if(start < cur) cur--;
            else { // 翻页
                if(start != 1) {
                    start--; end--; cur--;
                } else {
                    start = n - 3; end = n; cur = n;
                }
            }
        } else if(s[i] == 'D') {
            if(end > cur) cur++;
            else {
                if(end != n) {
                    start++; end++; cur++;
                } else {
                    start = 1; end = 4; cur = 1;
                }
            }
        }
    }
    for(int i = start; i < end; i ++)
        cout << i << " ";
    cout << end << endl << cur << endl;
}

int main() {
    int n;
    string s;
    while(cin >> n >> s) {
        mp3(s, n);
    }
    return 0;
}
