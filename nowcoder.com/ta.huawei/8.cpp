/*
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开

输出描述:
输出合并后的键值对（多行）

示例1
输入
4
0 1
0 2
1 2
3 4
输出
0 3
1 2
3 4
*/


#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        map<int, int> m_map;
        int k, v;
        while(n--) {
            scanf("%d %d", &k, &v);
            if(m_map.count(k) == 0)
                m_map[k] = v;
            else
                m_map[k] += v;
        }
        map<int, int>::iterator iter;
        for(iter = m_map.begin(); iter != m_map.end(); iter++) {
            printf("%d %d\n", iter->first, iter->second);
        }
    }
    return 0;
}
