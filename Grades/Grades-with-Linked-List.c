 #include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Score {
    int id;
    char name[10];
    int kor;
    int eng;
    int math;
    int sumScore;
    double avg;
    struct Score* next;
};

void addScore(struct Score* target, int id, char name[10], int kor, int eng, int math, int sumScore, double avg) {
    struct Score* newStudent = malloc(sizeof(struct Score));
    newStudent->next = target->next;

    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->kor = kor;
    newStudent->eng = eng;
    newStudent->math = math;
    newStudent->sumScore = sumScore;
    newStudent->avg = avg;

    target->next = newStudent;
}

void printAll(struct Score* target) {
    double avgKor = 0.0;
    double avgEng = 0.0;
    double avgMath = 0.0;
    int getScore = 0;
    double avgAll = 0.0;

    int i = 0;
    struct Score* ptr = target->next;
   
    printf("   학번     이름   국어   영어   수학   총점   평균\n");
    printf("====================================================\n");

    while (ptr != NULL) {
        avgKor += ptr->kor;
        avgEng += ptr->eng;
        avgMath += ptr->math;
        getScore += ptr->sumScore;
        avgAll += ptr->avg;
        i++;
        printf("%d %s %5d %5d %5d %7d % 7.1lf\n", ptr->id, ptr->name, ptr->kor, ptr->eng, ptr->math, ptr->sumScore, ptr->avg);
        ptr = ptr->next;
    }
    /*
    for (ptr = target->next; ptr != NULL; ptr->next) {
        avgKor += ptr->kor;
        avgEng += ptr->eng;
        avgMath += ptr->math;
        getScore += ptr ->sumScore;
        avgAll += ptr->avg;

        i++;

        printf("%d %s %5d %5d %5d %7d % 7.1lf\n",
          ptr->id, ptr->name, ptr->kor, ptr->eng, ptr->math, ptr->sumScore, ptr->avg);
        printf("12\n");
    }*/ 
    avgKor = avgKor / (i);
    avgEng = avgEng / (i);
    avgMath = avgMath / (i);
    avgAll = avgAll / (i);

    printf("====================================================\n");
    printf("          전체평균 % 4.1lf % 4.1lf % 4.1lf %7d % 7.1lf\n", avgKor, avgEng, avgMath, getScore, avgAll);
}

void freeAll(struct Score* target) {
    struct Score* curr = target->next;
    while (curr != NULL) {
        target->next = curr->next;
        free(curr);
        curr = target -> next;
    }
}

int main() {
    int i = 0;

    struct Score* head = malloc(sizeof(struct Score));
    struct Score set;

    head->next = NULL;

    while (1) {
        scanf("%d", &set.id);
        if (set.id == 0)
            break;
        scanf("%s", set.name);
        scanf("%d %d %d", &set.kor, &set.eng, &set.math);
        set.sumScore = (set.kor + set.eng + set.math);
        set.avg = (double)set.sumScore / 3;

        addScore(head, set.id, set.name, set.kor, set.eng, set.math, set.sumScore, set.avg);
        printAll(head);
    }

    freeAll(head);
    free(head);
}