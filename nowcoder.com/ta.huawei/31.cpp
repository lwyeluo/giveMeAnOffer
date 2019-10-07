#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    char word[25], empty[25];
    string s = "";
    scanf("%[^A-Za-z]", empty);
    while(scanf("%[A-Za-z]", word) != EOF) {
        scanf("%[^A-Za-z]", empty);
        //printf("%s\n", word);
        s = string(word) + " " + s;
    }
    cout << s.substr(0, s.length() - 1) << endl;
    return 0;
}

/*
// 解法2
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    char word[25], empty[25];
    string s = "";
    while(getline(cin, s)) {
        string temp = "";
        vector<string> vec_w;
        for(int i = 0; i < s.length(); i ++) {
            if((s[i] <= 'Z' && s[i] >= 'A') ||
                (s[i] <= 'z' && s[i] >= 'a'))
                temp += s[i];
            else {
                if(temp.length() > 0) {
                    vec_w.push_back(temp);
                    temp = "";
                }    
            }
        }
        if(temp.length() > 0)
            vec_w.push_back(temp);
        if(vec_w.size() == 0)
            continue;
        for(int i = vec_w.size() - 1; i > 0; i --)
            cout << vec_w[i] << " ";
        cout << vec_w[0] << endl;
    }
    return 0;
}
*/
