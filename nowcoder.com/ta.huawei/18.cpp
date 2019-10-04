#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

struct OUTPUT {
    int o_a, o_b, o_c, o_d, o_e, o_err, o_pri;
    void print() {
        printf("%d %d %d %d %d %d %d\n", o_a, o_b, o_c, 
               o_d, o_e, o_err, o_pri);
    }
};

void check(char* in_ip, char* in_mask, struct OUTPUT* out) {
    int ip[4];
    int mask[4];
    int ret;
    ret = sscanf(in_ip, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    if(ret != 4) {
        out->o_err += 1;
        return;
    }
    ret = sscanf(in_mask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);
    if(ret != 4) {
        out->o_err += 1;
        return;
    }
    for(int i = 0; i < 4; i ++)
        if(ip[i] < 0 || ip[i] > 255 || mask[i] < 0 || mask[i] > 255) {
            out->o_err += 1;
            return;
        }
    if(mask[3] == 255) {
        out->o_err += 1;
        return;
    }
    // check mask
    for(int i = 3; i >= 0; i --) {
        if(mask[i] != 0) {
            // previous mask must be 255
            for(int j = i - 1; j >= 0; j --) {
                if(mask[j] != 255) {
                    out->o_err += 1;
                    return;
                }
            }
            // current mask must be legal
            int temp = mask[i], cnt = 0;
            while((temp & 0x1) == 0) {
                temp >>= 1;
                cnt += 1;
            }
            if(temp != pow(2, 8 - cnt) - 1) {
                out->o_err += 1;
                return;
            }
            break;
        }
    }
    
    // count
    if(ip[0] == 10)
        out->o_pri += 1;
    else if(ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31)
        out->o_pri += 1;
    else if(ip[0] == 192 && ip[1] == 168)
        out->o_pri += 1;

    if(ip[0] >= 1 && ip[0] < 127)
        out->o_a += 1;
    else if(ip[0] >= 128 && ip[0] < 192)
        out->o_b += 1;
    else if(ip[0] >= 192 && ip[0] < 224)
        out->o_c += 1;
    else if(ip[0] >= 224 && ip[0] < 240)
        out->o_d += 1;
    else if(ip[0] >= 240)
        out->o_e += 1;
    return;
}

int main() {
    //freopen("input.txt", "r", stdin);
    char ip[20], mask[20];
    struct OUTPUT out;
    memset(&out, 0, sizeof(out));
    while(scanf("%[^~]s", ip) != EOF && scanf("~%s", mask) != EOF) {
        check(ip, mask, &out);
    }
    out.print();
    return 0;
}
