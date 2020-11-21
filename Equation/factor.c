#include <stdio.h>
#include "factor.h"

int factorize(int num, int factors[][2]) {
    // TODO factors 배열에 인수분해 쌍을 넣고, 총 갯수를 리턴하세요.
    int count = 0;
    int j = 0;
    if (num > 1) {
        for (int i = 0; i < num / 2; i++) {
            if (i + 1 <= num / (i + 1)) {
                if (num % (i + 1) == 0) {

                    count += 2;
                    factors[j][0] = i + 1;
                    factors[j][1] = num / (i + 1);
                    factors[j + 1][0] = -(i + 1);
                    factors[j + 1][1] = -(num / (i + 1));

                    if ((i + 1) > num / (i + 1)) {
                        factors[j][0] = num / (i + 1);
                        factors[j][1] = i + 1;
                        factors[j + 1][0] = -(num / (i + 1));
                        factors[j + 1][1] = -(i + 1);
                    }
                    //     printf("factor의값은 : %d, %d\n", factors[j][0], factors[j][1]);
                    j += 2;
                }
            }
        }
    }
    else if (num == 1) {
        factors[0][0] = 1;
        factors[0][1] = 1;
        factors[1][0] = -1;
        factors[1][1] = -1;
        count += 2;
    }
    else if (num == -1) {
        factors[0][0] = 1;
        factors[0][1] = -1;
        factors[1][0] = -1;
        factors[1][1] = 1;
        count += 2;
    }

    else {
        for (int i = 0; i < -(num / 2); i++) {
            if (num % (i + 1) == 0) {
                if (-(i + 1) >= num / (i + 1)) {
                    count += 2;
                    factors[j][0] = i + 1;
                    factors[j][1] = num / (i + 1);
                    factors[j + 1][0] = -(i + 1);
                    factors[j + 1][1] = -(num / (i + 1));

                    if (-(i + 1) > num / -(i + 1)) {
                        factors[j][0] = num / (i + 1);
                        factors[j][1] = i + 1;
                        factors[j + 1][0] = -(num / (i + 1));
                        factors[j + 1][1] = -(i + 1);
                    }
                    //        printf("factor의값은 : %d, %d\n", factors[j][0], factors[j][1]);
                    j += 2;
                }
            }
        }
    }
    return count;
}

double mysqrt(double a){
    double x = 2.0;
    for (int i = 0; i<12; i++){
        x=(x+(a/x)) / 2;
    }
    
    return x;
}

