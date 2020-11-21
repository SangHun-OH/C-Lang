#include <stdio.h>

struct score{
    int id;
    char name[10];
    int kor;
    int eng;
    int math;
    int sumScore;
    double avg;
};

int main(){
    int i =0;
    struct score set[100];
    double avgKor = 0.0;
    double avgEng = 0.0;
    double avgMath =0.0;
    int getScore=0;
    double avgAll=0.0;
    
    while(1){
        scanf("%d", &set[i].id);
        if (set[i].id == 0)
            break;
        scanf("%s", set[i].name);
        scanf("%d %d %d",  &set[i].kor, &set[i].eng, &set[i].math);
        set[i].sumScore = (set[i].kor + set[i].eng + set[i].math);
        set[i].avg = (double)set[i].sumScore/3;
        
        avgKor += set[i].kor;
        avgEng += set[i].eng;
        avgMath += set[i].math;
        getScore += set[i].sumScore;
        avgAll += set[i].avg;
        
        i++;
    }
    
    avgKor = avgKor/(i);
    avgEng = avgEng/(i);
    avgMath = avgMath/(i);
    avgAll = avgAll/(i);
    
    printf("   학번     이름   국어   영어   수학   총점   평균\n");
    printf("====================================================\n");
    for (int j =0; j<i; j++){
        printf("%d %s %5d %5d %5d %7d % 7.1lf\n",
            set[j].id, set[j].name, set[j].kor, set[j].eng, set[j].math, set[j].sumScore, set[j].avg);
    }
    printf("====================================================\n");
    printf("          전체평균 % 4.1lf % 4.1lf % 4.1lf %7d % 7.1lf", avgKor, avgEng, avgMath, getScore, avgAll);
    
}