#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calcLIS(vector<int>& q, vector<int>& rank) {
    for(int i = 1; i < rank.size(); i ++)
        for(int j = 0; j < i; j ++)
            if(q[j] < q[i] && rank[i] < rank[j] + 1)
                rank[i] = rank[j] + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF) {
        int num;
        vector<int> q;
        vector<int> rank(n, 1), de_rank(n, 1);
        while(n--) {
            scanf("%d", &num);
            q.push_back(num);
        }
        calcLIS(q, rank);
        reverse(q.begin(), q.end());
        calcLIS(q, de_rank);
        reverse(de_rank.begin(), de_rank.end());
        int max_rank = 0;
        for(int i = 0; i < q.size(); i ++) {
            int d = rank[i] + de_rank[i] - 1;
            if(max_rank < d)
                max_rank = d;
        }
        printf("%d\n", q.size() - max_rank);
    }
    return 0;
}
