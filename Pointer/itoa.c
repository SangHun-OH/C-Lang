#include <stdio.h>
#include <string.h>

void i_to_a(int from, char to[])
{
    int i = 0;
    int a = 10;
    int dnum;
    int tnum;
    char temp[20] = "";
    int count = 0;
    
    if (from == 0){
        temp[i] = '0';
        count++;
    }
    else if(from < 0){
        tnum=(-from);
        for (i = 0; tnum > 0; i++){
        dnum = tnum % a;
        temp[i] = dnum + '0';
        tnum = tnum / a;
        count ++;
        }
        temp[count] = '-';
        count ++;
    }
    else {
        for (i = 0; from > 0; i++){
            dnum = from % a;
            temp[i] = dnum + '0';
            from = from / a;
            count ++;
        }
    }
    
    for (i = 0; i < count; i++)
        to[i] = temp[strlen(temp)-i-1];
    to[count] = NULL;
}

int main()
{
    int num;
    char str[20]="";
    
    printf("정수를 입력하시오: ");
    scanf("%d", &num);
    
    i_to_a(num, str);
    
    printf("결과값: %s\n", str);
}