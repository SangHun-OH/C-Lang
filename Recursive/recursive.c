#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void drawTri(int input, int blank) {
	int star;
	if (input == 1) {
		star = 1;
	}
	else {
		star = input;
		drawTri(input - 1, blank + 1);
	}
	for (int i = 0; i < blank; i++) {
		printf(" ");
	}
	for (int i = 0; i < star*2-1; i++) {
		printf("*");
	}
	printf("\n");
}
int fibo(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else return fibo(num - 1) + fibo(num - 2);
}

int factorial(int num) {
	if (num == 1)
		return 1;
	else
		return num*factorial(num - 1);
}

int main() {
	int input;
	char ftest[10];

	printf("삼각형의 높이 입력 : ");
	scanf("%d", &input);

	drawTri(input, 0);

	return 0;
}