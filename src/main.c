#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "check.h"

const int InitialCount=100;

int Count, Num, Player, x, a;
int Correct, Number_correct;

int main () {

    system("clear");
  
     
        printf("\nВыберите режим игры \n");
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
		    
                    printf("Ваш ход. На столе %d спичек.\n",Count);
                    printf("Сколько спичек Вы берете?\n");
                    scanf("%d", &Num);
		    printf("Вы взяли %d спичек\n", Num);
		    
                
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
		    
                    printf("Ход за ботом. На столе %d спичек.\n", Count);
                    printf("Бот взял %d спичек\n", Num);}

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
                printf("Игрок 1! Вы победили!\n");
        
            } else {
                printf("Бот победил!\n");
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
		    
                    printf("Игрок 1. На столе %d спичек.\n", Count);
                    printf("Сколько спичек Вы берете (1-10)?\n");
                    scanf("%d", &Num);
		    
                
                    Correct = check(Num, Count);
                
                    if (Correct == 0) {
                        printf("Здесь что-то не так (Error)! Игрок 1, повторите ввод!\n");
                    }
                
                } while (Correct == 0);
            
            } else {
            
                do {
		   
                    printf("Игрок 2. На столе %d спичек.\n", Count);
                    printf("Сколько спичек Вы берете (1-10)?\n");
                    scanf("%d", &Num);
		    
                
                    Correct = check(Num, Count);
                
                    if (Correct == 0) {
                        printf("Здесь что-то не так (Error)! Игрок 2, повторите ввод!\n");
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
                printf("Игрок 1 победил!\n\n");
        
            } else {
                printf("Игрок 2 победил!\n\n");
            }
        }
    
    return 0;
    }
}
