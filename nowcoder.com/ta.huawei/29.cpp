#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_LEN 105

void Encrypt (char aucPassword[], char aucResult[]) {
    int len = strlen(aucPassword);
    memset(aucResult, 0, MAX_LEN);
    for(int i = 0; i < len; i ++) {
        if(aucPassword[i] >= 'A' && aucPassword[i] <= 'Z') {
            aucResult[i] = (aucPassword[i] - 'A' + 1) % 26 + 'a';
        } else if(aucPassword[i] >= 'a' && aucPassword[i] <= 'z') {
            aucResult[i] = (aucPassword[i] - 'a' + 1) % 26 + 'A';
        } else if(aucPassword[i] >= '0' && aucPassword[i] <= '9') {
            aucResult[i] = (aucPassword[i] - '0' + 1) % 10 + '0';
        }
    }
}

int unEncrypt (char result[], char password[]) {
    int len = strlen(result);
    memset(password, 0, MAX_LEN);
    for(int i = 0; i < len; i ++) {
        if(result[i] >= 'A' && result[i] <= 'Z') {
            password[i] = (result[i] - 'A' + 25) % 26 + 'a';
        } else if(result[i] >= 'a' && result[i] <= 'z') {
            password[i] = (result[i] - 'a' + 25) % 26 + 'A';
        } else if(result[i] >= '0' && result[i] <= '9') {
            password[i] = (result[i] - '0' + 9) % 10 + '0';
        }
    }
    return len;
}

int main() {
    //freopen("input.txt", "r", stdin);
    char input[MAX_LEN], result[MAX_LEN];
    while(scanf("%s", input) != EOF) {
        Encrypt(input, result);
        printf("%s\n", result);
        scanf("%s", input);
        unEncrypt(input, result);
        printf("%s\n", result);
    }
    return 0;
}
