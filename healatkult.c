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

// Pilih karakter 
    // AmbaSuke
    int ATK_AS = 8;
    int DEF_AS = 7;

    //AmbaLabubu
    int ATK_AL = 7;
    int DEF_AL = 10;

    //Ambaingham 
    int ATK_AHAM = 10;
    int DEF_AHAM = 5;
    
    

    //AmbaRuwo
    int ATK_AR = 11;
    int DEF_DEF = 4;

    //Variabel Buat milih skill
    int PilihATK1;
    int PilihATK2;

    //Masukkan nama player 1 & 2
    char NamaPlayer1[64];
    char NamaPlayer2[64];

    printf("Masukkan Username player 1 : ");
    scanf("%s",&NamaPlayer1);
    printf("\nMasukkan Username player 2 : ");
    scanf("%s",&NamaPlayer2);
    printf("\n%s",NamaPlayer1);
    printf("\n%s",NamaPlayer2);
   




    //random siapa yang nyerang pertama
  srand(time(0));
  int number = (rand() % 2) + 1;
  printf("\nPlayer yang pertama kali menyerang adalah player %d\n", number);

  //mulai nyerang 
    player1_atk = player1_atk + weapon1;
    player2_atk = player2_atk + weapon2;

    player1_def = player1_def + def1;
    player2_def = player2_def + def2;

    player1_atk = player1_atk - player2_def;
    player2_atk = player2_atk - player1_def;

    // misalnya Ambaruwo vs AmbaLingham
    if(number == 1){
        player2_hp = player2_hp - player1_atk;
        printf("Sisa HP player 2 :%d\n",player2_hp);
        while(player1_hp > 0 && player2_hp >0){
            char attack2;
            start11:
            printf("\nPlayer 2 menyerang  (Y/N) : ");
            scanf(" %c",&attack2);
            if (attack2 == 'Y'){
                printf("1. Basic ATK\n2. True Damage\n3. Lifesteal\n4. Heal\n");
                scanf("%d",&PilihATK2);
                if(PilihATK2 == 1){// BASIC ATTACK
                    player1_hp = player1_hp - player2_atk;
                    printf("Sisa HP player 1 : %d\n",player1_hp);
                }
                else if (PilihATK2 == 2){// ULTIMATE
                    int random_ATK2 = rand() % 6 + 15;
                    player2_hp = player2_hp -random_ATK2;
                    player1_hp = player1_hp - 15;
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
                else if(PilihATK2 == 3){// LIFESTEAL
                    srand(time(0));
                    int randomls = (rand() % 6) + 5;
                    int ls = player1_hp * randomls/100;
                    player1_hp = player1_hp - ls;
                    player2_hp = player2_hp + ls;
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
               else {//HEAL
                    srand(time(0));
                    int random_heal1 = (rand() % 4) + 3;
                    player2_hp = player2_hp + random_heal1;
                    printf("HP player 2 sekarang : %d",player2_hp);
               }
            }
            else if (attack2 == 'N'){
                printf("Sekarang giliranmu menyerang!!!");
                goto start11;
            }
           
            start12:
            char attack1;
            printf("\nPlayer 1 menyerang  (Y/N) : ");
            scanf(" %c",&attack1);
            if (attack1 == 'Y'){
                printf("1. Basic ATK\n2. True Damage\n3. Lifesteal\n4. Heal\n");
                scanf("%d",&PilihATK1);
                if (PilihATK1 == 1){//BASIC ATTACK
                    player2_hp = player2_hp - player1_atk;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
                 else if (PilihATK1 == 2){// ULTIMATE
                    int random_ATK1 = rand() % 6 + 15;
                    player2_hp = player2_hp -random_ATK1;
                    player1_hp = player1_hp - 15;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                }
                 else if (PilihATK1 == 3){//LIFESTEl
                    srand(time(0));
                    int randomls = (rand() % 6) + 5;
                    int ls = player2_hp * randomls/100;
                    player2_hp = player2_hp - ls;
                    player1_hp = player1_hp + ls;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                }
               else {//HEAL
                    srand(time(0));
                    int random_heal2 = (rand() % 4) + 3;
                    player1_hp = player1_hp + random_heal2;
                     printf("HP player 1 sekarang : %d",player1_hp);
               }
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
            scanf(" %c",&attack3);
            if(attack3 == 'Y'){
                printf("1. Basic ATK\n2. True Damage\n3. Lifesteal\n4. Heal\n");
                scanf("%d",&PilihATK1);
                if (PilihATK1 == 1){//BASIC ATTACK
                    player2_hp = player2_hp - player1_atk;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
                else if (PilihATK1 == 2){//ULTIMATE
                    int random_ATK1 = rand() % 6 + 15;
                    player2_hp = player2_hp -random_ATK1;
                    player1_hp = player1_hp - 15;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                }
                else if (PilihATK1 == 3){//LIFESTEAL
                   srand(time(0));
                    int randomls = (rand() % 6) + 5;
                    int ls = player2_hp * randomls/100;
                    player2_hp = player2_hp - ls;
                    player1_hp = player1_hp + ls;
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                }
                else {//HEAL
                    srand(time(0));
                    int random_heal3 = (rand() % 4) + 3;
                    player1_hp = player1_hp + random_heal3;
                     printf("HP player 1 sekarang : %d",player1_hp);
               }
            }
            else if(attack3 == 'N') {
                printf("Sekarang giliranmu menyerang!!!");
                goto start21;
            }
            
            start22:
            char attack4;
            printf("\nPlayer 2 menyerang  (Y/N) : ");
            scanf(" %c",&attack4);
            if(attack4 == 'Y'){
                printf("1. Basic ATK\n2. True Damage\n3. Lifesteal\n4. Heal\n");
                scanf("%d",&PilihATK2);
                if(PilihATK2 == 1){//BASIC ATTACK
                    player1_hp = player1_hp - player2_atk;
                    printf("Sisa HP player 1 : %d\n",player1_hp);
                }
                else if (PilihATK2 == 2){//ULTIMATE
                    int random_ATK2 = rand() % 6 + 15;
                    player1_hp = player1_hp - random_ATK2;
                    player2_hp = player2_hp - 15;
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
                else if(PilihATK2 == 3){//LIFESTEAL
                    srand(time(0));
                    int randomls = (rand() % 6) + 5;
                    int ls = player1_hp * randomls/100;
                    player1_hp = player1_hp - ls;
                    player2_hp = player2_hp + ls;
                    printf("\nSisa HP player 1 : %d\n",player1_hp);
                    printf("\nSisa HP player 2 : %d\n",player2_hp);
                }
              else {//HEAL
                    srand(time(0));
                    int random_heal4 = (rand() % 4) + 3;
                    player2_hp = player2_hp + random_heal4;
                    printf("HP player 2 sekarang : %d",player2_hp);
               }
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
