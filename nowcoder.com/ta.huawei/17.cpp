/*
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
坐标之间以;分隔。

非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。

下面是一个简单的例子 如：
A10;S20;W10;D30;X;A1A;B10A11;;A10;
处理过程：
起点（0,0）

+   A10   =  （-10,0）
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  无效
+   A1A   =  无效
+   B10A11   =  无效
+  一个空 不影响
+   A10  =  (10,-10)

结果 （10， -10）
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int x, y;

void handlePos(string str) {
    if(str.length() != 2 && str.length() != 3)
        return;
    if(str[1] > '9' || str[1] < '0')
        return;
    int inc = 0;
    if(str.length() == 2)
        inc = str[1] - '0';
    else if(str[1] <= '9' && str[2] <= '9' && str[2] >= '0')
        inc = (str[1] - '0') * 10 + (str[2] - '0');
    if(inc == 0)
        return;
    //cout << "string is " << str << endl;
    if(str[0] == 'A') {
        x -= inc;
    } else if(str[0] == 'W') {
        y += inc;
    } else if(str[0] == 'D') {
        x += inc;
    } else if(str[0] == 'S') {
        y -= inc;
    }
    return;
}

int main() {
    string str;
    while(getline(cin, str)) {
        x = 0; y = 0;
        char* p = strtok(const_cast<char*>(str.c_str()), ";");
        while(p) {
            handlePos(string(p));
            p = strtok(NULL, ";");
        }
        printf("%d,%d\n", x, y);
    }
    return 0;
}
