#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getFileName(string path) {
    int pos = path.rfind("\\");
    if(path.length() - pos - 1 > 16)
        return path.substr(path.length() - 16);
    return path.substr(pos + 1);
}

struct Record {
    string path;
    string name;
    int cnt;
    int lineno;
    Record(string p, int line) {
        path = p;
        lineno = line;
        cnt = 1;
        name = getFileName(path);
    }
    bool operator==(const struct Record & a) {
        return (name == a.name) && (lineno == a.lineno);
    }
    void print() {
        cout << name << " " << lineno << " " << cnt << endl;
    }
};

int main() {
    string path;
    int lineno;
    vector<struct Record> vec;
    while(cin >> path >> lineno) {
        struct Record r(path, lineno);
        vector<struct Record>::iterator iter = find(vec.begin(), vec.end(), r);
        if(iter != vec.end()) {
            iter->cnt += 1;
        } else {
            vec.push_back(r);
        }
    }
    int start = vec.size() > 8 ? vec.size() - 8 : 0;
    for(; start < vec.size(); start ++) {
        vec[start].print();
    }
    return 0;
}
