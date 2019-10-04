#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findInI(vector<string>& vec_i, vector<int>& vec_r) {
    string out = "";
    int pos = 0, total = 0;
    for(int i = 0; i < vec_r.size(); i ++) {
        if(i > 0 && vec_r[i] == vec_r[i - 1])
            continue;
        string indictor = to_string(vec_r[i]);
        int cnt = 0;
        string temp = "";
        for(int j = 0; j < vec_i.size(); j ++) {
            pos = vec_i[j].find(indictor);
            if(pos != string::npos) {
                // find it
                cnt ++;
                temp = temp + " " + to_string(j) + " " + vec_i[j];
            }
        }
        if(cnt > 0) {
            out = out + " " + indictor + " " + to_string(cnt) + temp;
            total += (cnt + 1) * 2;
            //cout << "The " << i << "-th round: " << indictor + " " + to_string(cnt) + temp << endl;
        }
    }
    return to_string(total) + out;
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    while(scanf("%d", &n) != EOF) {
        vector<string> vec_i;
        vector<int> vec_r;
        int num;
        while(n--) {
            scanf("%d", &num);
            vec_i.push_back(to_string(num));
        }
        scanf("%d", &m);
        while(m--) {
            scanf("%d", &num);
            vec_r.push_back(num);
        }
        sort(vec_r.begin(), vec_r.end());
        cout << findInI(vec_i, vec_r) << endl;
    }
    return 0;
}
