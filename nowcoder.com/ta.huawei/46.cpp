#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    while(cin >> s >> n) {
        if(s.length() < n)
            cout << s << endl;
        else if(s[n - 1] < 0)
            cout << s.substr(0, n - 1) << endl;
        else
            cout << s.substr(0, n) << endl;
    }
    return 0;
}
