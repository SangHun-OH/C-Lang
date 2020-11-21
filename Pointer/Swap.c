#include <stdio.h>

// 아래 함수를 선언부를 포함하여 수정하시오
int swap(int *a, int *b)
{
    int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    
    printf("두 정수를 입력하세요: ");
    
    scanf("%d%d", &a, &b);
    
    // 아래 함수 호출문도 필요시 수정하시오
    swap(&a, &b);
    
    printf("교환된 값: %d %d\n", a, b);
}