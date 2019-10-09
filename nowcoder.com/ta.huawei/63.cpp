#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int n;
    while(cin >> s >> n) {
        if(n == s.length()) {
            cout << s << endl;
            continue;
        } else if (n > s.length())
            continue;
        vector<int> v(s.length() - n + 1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i ++)
            if(s[i] == 'G' || s[i] == 'C')
                cnt ++;
        v[0] = cnt;
        
        int max = v[0], idx = 0;
        for(int i = 1; i <= s.length() - n; i ++) {
            int add = (s[i + n - 1] == 'G' || s[i + n - 1] == 'C') ? 1 : 0;
            int sub = (s[i - 1] == 'G' || s[i - 1] == 'C') ? 1 : 0;
            v[i] = v[i - 1] + add - sub;
            if(max < v[i]) {
                max = v[i];
                idx = i;
            }
        }
        cout << s.substr(idx, n) << endl;
    }
    return 0;
}
