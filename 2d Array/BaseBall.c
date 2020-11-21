#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int inputNum[10][3];
    int S = 0;
    int B = 0;
    int seed;
    int comp_nums[3];
    int count;
    int jflag = 0;

    printf("난수 씨앗을 입력하시오: ");
    scanf("%d", &seed);
    srand(seed);

    comp_nums[0] = rand() % 9 + 1;

    do {
        comp_nums[1] = rand() % 9 + 1;
    } while (comp_nums[0] == comp_nums[1]);

    do {
        comp_nums[2] = rand() % 9 + 1;
    } while (comp_nums[0] == comp_nums[2] || comp_nums[1] == comp_nums[2]);

    for (int i = 0; i < 10; i++) {

        if (i == 9) {
            printf("패배\n");
            printf("복기는 다음과 같습니다.\n");
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (k == j && inputNum[i][j] == comp_nums[k]) {
                            printf("%dS ", inputNum[i][j]);
                            jflag = 1;
                        }
                        if (k != j && inputNum[i][j] == comp_nums[k]) {
                            printf("%dB ", inputNum[i][j]);
                            jflag = 1;
                        }
                    }
                    //for (int k = 0; k < 3; k++) {
                    if (jflag == 0 && inputNum[i][j] != comp_nums[j])
                        printf("%dX ", inputNum[i][j]);
                    jflag = 0;
                }
                if (i < count - 1)
                    printf("\n");
            }
            return 0;
        }
        count++;
        printf("숫자 배열을 맞춰 보세요 : ");
        for (int j = 0; j < 3; j++) {
            scanf("%d", &num);
            inputNum[i][j] = num;
        }
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == j) {
                    if (inputNum[i][j] == comp_nums[k]) {
                        S++;
                    }
                }
                else if (inputNum[i][j] == comp_nums[k]) {
                    B++;
                }
            }
        }
        if (S == 3) {
            printf("%dS\n", S);
            printf("승리하였습니다!\n");

            printf("복기는 다음과 같습니다.\n");
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        if (k == j && inputNum[i][j] == comp_nums[k]) {
                            printf("%dS ", inputNum[i][j]);
                            jflag = 1;
                        }
                        if (k != j && inputNum[i][j] == comp_nums[k]) {
                            printf("%dB ", inputNum[i][j]);
                            jflag = 1;
                        }
                    }
                    //for (int k = 0; k < 3; k++) {
                    if (jflag == 0 && inputNum[i][j] != comp_nums[j])
                        printf("%dX ", inputNum[i][j]);
                    jflag = 0;
                }
                if (i < count - 1)
                    printf("\n");
            }

            return 0;
        }
        printf("%dS %dB\n", S, B);
        S = 0;
        B = 0;
    }
}