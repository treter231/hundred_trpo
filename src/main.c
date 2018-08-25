#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int check(int Num, int Count){
    if(Num>=1&&Num<=10&&Num<=Count){
        return 1;
    }else{
        return 0;
    }
}

int check(int Num, int Count);

const int InitialCount=100;

int Count, Num, Player, x, a;
int Correct;

int main () {

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
                
                    if (Correct == 0) {
                        printf("Здесь что-то не так (Error)! Повторите ввод!\n");
                    }
                
                } while (Correct == 0);
            
            } else {
            
                do {
                    Num=rand()%10+1;
                    if (Num>Count)
                        Num=Count;
		    
                    printf("Ход за ботом. На столе %d спичек.\n",Count);
                    printf("Бот взял %d спичек\n",Num);}

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
       


    return 0;
    
}

