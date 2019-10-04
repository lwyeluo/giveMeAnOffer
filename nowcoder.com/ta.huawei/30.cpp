#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

char convert(char in) {
    int num;
    if(in <= '9' && in >= '0')
        num = in - '0';
    else if(in <= 'F' && in >= 'A')
        num = in - 'A' + 10;
    else if(in <= 'f' && in >= 'a')
        num = in - 'a' + 10;
    else
        return in;
    
    int temp = num;
    int rev = 0, k = 0;
    while(k <= 3) {
        if(temp % 2 == 1)
            rev += pow(2, 3 - k);
        k ++;
        temp >>= 1;
    }
    
    if(rev <= 9)
        return '0' + rev;
    return 'A' + rev - 10;
}

int main() {
    //freopen("input.txt", "r", stdin);
    string str1, str2;
    while(cin >> str1 >> str2) {
        string str = str1 + str2;
        string odd_str = "", even_str = "";
        for(int i = 0; i < str.length(); i ++)
            if(i % 2 == 1)
                odd_str += str[i];
            else
                even_str += str[i];
        sort(odd_str.begin(), odd_str.end());
        sort(even_str.begin(), even_str.end());
        int j = 0, k = 0;
        for(int i = 0; i < str.length(); i ++)
            if(i % 2 == 1)
                str[i] = convert(odd_str[j++]);
            else
                str[i] = convert(even_str[k++]);
        cout << str << endl;
    }
    return 0;
}
