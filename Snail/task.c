#include <stdio.h>

int main(){
    int input;
    int a[11][11]={0,};
    int num=1, x=0, y=0;
    
    int mark=1;
    
    printf("수입력 : ");
    scanf("%d", &input);
    
    for (int i = 0; i < input; i++){
        a[x][y] = num++;
        y+= mark;
    }
   // printf("%d", a[0][1]);
    y--;
    //printf("y: %d", y);
    for (int i = input-1; i>0; i--){
        for (int j = 0; j < i; j++){
            x+=mark;
            a[x][y] = num++;
        }
        mark *= -1;
        for (int j = 0; j<i; j++){
            y+=mark;
            a[x][y] = num++; 
        }
    }
    
    for (int i = 0; i<input; i++){
        for (int j = 0; j < input; j++)
        printf(" %3d", a[i][j]);
        printf("\n");
    }
    
    
    
}