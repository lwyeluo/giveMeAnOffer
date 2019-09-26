#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <limits.h>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int a = 0, int b = 0) {x = a; y = b;}
};

// the length from two vertices
float length(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// calculate the shorest path
//   @matrix
//   @src: the source vertex
//   @dst: the target vertex
float shortestPath(vector<vector<float> >& matrix, int src, int dst) {
    int n = matrix.size() - 1;
    vector<bool> visited(n + 1, false);
    vector<float> path(n + 1, INT_MAX); // the shortest path for all vertices

    // for the vertices directly linked to the src
    visited[src] = true;
    for(int i = 1; i <= n; i ++) {
        path[i] = matrix[src][i];
    }
    // main loop
    for(int i = 1; i <= n; i ++) {
        // serach the shortest vertex
        int idx = -1; int value = INT_MAX;
        for(int j = 1; j <= n; j ++) {
            if(!visited[j] && path[j] != INT_MAX && path[j] < value) {
                value = path[j];
                idx = j;
            }
        }
        if(idx == -1)
            return path[dst];
        visited[idx] = true;
        // update path
        for(int k = 1; k <= n; k ++) {
            if(!visited[k] && matrix[idx][k] != INT_MAX &&
                path[k] > matrix[idx][k] + path[idx]
            )
                path[k] = matrix[idx][k] + path[idx];
        }
    }
    return path[dst];
}

int main() {
    int n, m;
    while(scanf("%d", &n) != EOF) {
        int src, dst; // the source and destination

        vector<Point> vertex;
        vertex.push_back(Point(0, 0));

        vector<vector<float> > matrix(n + 1);
        for(int i = 0; i < matrix.size(); i ++) {
            matrix[i].resize(n + 1);
            for(int j = 0; j < matrix[i].size(); j ++) {
                matrix[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
        // read V
        for(int i = 1; i <= n; i ++) {
            Point data;
            scanf("%d %d", &data.x, &data.y);
            vertex.push_back(data);
        }
        // read E and set the matrix
        scanf("%d", &m);
        for(int i = 0; i < m; i ++) {
            int a, b;
            scanf("%d %d", &a, &b);
            matrix[a][b] = matrix[b][a] = length(vertex[a], vertex[b]);
        }
        // read the source and destination
        scanf("%d %d", &src, &dst);
        // calculate the shorest path
        printf("%.2f\n", shortestPath(matrix, src, dst));
    }
    return 0;
}
