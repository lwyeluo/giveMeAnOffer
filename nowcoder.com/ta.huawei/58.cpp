#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct cmp {
    bool operator()(int x, int y) {return x > y;}
};

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        priority_queue<int, vector<int>, cmp> q;
        int d;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &d);
            q.push(d);
        }
        string s = "";
        for(int i = 0; i < k && !q.empty(); i ++) {
            s = s + to_string(q.top()) + " ";
            q.pop();
        }
        cout << s.substr(0, s.length() - 1) << endl;
    }
}
