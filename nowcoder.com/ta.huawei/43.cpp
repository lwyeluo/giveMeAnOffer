#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
bool map[12][12];
bool visited[12][12];

struct Path{
    int x, y;
    Path(int i, int j) {x = i; y = j;}
};
vector<Path> path;
vector<Path> path_best;

void dfs(int i, int j) {
    if(i == n - 1 && j == m - 1) {
        if(path_best.size() == 0 || path.size() + 1 < path_best.size()) {
            path_best.clear();
            path_best.assign(path.begin(), path.end());
        }
        return;
    }
    visited[i][j] = true;
    path.push_back(Path(i, j));
    if(i + 1 < n && !visited[i + 1][j] && !map[i + 1][j])
        dfs(i + 1, j);
    if(i - 1 >= 0 && !visited[i - 1][j] && !map[i - 1][j])
        dfs(i - 1, j);
    if(j + 1 < m && !visited[i][j + 1] && !map[i][j + 1])
        dfs(i, j + 1);
    if(j - 1 >= m && !visited[i][j - 1] && !map[i][j - 1])
        dfs(i, j - 1);
    path.pop_back();
    visited[i][j] = false;
    return;
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        int d;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        path.clear();
        path_best.clear();
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                scanf("%d", &d);
                map[i][j] = d;
            }
        }
        visited[0][0] = true;
        dfs(0, 0);
        for(size_t i = 0; i < path_best.size(); i ++)
            printf("(%d,%d)\n", path_best[i].x, path_best[i].y);
        printf("(%d,%d)\n", n - 1, m - 1);
    }
    return 0;
}
