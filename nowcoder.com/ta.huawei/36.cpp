#include <stdio.h>
#include <string.h>

void encrypt(char * key, char * data, char * encrypt) {
    char key_padding[26];
    bool exist[26];
    
    char inditor = 'a';
    if(key[0] <= 'Z' && key[0] >= 'A') inditor = 'A';
    
    memset(exist, false, sizeof(exist));
    int k = 0;
    for(size_t i = 0; i < strlen(key); i ++) {
        int alpha = key[i] - inditor;
        if(!exist[alpha]) {
            exist[alpha] = true;
            key_padding[k++] = key[i];
        }
    }
    int used_alpha = 0;
    for(int i = k; i < 26; i ++) {
        for(int j = used_alpha; j < 26; j ++)
            if(!exist[j]) {
                key_padding[i] = j + inditor;
                used_alpha = j + 1;
                break;
            }
    }
    
    for(size_t i = 0; i < strlen(data); i ++) {
        if(data[i] < inditor + 26 && data[i] >= inditor)
            encrypt[i] = key_padding[data[i] - inditor];
        else
            encrypt[i] = data[i];
    }
}

int main() {
    char key[2048], data[2048];
    while(scanf("%s", key) != EOF) {
        scanf("%s", data);
        char* result = new char[strlen(data) + 1];
        encrypt(key, data, result);
        printf("%s\n", result);
    }
    return 0;
}
