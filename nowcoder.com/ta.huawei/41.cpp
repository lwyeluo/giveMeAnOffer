#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int t;
        vector<int> weight, num;
        set<int> result;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &t);
            weight.push_back(t);
        }
        for(int i = 0; i < n; i ++) {
            scanf("%d", &t);
            num.push_back(t);
        }
        int sum = 0;
        result.insert(0);
        for(int i = 0; i < n; i ++) {
            set<int> tmp_set;
            for(int j = 1; j <= num[i]; j ++)
                for(auto iter = result.begin(); iter != result.end(); iter ++)
                    tmp_set.insert(*iter + weight[i] * j);
            for(auto iter = tmp_set.begin(); iter != tmp_set.end(); iter ++)
                result.insert(*iter);
        }
        printf("%d\n", result.size());
    }
    return 0;
}
