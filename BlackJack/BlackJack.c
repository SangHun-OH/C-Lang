#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
    char card_name[3];
    int sum = 0;
    int val = 0;
    int count = 0;
    while (sum < 17) {

        printf("카드이름을 입력하세요 : ");
        scanf("%2s", card_name);

        switch (card_name[0]) {
        case 'K':
            val = 10;
            break;
        case 'Q':
            val = 10;
            break;
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            count++;
            break;
        default:
            val = atoi(card_name);
            if (val < 2 || val > 10) {
                printf("2~10 숫자와 K, Q, J, A 만 입력가능!\n");
                continue;
            }
        }

        sum = sum + val;

        if (sum > 21) {
            if (count == 0) {
                printf("누적가치 : %d\n", sum);
                printf("파산하였습니다.\n");
                continue;
            }
            else {
                sum = sum - 10;
                count--;
            }
        }
        printf("누적가치 : %d\n", sum);

        if (sum >= 17 && sum <= 21)
            printf("딜을 마칩니다.\n");
    }
}