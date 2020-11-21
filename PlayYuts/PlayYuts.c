#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Play {
    char name;
    int turn;
    int win;
    int score[3];
    struct Mal* malSel[3];
    struct Play* next;
} Play;

typedef struct Mal {
    int loc;
}Mal;

void yutT(Play* p){
    char team[6] = "";
    
    int sel;
    
    switch (p->name){
        case 'W':
            strcpy(team, "백군");
            break;
        case 'B':
            strcpy(team, "청군");
            break;
    }
    
    printf("%s이 윷을 던집니다. 무엇이 나왔나요?", team);
    scanf("%d", &sel);
    
    if (sel == 1){
        printf("도가 나왔습니다.\n");
        p->turn = 0;
        p->next->turn=1;
    }
    else if (sel == 2){
        printf("개가 나왔습니다.\n");
        p->turn = 0;
        p->next->turn=1;
    }
    else if (sel == 3){
        printf("걸이 나왔습니다.\n");
        p->turn = 0;
        p->next->turn=1;
    }
    else if (sel == 4)
        printf("윷이 나왔습니다.\n");
    else
        printf("모가 나왔습니다.\n");
        
    int selMal;
    
    printf("어떤 말을 움직일까요? ");
    scanf("%d", &selMal);
    
    if ((selMal>3) || (selMal<1)){
        printf("1~3 사이값 입력\n");
        return;
    }
    
    selMal--;
    
    Mal *malSelect = p-> malSel[selMal];
    malSelect->loc+=sel;
    
        if (p->score[selMal]) {
        for (int i = 0; i < 3; i++) {
            if (i == selMal) {
                continue;
            }
            else {
                if (p->score[i]) {
                    p->malSel[i]->loc += sel;
                }
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        if (i == selMal) {
            continue;
        }
        else {
            if (malSelect->loc == p->malSel[i]->loc) {
                printf("업었습니다.\n");
                p->score[selMal] = 1;
                p->score[i] = 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        if (malSelect->loc == p->next->malSel[i]->loc) {
            printf("잡았습니다.\n");
            p->turn = 1;
            p->next->turn = 0;
            p->next->malSel[i]->loc = 0;
            for (int j = 0; j < 3; j++) {
                if (p->next->score[j] && (i != j)) {
                    p->next->malSel[j]->loc = 0;
                    p->next->score[j] = 0;
                }
            }
            break;
        }
    }
}

int win(Play *p1, Play *p2){
    int p1Win=0;
    int p2Win=0;
    
    for (int i = 0; i <3; i++) {
        if (p1->malSel[i]->loc >= 20) {
            p1Win += 1;
        }
        if (p2->malSel[i]->loc >= 20) {
            p2Win += 1;
        }
    }
    if (p1Win == 3) {
        p1->win = 1;
        return 1;
    }
    else if (p2Win == 3) {
        p2Win = 1;
        return 1;
    }
    else {
        return 0;
    }
}

void searchLoc(Play *p1, Play *p2){
     for (int i = 0; i < 3; i++) {
        char coord[] = "                                                                   ";
        int p1Coord = p1->malSel[i]->loc;
        int p2Coord = p2->malSel[i]->loc;
        if (p1Coord) {
            coord[p1Coord] = p1->name;
        }
        if (p2Coord) {
            coord[p2Coord] = p2->name;
        }

        printf("좌표%d: %s\n", i + 1, coord);
    }
}



int main(){
    Play *white = malloc(sizeof(Play));
    Play *blue = malloc(sizeof(Play));
    
    white -> name ='W';
    white -> turn = 1;
    white -> next = blue;
    white -> win = 0;
    
    for (int i = 0; i < 3; i++){
        white->malSel[i] = malloc(sizeof(struct Mal));
        white->score[i] = 0;
        white->malSel[i]->loc = 0;
    }
    
    blue -> name = 'B';
    blue -> turn = 0;
    blue -> next = white;
    blue -> win = 0;
    
    for (int i =0; i< 3; i++){
        blue->score[i] = 0;
        blue->malSel[i] = malloc(sizeof(struct Mal));
        blue->malSel[i]->loc = 0;
    }
    
    while (!win(white, blue)) {
        if (white->turn) {
            yutT(white);
        }
        else {
            yutT(blue);
        }
        searchLoc(white, blue);
    }
    if (white->win) {
        printf("백군이 승리했습니다!\n");
    }
    else {
        printf("청군이 승리했습니다!\n");
    }
}