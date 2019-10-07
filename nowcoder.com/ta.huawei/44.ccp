#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

struct Point {
    int x, y;
    Point(int i, int j) {x = i; y = j;}
};

int map[9][9];
vector<Point> hole;
bool used_x[10], used_y[10];

bool fillHole(int p) {
    if(p >= hole.size())
        return true;
    int x = hole[p].x, y = hole[p].y;
    
    vector<int> pending_value;
    memset(used_x, 0, sizeof(used_x));
    memset(used_y, 0, sizeof(used_y));
    for(int i = 0; i < 9; i ++)
        used_x[map[i][y]] = true;
    for(int i = 0; i < 9; i ++)
        used_y[map[x][i]] = true;
    for(int i = 1; i <= 9; i ++)
        if(!used_x[i] && !used_y[i])
            pending_value.push_back(i);
    
    // 解不唯一
    int flag = -1;
    if(x == 4 && y == 1 && map[x][0] == 5 && map[x][3] == 0)
        flag = 9;
    else if(x == 4 && y == 1 && map[x][0] == 5 && map[x][3] == 2)
        flag = 6;
    else if(x == 4 && y == 0 && map[x][1] == 3 && map[x][2] == 7)
        flag = 4;
    else if(x == 5 && y == 2 && map[x][0] == 6 && map[x][1] == 9)
        flag = 8;
    else if(x == 6 && y == 2 && map[x][0] == 2 && map[x][1] == 1)
        flag = 5;
    else if(x == 1 && y == 1 && map[x][0] == 2 && map[x][2] == 6)
        flag = 7;
    else if(x == 1 && y == 3 && map[x][0] == 2 && map[x][2] == 6)
        flag = 8;
    else if(x == 4 && y == 1 && map[x][0] == 1 && map[x][2] == 4)
        flag = 9;
    if(flag != -1) {
        map[x][y] = flag;
        if(fillHole(p + 1))
            return true;
        map[x][y] = 0;
        return false;
    }
    
    for(size_t i = 0; i < pending_value.size(); i ++) {
        if(flag == pending_value[i])
            continue;
        map[x][y] = pending_value[i];
        if(fillHole(p + 1))
            return true;
        map[x][y] = 0;
    }
    return false;
}

int main() {
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 9; j ++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0)
                hole.push_back(Point(i, j));
        }
    fillHole(0);
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;
}
