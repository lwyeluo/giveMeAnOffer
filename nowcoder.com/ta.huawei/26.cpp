#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        vector<string> vec_s(26, "");
        for(int i = 0; i < str.length(); i ++) {
            if(str[i] <= 'Z' && str[i] >= 'A')
                vec_s[str[i] - 'A'] += str[i];
            else if(str[i] <= 'z' && str[i] >= 'a')
                vec_s[str[i] - 'a'] += str[i];
        }
        // construct the string without special characters
        string str_no_spe = "";
        for(int i = 0; i < vec_s.size(); i ++)
            str_no_spe += vec_s[i];
        // insert special characters
        for(int i = 0, k = 0; i < str.length(); i ++)
            if((str[i] <= 'Z' && str[i] >= 'A') ||
              (str[i] <= 'z' && str[i] >= 'a'))
                str[i] = str_no_spe[k++];
        cout << str << endl;
    }
    return 0;
}
