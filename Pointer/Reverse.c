#include <stdio.h>

void reverse(char str[])
{
    int i = 0;
    char temp[100] = "";
    for (i = 0; i < strlen(str); i++)
        temp[i] = str[strlen(str)-i-1];
    for (i = 0; i < strlen(temp); i++)
        str[i] = temp[i];
}

int main()
{
    char str[21];
    
    printf("문자열을 입력하세요: ");
    scanf("%s", str);
    
    reverse(str);
    
    printf("뒤집힌 문자열: %s\n", str);
}