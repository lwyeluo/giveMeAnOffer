#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    while(scanf("%d", &n) != EOF) {
        string s;
        vector<string> dict;
        while(n--) {
            cin >> s;
            dict.push_back(s);
        }
        sort(dict.begin(), dict.end());
        
        string target;
        int idx;
        cin >> target >> idx;
        
        string target_bac = target;
        sort(target.begin(), target.end());
        
        int num_bro = 0;
        string str_find = "";
        for(int i = 0; i < dict.size(); i ++) {
            string str = dict[i];
            if(str == target_bac)
                continue;
            sort(str.begin(), str.end());
            if(target == str) {
                num_bro ++;
                if(num_bro == idx)
                    str_find = dict[i];
            }
        }
        cout << num_bro << endl;
        if(str_find != "")
            cout << str_find << endl;
    }
    return 0;
}
