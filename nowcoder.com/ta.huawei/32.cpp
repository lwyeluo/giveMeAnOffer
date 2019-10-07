/*
解法1: manache算法
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    string s;
    while(getline(cin, s)) {
        // 扩充s
        string t = "$#";
        for(int i = 0; i < s.length(); i ++)
            t = t + s[i] + "#";
        vector<int> p(t.length(), 1);
        // 计算p
        int mx = 0, id = 0;
        int max_len = 0;
        for(int i = 1; i < t.length() - 1; i ++) {
            // 1. 初始化
            if(i < mx) p[i] = min(p[2 * id - i], mx - i);
            // 2. 向外扩充
            while(t[i - p[i]] == t[i + p[i]])
                p[i]++;
            // 3. 更新id，mx
            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            // 4. 更新最大长度
            max_len = max(max_len, p[i] - 1);
        }
        printf("%d\n", max_len);
    }
    return 0;
}

/*
解法2: 动态规划，o(n^2)，可能超时

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        vector<vector<bool> > my_vec(s.length(), vector<bool>(s.length(), false));
        int max = 0;
        for(int i = 0; i < s.length(); i ++) {
            for(int j = 0; j <= i; j ++) {
                if(i == j) my_vec[j][i] = 1;
                else if(i - j == 1) my_vec[j][i] = (s[i] == s[j]);
                else my_vec[j][i] = (s[i] == s[j]) && my_vec[j+1][i-1];
                if(my_vec[j][i] && i - j + 1 > max)
                    max = i - j + 1;
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
*/
