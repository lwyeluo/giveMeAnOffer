/*
购物车

通过率90%
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

#define MAX_MONEY (32000 + 5)
#define MAX_THING (60 + 5)
#define max(a, b) (a > b ? a : b)

int money, m;
bool flag[MAX_THING][MAX_MONEY];

//#define DEBUG
//#define WithPath

#ifdef WithPath
int dp[MAX_THING][MAX_MONEY];

int solve(vector<int>& v, vector<int>& p, vector<int>& q) {
    memset(dp, 0, sizeof(dp));
    memset(flag, false, sizeof(flag));
    for(int i = v[0]; i <= money; i ++) {
        dp[0][i] = v[0] * p[0];
    }
    for(int i = 1; i < v.size(); i ++) {
        for(int d = 0; d < v[i]; d++) //二维数组时 要记得赋值
            dp[i][d] = dp[i-1][d]; 
        for(int d = money; d >= v[i]; d --) {
            // 主件
            if(q[i] == 0) {
                if(dp[i - 1][d] < dp[i - 1][d - v[i]] + v[i] * p[i]) {
                    dp[i][d] = dp[i - 1][d - v[i]] + v[i] * p[i];
                    flag[i][d] = true;
                } else
                    dp[i][d] = dp[i - 1][d];
            }
            // 附件
            else {
                if(flag[q[i]-1][d - v[i]] && dp[i - 1][d] < dp[i - 1][d - v[i]] + v[i] * p[i]) {
                    dp[i][d] = dp[i - 1][d - v[i]] + v[i] * p[i];
                } else
                    dp[i][d] = dp[i - 1][d];
            }
        }
        #ifdef DEBUG
            printf("Round %d, result %d\n", i, dp[i][money]);
        #endif
    }
#ifdef DEBUG
    int cur_money = money;
    for(int i = v.size() - 1; i >= 1; i --) {
        if(dp[i][cur_money] != dp[i - 1][cur_money]) {
            printf("%d [%d, %d] is added\n", i, v[i], p[i]);
            cur_money -= v[i];
        }
    }
#endif
    return dp[v.size() - 1][money];
}
#else
int dp[MAX_MONEY];
int solve(vector<int>& v, vector<int>& p, vector<int>& q) {
    memset(dp, 0, sizeof(dp));
    memset(flag, false, sizeof(flag));
    for(int i = v[0]; i <= money; i ++) {
        dp[i] = v[0] * p[0];
    }
    for(int i = 1; i < v.size(); i ++) {
        for(int d = money; d >= v[i]; d --) {
            if(q[i] == 0) {
                // 主件
                if(dp[d] < dp[d - v[i]] + v[i] * p[i]) {
                    dp[d] = dp[d - v[i]] + v[i] * p[i];
                    flag[i][d] = true;
                }
            } else {
                // 附件
                if(dp[d] < dp[d - v[i]] + v[i] * p[i] && flag[q[i] - 1][d - v[i]])
                    dp[d] = dp[d - v[i]] + v[i] * p[i];
            }
        }
#ifdef DEBUG
        printf("Round %d, value=%d\n", i, dp[money]);
#endif
    }
    return dp[money];
}
#endif

int main () {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    while(scanf("%d %d", &money, &m) != EOF) {
        vector<int> vec_v, vec_p, vec_q;
        int v, p, q;
        while(m-- > 0) {
            scanf("%d %d %d", &v, &p, &q);
            vec_v.push_back(v);
            vec_p.push_back(p);
            vec_q.push_back(q);
        }
        int value = solve(vec_v, vec_p, vec_q);
        printf("%d\n", value);
    }
    return 0;
}
