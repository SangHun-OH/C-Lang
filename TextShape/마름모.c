#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num;

	scanf("%d", &num);

	if (num > 30) {
		printf("너무 큽니다.");
		return 0;
	}
	
	if (num % 2 == 0) {
		for (int i = 0; i < num / 2; i++) {
			for (int j = num / 2 - 1; j > i; j--) {
				printf(" ");
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				if (j == 0 || j == 2*i)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		for (int i = 0; i <num / 2; i++) {
			for (int j = 0; j < i; j++) {
				printf(" ");
			}
			for (int j = 2 * num/2 - 1; j > 2*i; j--) {
				if (j == 2 * num / 2 - 1 || j == 2 * i +1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < (num+1) / 2; i++) {
			for (int j = (num+1) / 2 - 1; j > i; j--) {
				printf(" ");
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				if (j == 0 || j == 2 * i)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
		for (int i = 0; i < num / 2 ; i++) {
			for (int j = 0; j < i+1; j++) {
				printf(" ");
			}
			for (int j = 2 * num / 2 - 2; j > 2 * i; j--) {
				if (j == 2 * num / 2 - 2 || j == 2 * i + 1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}