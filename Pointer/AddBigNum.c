#include <stdio.h>

char * add_big_number(char a[], char b[], char result[], int size)
{
    int carry = 0;
    int val = 0;
    int max = 0;
    int i, alen, blen;
    
    char numA[100] = "";
    char numB[100] = "";
    char buf[101] = "";

    alen = strlen(a);
    blen = strlen(b);
    
    for (i = 0; i < alen; i ++)
        numA[alen - i - 1] = a[i];
    for (i = 0; i < blen; i ++)
        numB[blen - i - 1] = b[i];
        
    max = alen;
    if (blen > alen)
        max = blen;
        
    carry = 0;
    
    for (i = 0; i < max; i++){
        if (numA[i] == NULL){
            val = (numB[i] - '0') + carry;
            carry = val / 10;
            buf[i] = val % 10 + '0';
        }
        else if (numB[i] == NULL){
            val = (numA[i] - '0') + carry;
            carry = val / 10;
            buf[i] = val % 10 + '0';
        }
        else {
            val = (numA[i] - '0') + (numB[i] - '0') + carry;
            carry = val/10;
            buf[i] = val%10 + '0';
        }
        
    }
    if (carry >0){
        buf[max] = carry + '0';
        max += 1;
    }
    
    for (i = 0; i < strlen(buf); i++){
        result[i] = buf[strlen(buf)-i-1];
    }
    
    return result;
}

int main()
{
    char a[100], b[100], buf[100];
    char *res;
    printf("첫 번째 자연수를 입력하시오:");
    scanf("%s", a);
    printf("두 번째 자연수를 입력하시오:");
    scanf("%s", b);
    res = add_big_number(a, b, buf, 100);
    printf("결과값: %s\n", res);
}