#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string str1, str2;
    while(cin >> str1 >> str2) {
        int n = str1.length(), m = str2.length();
        int ic = 1, dc = 1, rc = 1;
        vector<vector<int> > vec_cost(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i ++)
            vec_cost[i][0] = dc * i;
        for(int j = 1; j <= m; j ++)
            vec_cost[0][j] = ic * j;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                vec_cost[i][j] = min(vec_cost[i - 1][j] + dc,
                                    vec_cost[i][j - 1] + ic);
                if(str1[i - 1] == str2[j - 1])
                    vec_cost[i][j] = min(vec_cost[i][j],
                                        vec_cost[i - 1][j - 1]);
                else
                    vec_cost[i][j] = min(vec_cost[i][j],
                                        vec_cost[i - 1][j - 1] + rc);
            }
        }
        printf("%d\n", vec_cost[n][m]);
    }
    return 0;
}
