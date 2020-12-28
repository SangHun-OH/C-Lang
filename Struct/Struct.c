#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef enum Color { RED, BLUE, YELLOW };

typedef struct Point {
	double x;
	double y;
} Point;

typedef struct  Polygon {
	Point pt[10];
	int32_t num_pts;
} Polygon;

void swap_points(Polygon* p, int a, int b) {
	Polygon temp;
	temp.pt[0] = p->pt[a];
	p->pt[a] = p->pt[b];
	p->pt[b] = temp.pt[0];
}

void swap_points_v2(Point* p1, Point* p2) {
	Point temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	Polygon poly;
	double a, b;
	int i;
	double length= 0.0;
	char flag;

	poly.num_pts = 0;

	for (i = 0; i < 10; i++) {
		printf("값을 입력 : ");
		scanf("%lf %lf", &a, &b);

		if (a == -1) {
			break;
		}

		poly.pt[i].x = a;
		poly.pt[i].y = b;
		poly.num_pts++;
	}
	printf("num_pts 의 개수 : %d\n", poly.num_pts);

	for (i = 0; i < poly.num_pts; i++) {
		printf("(%.2lf, %.2lf)\n", poly.pt[i].x, poly.pt[i].y);
	}

	for (i = 0; i < poly.num_pts; i++) {
		if (i == (poly.num_pts - 1)) 
			length += sqrt(pow((poly.pt[i].x - poly.pt[0].x), 2) + pow((poly.pt[i].y - poly.pt[0].y), 2));
		else
			length += sqrt(pow((poly.pt[i].x - poly.pt[i + 1].x), 2) + pow((poly.pt[i].y - poly.pt[i + 1].y), 2));
	}

	printf("%d 각형의 둘레는 %lf 입니다.\n", poly.num_pts, length);

	printf("점의 위치를 바꾸시겠습니까? : ");

	scanf("%c", &flag);
	scanf("%c", &flag);

	if (flag == 'y') {
		int f, s;
		printf("첫번째 점의 인덱스를 입력해주세요 : ");
		scanf("%d", &f);
		printf("두번째 점의 인덱스를 입력해주세요 : ");
		scanf("%d", &s);

		swap_points(&poly, f, s);
	}

	if (flag == 'Y') {
		int f, s;
		printf("첫번째 점의 인덱스를 입력해주세요 : ");
		scanf("%d", &f);
		printf("두번째 점의 인덱스를 입력해주세요 : ");
		scanf("%d", &s);

		swap_points_v2(&poly.pt[f], &poly.pt[s]);
	}

	printf("다각형 점의 목록은 다음과 같습니다\n");
	for (i = 0; i < poly.num_pts; i++) {
		printf("(%.2lf, %.2lf)\n", poly.pt[i].x, poly.pt[i].y);
	}
}
