#include <stdio.h>
#include "factor.h"
#pragma warning(disable: 4996)

int main() {
    int factorsA[100][2];
    int factorsC[100][2];// 인수 쌍을 담을 배열
    int a, b, c;
    int flag = 0;

    printf("a를 입력하세요:");
    scanf("%d", &a);
    printf("b를 입력하세요:");
    scanf("%d", &b);
    printf("c를 입력하세요:");
    scanf("%d", &c);

    // 결과 출력
    int count_a = factorize(a, factorsA);

    printf("a의 가능한 인수조합: %d쌍\n", count_a);

    for (int i = 0; i < count_a; i++) {
        printf("%d %d\n", factorsA[i][0], factorsA[i][1]);
    }

    int count_c = factorize(c, factorsC);

    printf("c의 가능한 인수조합: %d쌍\n", count_c);

    for (int i = 0; i < count_c; i++) {
        printf("%d %d\n", factorsC[i][0], factorsC[i][1]);
    }
 
    printf("원래식 : %2ix^2 %+2ix %+2i = 0\n", a, b, c);

    for (int i = 0; i < count_a; i++) {
        for (int j = 0; j < count_c; j++) {
            int adbc = factorsA[i][0] * factorsC[j][1] + factorsA[i][1] * factorsC[j][0];
            if ( adbc == b) {
                printf("(%ix %+i)(%ix %+i)\n", factorsA[i][0] , factorsC[j][0], factorsA[i][1], factorsC[j][1]);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("인수분해 불가능\n");
    
    //(ax + b)(cx + d) =  ac x ^ 2 + (ad + bc)x + bd
    
    double d = b * b - 4.0 * a * c;

    if (d > 0 && flag == 1) {
        double e = mysqrt(d);
        double oi = (-b + e) / (2.0 * a);
        double ti = (-b - e) / (2.0 * a);

        printf("근:\n x = %f \n x = %f\n", oi, ti);
       
    }
    else if (d == 0 && flag==1)
        printf("%f \n", (-b) / (2.0 * a));
}