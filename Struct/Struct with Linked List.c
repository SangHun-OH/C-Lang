#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct Point {
	double x;
	double y;
	struct Point* next;
} Point;

typedef struct  Polygon {
	struct Point *pt;
	int32_t num_pts;
} Polygon;
/*
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
*/
int main()
{
	Polygon poly;
	//Point *head;
	double a, b;
	int i;
	double length= 0.0;
	char flag;
	int flag2=0;

	//poly.pt = NULL;
	poly.pt = (Point*)malloc(sizeof(Point));
	poly.pt ->next = NULL;
	poly.num_pts = 0;

	Point* sel = poly.pt;

	for (i = 0; i < 10; i++) {
		printf("값을 입력 : ");
		scanf("%lf %lf", &a, &b);

		if (a == -1) {
			break;
		}
		if (flag2==0) {
			flag2 = 1;
			poly.pt->x = a;
			poly.pt->y = b;
			//printf("여기접근\n");
		}
		else {
			//printf("정상접근\n");
			Point *curr = (Point*)malloc(sizeof(Point));
			curr->x = a;
			curr->y = b;
			curr->next = NULL;
			sel->next = curr;
			sel = curr;
		//	printf("정상접근내부 : (%.2lf, %.2lf)\n", curr->x, curr->y);
		}
		poly.num_pts++;
	}
	printf("num_pts 의 개수 : %d\n", poly.num_pts);
	
	Point* ptr;
	for (ptr = poly.pt; ptr != NULL; ptr = ptr->next) {
		printf("(%.2lf, %.2lf)\n", ptr->x, ptr->y);
	}

	ptr = poly.pt;

	for (i = 0; i < poly.num_pts; i++) {
		if (ptr->next == NULL)
			length += sqrt(pow((ptr->x - poly.pt->x), 2) + pow((ptr->y - poly.pt->y), 2));
		else
			length += sqrt(pow((ptr->x - ptr->next->x), 2) + pow((ptr->y - ptr->next->y), 2));

		ptr = ptr->next;
	}
	printf("%d 각형의 둘레는 %lf 입니다.\n", poly.num_pts, length);

	/*
	ptr = (Point*)malloc(sizeof(Point));
	ptr = poly.pt;

	while (ptr != NULL){
		printf("(%.2lf, %.2lf)\n", ptr->x, ptr->y);
		ptr = ptr->next;
	}*/
		
	/*

	

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
	}*/
}
