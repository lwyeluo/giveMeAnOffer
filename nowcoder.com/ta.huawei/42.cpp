#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string english0_20[] = {
    "", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
    "eighteen", "nineteen", "twenty"
};
string english30_90[] = {
    "", "", "twenty",
    "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};
string englishDig[] = {
    "", "thousand", "million", "billion"
};

string intToStr(int num) {
    string str = "";
    if(num / 100 != 0) {
        str = str + english0_20[num / 100] + " hundred";
        if(num % 100 != 0)
            str += " and ";
    }
    num %= 100;
    if(num <= 20)
        str += english0_20[num];
    else if(num % 10 == 0) 
        str += english30_90[num / 10];
    else {
        str = str + english30_90[num / 10] + " " + english0_20[num % 10];
    }
    return str;
}

int main() {
    long num;
    while(scanf("%ld", &num) != EOF) {
        long value = num;
        int remain = 0, dig = 0;
        string result = "";
        while(value != 0) {
            remain = value % 1000;
            value /= 1000;
            result = intToStr(remain) + " " + englishDig[dig++] + " " + result;
        }
        cout << result << endl;
    }
    return 0;
}
