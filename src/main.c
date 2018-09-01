#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "check.h"

const int InitialCount=100;

int Count, Num, Player, x, a;
int Correct, Number_correct;

int main () {

    system("clear");
    char q;

    printf(
        "\t       █  ████  ████\n"
        "\t       █  █  █  █  █\n"
        "\t       █  █  █  █  █\n"
        "\t       █  █  █  █  █\n"
        "\t       █  ████  ████\n\n");
    printf("\t%s    (s) Start%s %sor%s %s(q) Quit%s\n",GREEN, RESET,GRAY, RESET, RED, RESET);

    scanf("%c", &q);
    if (q == 'q') {
	system("clear");
        printf("%sGoodbye!%s\n",RED, RESET);
        return 0;
    } else if (q == 's'){
     
        printf("%s\nВыберите режим игры %s\n",GRAY, RESET);
        printf("1-против бота\n");
        printf("2-против человека\n\n");
        scanf("%i", &a);

//-------------------------------------------Против бота---------------------------------------------
	if (a == 1) {


	system("clear");

	Player=1;
  	Count=InitialCount;
    
   	do {
        
    	    if (Player==1) {
            
                do {
		    printf("%s-----------------------------------------%s\n",RED, RESET);
                    printf("%sВаш ход.%s На столе %s%d%s спичек.\n",RED, RESET, RED, Count, RESET);
                    printf("Сколько спичек %sВы%s берете?\n",RED, RESET);
                    scanf("%d", &Num);
		    printf("Вы взяли %s%d%s спичек\n",RED, Num, RESET);
		    printf("%s-----------------------------------------%s\n\n",RED, RESET);
                
                    Correct = check(Num, Count);
		    Number_correct = check_isalpha(Num);
               
                    if (Correct == 0 && Number_correct == 0){
                        printf("Здесь что-то не так (Error)! Повторите ввод!\n");
		    
                    }
	    	   
                
                } while (Correct == 0);
            
            } else {
            
                do {
                    Num=rand()%10+1;
                    if (Num>Count)
                        Num=Count;
		    printf("%s-----------------------------------------%s\n",GREEN, RESET);
                    printf("%sХод за ботом.%s На столе %s%d%s спичек.\n",GREEN, RESET, GREEN, Count, RESET);
                    printf("Бот взял %s%d%s спичек\n",GREEN, Num, RESET);
		    printf("%s-----------------------------------------%s\n\n",GREEN, RESET);}

                while (Correct == 0);
            
            }
        
        
            Count-=Num;
        
            if (Player==1) {
                Player=2;
            
            } else {
                Player=1;
            }
            } while (Count>0);
    
            if (Player == 2) {
                printf("%sИгрок 1! Вы победили!%s\n",RED, RESET);
        
            } else {
                printf("%sБот победил!%s\n",GREEN, RESET);
            }
        }

// ------------------------------------------Против человека----------------------------------------- 
	if (a == 2) {

	system("clear");

	Player=1;
        Count=InitialCount;
    
    	do {
        
            if (Player==1) {
            
                do {
		    printf("%s---------------------------------%s\n",RED, RESET);
                    printf("%sИгрок 1.%s На столе %s%d%s спичек.\n",RED, RESET,RED, Count, RESET);
                    printf("Сколько спичек Вы берете (1-10)?\n");
                    scanf("%d", &Num);
		    printf("%s---------------------------------%s\n\n",RED, RESET);
                
                    Correct = check(Num, Count);
                
                    if (Correct == 0) {
                        printf("%sЗдесь что-то не так (Error)! Игрок 1, повторите ввод!%s\n",RED, RESET);
                    }
                
                } while (Correct == 0);
            
            } else {
            
                do {
		    printf("%s---------------------------------%s\n",GREEN, RESET);
                    printf("%sИгрок 2.%s На столе %s%d%s спичек.\n",GREEN, RESET,GREEN, Count, RESET);
                    printf("Сколько спичек Вы берете (1-10)?\n");
                    scanf("%d", &Num);
		    printf("%s---------------------------------%s\n\n",GREEN, RESET);
                
                    Correct = check(Num, Count);
                
                    if (Correct == 0) {
                        printf("%sЗдесь что-то не так (Error)! Игрок 2, повторите ввод!%s\n",GREEN, RESET);
                    }
                
                } while (Correct == 0);
            
            }
        
        
            Count-=Num;
        
            if (Player==1) {
                Player=2;
            
            } else {
                Player=1;
            }
            } while (Count>0);
    
            if (Player == 2) {
                printf("%sИгрок 1 победил!%s\n\n",RED, RESET);
        
            } else {
                printf("%sИгрок 2 победил!%s\n\n",GREEN, RESET);
            }
        }
    
    return 0;
    }
}

