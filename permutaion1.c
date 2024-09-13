#include <stdio.h>
#include <string.h>

void generateString(char*set, int n, char*result, int k, int index){
    if(index == k){
        result[index] = '\0';
        printf("%s\n", result);
        return;
    }
    for(int i = 0 ; i < n ; i++){
        result[index] = set[i];
        generateString(set, n,result, k, index+1);
    }
}

int main(){
    char chars[21];
    int k;
    char current[11];
    scanf("%s", chars);
    scanf("%d", &k);
    int n = strlen(chars);
    generateString(chars, n, current, k, 0);
    return 0;
}