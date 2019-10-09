/*
解法1: f(m, n) = { f(m, n -1); if 有一个空盘时
                   f(m -n, n); if 没有空盘，也就是每个盘至少都放了一个苹果，所以苹果数为 m - n
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M < 1 || M>10 || N < 1 || N>10) {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++) dp[0][i] = 1;
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i - j][j]);
        cout << dp[M][N] << endl;
    }
}

/*
解法2: 直接dfs计算

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> methods;
vector<int> nums;
int m, n;

void placeApple(int remain, int k) {
    if(k == 1) {
        vector<int> ret;
        ret.assign(nums.begin(), nums.end());
        ret.push_back(remain);
        sort(ret.begin(), ret.end());
        string s = "";
        for(size_t i = 0; i < ret.size(); i ++)
            s = s + to_string(ret[i]) + "-";
        methods.insert(s);
        return;
    }
    for(int i = 1; i < remain; i ++) {
        nums.push_back(i);
        placeApple(remain - i, k - 1);
        nums.pop_back();
    }
}

int main() {
    while(scanf("%d %d", &m, &n) != EOF) {
        methods.clear();
        for(int i = 1; i <= n; i ++) {
            nums.clear();
            placeApple(m, i);
        }
        printf("%d\n", methods.size());
    }
    return 0;
}
*/
