#include <iostream>
#include <string>
#include <vector>

using namespace std;

void find(string s) {
    vector<int> v(26, 0);
    for(int i = 0; i < s.length(); i ++)
        v[s[i] - 'a'] ++;
    for(int i = 0; i < s.length(); i ++)
        if(v[s[i] - 'a'] == 1) {
            cout << s[i] << endl;
            return;
        }
    cout << -1 << endl;
}

int main() {
    string s;
    while(cin >> s) {
        find(s);
    }
    return 0;
}
