#include <stdio.h>
#include <stdlib.h>    
#include <time.h>    

int main(){
    //stat awal
    int player1_hp = 100;
    int player2_hp = 100;
    int player1_atk = 20;
    int player2_atk = 15;
    int player1_def = 7;
    int player2_def = 9;

    //senjata
    int weapon1 = 7;
    int weapon2 = 9;

    //armor
    int def1 = 9;
    int def2 = 7;

    

    //random siapa yang nyerang pertama
  srand(time(0));
  int number = (rand() % 2) + 1;
  printf("\nPlayer yang pertama kali menyerang adalah player %d\n", number);

  //mulai nyerang 
    player1_atk = player1_atk + weapon1;
    player2_atk = player2_atk + weapon2;

    player1_def = player1_def +def1;
    player2_def = player2_def +def2;

    player1_atk = player1_atk - player2_def;
    player2_atk = player2_atk - player1_def;


    if(number == 1){
        player2_hp = player2_hp - player1_atk;
        printf("Sisa HP player 2 :%d\n",player2_hp);
        while(player1_hp > 0 && player2_hp >0){
            char attack2;
            start11:
            printf("\nPlayer 2 menyerang  (Y/N) : ");
            scanf("%c",&attack2);
            if (attack2 == 'Y'){
                player1_hp = player1_hp - player2_atk;
                printf("Sisa HP player 1 : %d\n",player1_hp);
            }
            else if (attack2 == 'N'){
                printf("Sekarang giliranmu menyerang!!!");
                goto start11;
            }
           
            start12:
            char attack1;
            printf("\nPlayer 1 menyerang  (Y/N) : ");
            scanf("%c",&attack1);
            if (attack1 == 'Y'){
                player2_hp = player2_hp - player1_atk;
                printf("\nSisa HP player 2 : %d\n",player2_hp);
            }
            else if (attack1 == 'N'){
                printf("Sekarang giliranmu menyerang!!!");
                goto start12;
            }
        }
    }
    else {
        player1_hp = player1_hp - player2_atk;
        printf("Sisa HP player 1 :%d\n",player1_hp);
        while(player1_hp > 0 && player2_hp >0){
            start21:
            char attack3;
            printf("\nPlayer 1 menyerang  (Y/N) : ");
            scanf("%c",&attack3);
            if(attack3 == 'Y'){
                 player2_hp = player2_hp - player1_atk;
                printf("\nSisa HP player 2 : %d\n",player2_hp);
            }
            else if(attack3 == 'N') {
                printf("Sekarang giliranmu menyerang!!!");
                goto start21;
            }
            
            start22:
            char attack4;
            printf("\nPlayer 2 menyerang  (Y/N) : ");
            scanf("%c",&attack4);
            if(attack4 == 'Y'){
                 player2_hp = player2_hp - player1_atk;
                printf("\nSisa HP player 2 : %d\n",player2_hp);
            }
            else if (attack4 == 'N'){
                printf("Sekarang giliranmu menyerang!!!");
                goto start22;
            }
           
        }
    }
    
    if (player1_hp >= 0){
        printf("Player 2 Menang");
    }
    else {
        printf("Player 1 Menang");
    }
  
    return 0;
}