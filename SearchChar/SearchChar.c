#include <stdio.h>
#include <string.h>

int main()
{
    char chs[100];
    char haystack[1000];
    char* token;
    int find = 0;
    int i = 0;

    fgets(chs, 99, stdin);
    fgets(haystack, 999, stdin);

    while (chs[i]){
        if (chs[i] >= 'A' && chs[i] <= 'Z')
            chs[i] = chs[i] + 32;
        i++;
    }
    i = 0;
    while (haystack[i]){
        if (haystack[i] >= 'A' && haystack[i] <= 'Z')
            haystack[i] = haystack[i] + 32;
        i++;
    }
    haystack[strlen(haystack)-1] = '\0';
    int len = strlen(chs);
    
    for (token = strtok(haystack, " ,./-:"); token !=NULL; token = strtok(NULL, " ,./-:")){
        for (i = 0; i < len; i++){
            if (strchr(token, chs[i]) != NULL){
                find = 1;
            }
        }
        if (find == 1){
            printf("%s\n", token);
            find = 0;
        }
    }
}
