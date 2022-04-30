// Copyrights for LoRixD - You have NO copyright to upload or share this file WHITOUT permissions from LoRixD
//                       - If you still want to upload it look for permission of LoRixD on YouTube or Gmail


#include <stdio.h>          /*-lwinmm -- to run the compiler */
#include <stdlib.h>         /*  //                 //             ///////  //                 ///////   */
#include <windows.h>        /*  //     //  //      //             //   //                     //   //   */
#include <time.h>           /*  //      ///        //       //    ///////  //     //    //    //    //  */
                            /*  /////    //        //     //  //  // //    //       ////      //    //  */
                            /*  // //    //        //     //  //  //  //   //       ////      //   //   */
#define MAX_X 45 /*60           /////   //         //////   //    //   //  //     //    //    //////    */
#define MAX_Y 15 //20

#define WINDOW_X 60 //60
#define WINDOW_Y 20 //20

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#include "unchangeable vars.h"
#include "maps.h"

char songicon = 14;

char snake_form = 177; //177
char snake_head = 178; //178

char snake_form2 = 176;
char snake_head2 = 177;

char foodicon     = 254;
char obstacleicon = 'X';

double speed;

void wait();
void gotoxy(unsigned short, unsigned short);
void add_body(int, int);
void move(int, int);

void text_color(int);
void draw_snake();
void food(int, int, int);
void obstacles(int, int, int);

void move2();
void add_body2(int, int);
void draw_snake2();
void self_eat2();

void scan();
void check();
void self_eat();
void deallocate();
void cheatscreen();

void anticheat();
void arcade();
void startgame();
void info();
void welcome();
void init();
void display();
void input();
void direction();

void endingame();
void end();

#include "savegame IO.h"
#include "options IO.h"
#include "commands.h"

void check()
{
    int points_recieved;

     body *tmp;
     tmp = body_head;

     /*                              Food check                         */

     if ( foods[body_head->y][body_head->x] == foodicon || (mode == 2 && map == 3))
     {

         if(soundstatus == 1 && mode != 2 && map != 3)
         {
          PlaySound("sounds\\Eat.wav", NULL, SND_ASYNC);
          eat_time = clock();
         }

        if (map == 3)
        {
         speed -= 0.0003;
         points_recieved = 5;
        }
        else
        {
          foods[body_head->y][body_head->x] = ' ';

          food(0, 0, 1);

          if(body_head->y == 1 || body_head->y == MAX_Y - 2 ||
            (body_head->x <= 3 && body_head->x > 0) || (body_head->x >= MAX_X - 4 && body_head->x < MAX_X - 2))
            {
             points_recieved = 25;
             speed -= 0.009;
             coins++;
            }
     else if( (body_head->y <= 3 && body_head->y > 1) || (body_head->y >= MAX_Y - 5 && body_head->y < MAX_Y - 2) ||
              (body_head->x <= 5 && body_head->x > 3) || (body_head->x >= MAX_X - 7 && body_head->x < MAX_X - 2) ||
              (base[body_head->y + 1][body_head->x] == obstacleicon) || (base[body_head->y - 1][body_head->x] == obstacleicon) ||
              (base[body_head->y][body_head->x + 1] == obstacleicon) || (base[body_head->y][body_head->x - 1] == obstacleicon))
            {
             points_recieved = 15;
             speed -= 0.007;
             coins++;
            }
          else
            {
             points_recieved = 10;
             speed -= 0.004;
             coins++;
            }
        }

         if (mode == 3)
         {
          // content coming      scoremo3p1,hscoremo3p1,
          //                     scoremo3p1,hscoremo3p1;
         }
         else
         {
          score_verifier += ((points_recieved /5) * 7);
          score += points_recieved;
         }


          add_body(body_tail->y, body_tail->x);
          draw_snake();

        if ( coins % 3 == 0)
        {
          coins = 0;

          if ((map == 1 && mode == 2) || (mode == 1))
         {
          obstacles (0,0,1);

          if(soundstatus == 1)
         {
          PlaySound("sounds\\Obstacle_after_food.wav", NULL, SND_ASYNC);
         }

         }
        }
     }
     /* ---------------------------------------------------------------- */


     /*                                              Base limit check    */
    if(mode == 2)
    {
     if ( ( body_head->y == 0 ) || ( body_head->x == 0 ) || ( body_head->y == (MAX_Y - 1) ) || ( body_head->x == (MAX_X - 1) ) ) {
          end();
     }
     /* ----------------------------------------------------------------------------------------------------------------------- */
    }
    else if (mode == 1 || mode == 3)
    {
     if ( body_head->y == 0 )
     {
      body_head->y = (MAX_Y - 2);
      base[0][body_head -> x] = 205;
     }
     if ( body_head->x == 0 )
     {
      body_head->x = (MAX_X - 2);
      base[body_head -> y][0] = 186;
     }
     if ( body_head->y == (MAX_Y - 1) )
     {
      body_head->y = 1;
      base[MAX_Y - 1][body_head -> x] = 205;
     }
     if ( body_head->x == (MAX_X - 1) )
     {
      body_head->x = 1;
      base[body_head -> y][MAX_X - 1] = 186;
     }
    }

     /*                            Obstacle check                         */


  /*if (obstacl[body_head->y][body_head->x] == obstacleicon)
    {
     end();
    }*/

         while (tmp != NULL){
           if (obstacl[tmp->y][tmp->x] == obstacleicon){
                tmp = NULL;
                end();
           }
           else {
                tmp = tmp->next;
           }
     }

     /* ----------------------------------------------------------------- */
}

void load()
{
       system("cls");

       stprepeat = 1;

         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       gotoxy(MAX_X / 2 + MAX_X / 10,MAX_Y / 2 );

       text_color(9);
       printf("LOADING");

       gotoxy(MAX_X / 2 + MAX_X / 10 - 7,MAX_Y / 2 + 1);

       for( z = 1;z <= 20; z++)
       {
        text_color(12);
        wait(0.1);

        printf("%c",177);
       }

       text_color(16);

     system("cls");

     pastclock = clock();
     stprepeat = 1;
}

void arcade()
{
  stprepeat = 0;

   system("cls");

      command = 1;

         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 4);
      printf("--Map 1--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 2);
      printf("Map 2");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Map 3");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 2);
      printf("Map 4");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 4);
      printf("Map 5");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       map = 1;
       stprepeat = 1;
      }
while(stprepeat == 0)
{
      if ((press  == DOWN && command == 5) || (press  == UP && command == 2))
     {
      system("cls");

      command = 1;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 4);
      printf("--Map 1--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 2);
      printf("Map 2");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Map 3");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 2);
      printf("Map 4");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 4);
      printf("Map 5");

      press = getch();
     }
      else if ((press  == DOWN && command == 1) || (press  == UP && command == 3))
     {
            system("cls");

      command = 2;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 4);
      printf("Map 1");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 2);
      printf("--Map 2--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Map 3");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 2);
      printf("Map 4");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 4);
      printf("Map 5");

      press = getch();
     }
      else if ((press  == DOWN && command == 2) || (press  == UP && command == 4))
     {
            system("cls");

      command = 3;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 4);
      printf("Map 1");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 2);
      printf("Map 2");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2);
      printf("--Map 3--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 2);
      printf("Map 4");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 4);
      printf("Map 5");

      press = getch();
     }
      else if ((press  == DOWN && command == 3) || (press  == UP && command == 5))
     {
            system("cls");

            command = 4;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 4);
      printf("Map 1");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 2);
      printf("Map 2");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Map 3");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 + 2);
      printf("--Map 4--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 4);
      printf("Map 5");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       map = 4;
       stprepeat = 1;
      }
     }
      else if ((press  == DOWN && command == 4) || (press  == UP && command == 1))
     {
            system("cls");

      command = 5;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 4);
      printf("Map 1");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 2);
      printf("Map 2");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Map 3");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 + 2);
      printf("Map 4");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 + 4);
      printf("--Map 5--");

      press = getch();

      if(press == 13)
      {
        if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       map = 5;
       stprepeat = 1;
      }
     }

          if(press == 13 && command == 1)
          {
             if(soundstatus == 1)
             {
              PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
             }

           map = 1;
           stprepeat = 1;
          }
          else if(press == 13 && command == 2)
          {
             if(soundstatus == 1)
             {
              PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
             }

           map = 2;
           stprepeat = 1;
          }
          else if(press == 13 && command == 3)
          {
             if(soundstatus == 1)
             {
              PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
             }

           map = 3;
           stprepeat = 1;
          }
          else if(press == 13 && command == 4)
          {
             if(soundstatus == 1)
             {
              PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
             }

           map = 4;
           stprepeat = 1;
          }
          else if(press == 13 && command == 5)
          {
             if(soundstatus == 1)
             {
              PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
             }

           map = 5;
           stprepeat = 1;
          }
          else if (press == 27)
          {
            if(soundstatus == 1)
            {
             PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
            }
            endingame();
            stprepeat = 0;
            welcome();
          }
          else if(press == LEFT)
          {
           startgame();
          }

    if (kbhit())
    {
     press = getch();

     if (press == DOWN || press == UP || press == 13)
     {}
     else
     {
      gotoxy(MAX_X /2 - 10 , MAX_Y /2 + 7);
      printf("Please don't press non-avabile keys !");
     }
    }
  }
}

void startgame()
{
   stprepeat = 0;
   command = 1;

   system("cls");

         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 3);
      printf("--Clasic--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Arcade");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 + 3);
      printf("Multiplayer");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       mode = 1;
       stprepeat = 1;
      }

while(stprepeat == 0)
{

if ((press  == DOWN && command == 3) || (press  == UP && command == 2))
     {
      system("cls");

      command = 1;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 3);
      printf("--Clasic--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Arcade");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 + 3);
      printf("Multiplayer");

      press = getch();
     }
else if ((press  == DOWN && command == 1) || (press  == UP && command == 3))
    {
      system("cls");

      command = 2;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 3);
      printf("Clasic");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2);
      printf("--Arcade--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 + 3);
      printf("Multiplayer");

      press = getch();

    }
else if ((press  == DOWN && command == 2) || (press  == UP && command == 1))
    {
      system("cls");

      command = 3;
         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2 - 3);
      printf("Clasic");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 3 ,MAX_Y / 2);
      printf("Arcade");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 7 ,MAX_Y / 2 + 3);
      printf("--Multiplayer--");

      press = getch();

    }



      if(press == 13 && command == 1)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       mode = 1;
       stprepeat = 1;
      }
      else if(press == 13 && command == 2)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       mode = 2;
       arcade();
      }
      else if(press == 13 && command == 3)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       mode = 3;
       stprepeat = 1;
      }
      else if (press == 27)
      {
       if(soundstatus == 1)
       {
        PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
       }
       endingame();
       stprepeat = 0;
       welcome();
      }
      else if(press == LEFT)
      {
       welcome();
      }

    if (kbhit())
    {
     press = getch();

     if (press == DOWN || press == UP || press == 13)
     {}
     else
     {
      gotoxy(MAX_X /2 - 10 , MAX_Y /2 + 7);
      printf("Please don't press non-avabile keys !");
     }
    }
}

press = 0 ;
 }
void info()
{
    if(soundstatus == 1)
    {
     PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
    }

     system ("cls");

     gotoxy (MAX_X /2 + 5,MAX_Y - (MAX_Y - 1) );
     printf ("Snake");
     gotoxy (MAX_X /2 - 2,MAX_Y - (MAX_Y - 3) );
     printf (".:Game Information:.");
     gotoxy (MAX_X /2 + 5,MAX_Y - (MAX_Y - 6) );
     printf ("Food: %c", 254);
     gotoxy (MAX_X /2 + 2,MAX_Y - (MAX_Y - 8) );
     printf (" Obstacle: x");
     gotoxy (MAX_X /2,MAX_Y - (MAX_Y - 10) );
     printf ("Move: Arrow keys");
     gotoxy (MAX_X /2 - 5,MAX_Y - (MAX_Y - 13) );
     printf ("Press left arrow to go back.");
     gotoxy (MAX_X /2 - 5,MAX_Y - (MAX_Y - 16) );
     printf ("(c) Copyrights 2015 -- LORIXD");
     gotoxy (MAX_X /2 - 5,MAX_Y - (MAX_Y - 18) );
     printf ("Personal Computer \" Szoke PC \" ");

 while(stprepeat == 0)
{
     press = getch();

     if(press == LEFT)
     {
      stprepeat = 1;
      welcome();
     }
     else
     {
      gotoxy (MAX_X /2 - 8,MAX_Y - (MAX_Y - 21) );
      printf("Please don't press non-avabile keys !");
     }
}

}
void welcome()
{
     system("cls");

     command = 1;

     system("color f0"); // system("color g0") - information

      gotoxy(MAX_X / 2 + MAX_X / 10 - 7 ,MAX_Y / 2 - 3);
      printf("--Start Game--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 6 ,MAX_Y / 2);
      printf("Informations");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 4 ,MAX_Y / 2 + 3);
      printf("Exit Game");

      press = getch();   //https://msdn.microsoft.com/en-us/library/aa299374%28VS.60%29.aspx

      if(press == 13)
      {
       startgame();
      }

while(stprepeat == 0)
{

if ((press  == DOWN && command == 3) || (press  == UP && command == 2))
     {
      system("cls");

      command = 1;

         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 7 ,MAX_Y / 2 - 3);
      printf("--Start Game--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 6 ,MAX_Y / 2);
      printf("Informations");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 4 ,MAX_Y / 2 + 3);
      printf("Exit Game");

      press = getch();
     }
else if ((press  == DOWN && command == 1) || (press  == UP && command == 3))
     {
      system("cls");

      command = 2;

         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 3);
      printf("Start Game");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 8 ,MAX_Y / 2);
      printf("--Informations--");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 4 ,MAX_Y / 2 + 3);
      printf("Exit Game");

      press = getch();
    }
else if ((press  == DOWN && command == 2) || (press  == UP && command == 1))
     {
      system("cls");

      command = 3;

         if(soundstatus == 1)
         {
          PlaySound("sounds\\But_Change.wav", NULL, SND_ASYNC);
         }

      gotoxy(MAX_X / 2 + MAX_X / 10 - 5 ,MAX_Y / 2 - 3);
      printf("Start Game");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 6 ,MAX_Y / 2);
      printf("Informations");
      gotoxy(MAX_X / 2 + MAX_X / 10 - 6 ,MAX_Y / 2 + 3);
      printf("--Exit Game--");

      press = getch();
    }

    if(press == 13 && command == 1)
    {
     startgame();
    }
    else if(press == 13 && command == 2)
    {
     info();

     press = getch();
    }
    else if(press == 13 && command == 3)
    {
      if(soundstatus == 1)
      {
       PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
      }

      system("cls");

      exit(0);
     }
    else if (press == 27)
    {
      if(soundstatus == 1)
      {
       PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
      }
      endingame();
      stprepeat = 0;
      welcome();
    }



    if (kbhit())
    {
     press = getch();

     if (press == DOWN || press == UP || press == 13)
     {}
     else
     {
      gotoxy(MAX_X /2 - 10 , MAX_Y /2 + 7);
      printf("Please don't press non-avabile keys !");
     }

     }
    }

press = 0 ;
}
void permissions()
{
 int press;

 if(((map == 2 && mode == 2) && hscoremo2ma1 < objmo2ma1) || ((map == 3 && mode == 2) && hscoremo2ma2 < objmo2ma2)
  ||((map == 4 && mode == 2) && hscoremo2ma3 < objmo2ma3) || ((map == 5 && mode == 2) && hscoremo2ma4 < objmo2ma4))
 {
  system("cls");

  gotoxy(MAX_X /2 - 18 ,MAX_Y /2 - 2);
  printf("To start, you need to complete map %d objectives !", map - 1);
  gotoxy(MAX_X /2 + 3 ,MAX_Y /2);
  printf("--OK--");

      while(press != 13)
      {
       press = getch();
      }

  deallocate();
  scanoptionsfile();   //those are for preventing bugs
  scansavegame();

  welcome();
 }
}


void init()
{
     int y, x;
     int addx,addy;

     if (mode == 1)
     {
      speed = 0.15;//0.15
     }
     else if(mode == 2 || mode == 3)
     {
     speed = 0.20;
     }


     /*           Frame            */
     for (y = 1; y < MAX_Y - 1; y++) {
         base[y][0] = 186;
         base[y][MAX_X - 1] = 186;
     }

     for (x = 1; x < MAX_X - 1; x++) {
         base[0][x] = 205;
         base[MAX_Y - 1][x] = 205;
     }

     base[0][0] = 201;
     base[0][MAX_X - 1] = 187;
     base[MAX_Y - 1][0] = 200;
     base[MAX_Y - 1][MAX_X - 1] = 188;
     /*           Direction         */

     do
     {
     key = (rand() % (80-72)) +72;
     }
     while ( (key != UP) && (key != LEFT) && (key != RIGHT) && (key != DOWN) );

     prev_key = key;

     /* --------------------------- */


     /*           Snake             */

     if ((mode == 2 && map == 2) || (mode == 2 && map == 4))
     {
      addx = MAX_X / 2 + 15;
      addy = MAX_Y / 2 + 4;
     }
     else if (mode == 2 && map == 5)
     {
      addx = MAX_X / 2 - 15;
      addy = MAX_Y / 2 - 4;
     }
     else
     {
      addx = MAX_X / 2;
      addy = MAX_Y / 2;
     }

     if (key == UP)
     {
      add_body(addy, addx);
      add_body(addy + 1, addx);
      add_body(addy + 2, addx);
     }
     else if (key == DOWN)
     {
      add_body(addy, addx);
      add_body(addy - 1, addx);
      add_body(addy - 2, addx);
     }
      else if (key == LEFT)
     {
      add_body(addy, addx);
      add_body(addy, addx + 1);
      add_body(addy, addx + 2);
     }
     else if (key == RIGHT)
     {
      add_body(addy, addx);
      add_body(addy, addx - 1);
      add_body(addy, addx - 2);
     }
     else
     {
       system("COLOR FC");
       printf("Error allocating direction !");

       while(!kbhit())
       {
       }
        exit(1);
     }

     draw_snake();
     /* --------------------------- */

     /*           Obstacles         */
      if (map == 1 || mode == 1)
     {
     obstacles(0,0,1);
     }
     else if (mode == 2 && map != 1)
     {
     for (y = 0; y < MAX_Y ; y++)
     {
      for (x = 0; x < MAX_X ; x++)
      {
       if (map == 2 && mode == 2)
       {
         ms = mapskech22[y][x];
       }
       else if (map == 3 && mode == 2)
       {
         ms = mapskech3[y][x];
       }
       else if (map == 4 && mode == 2)
       {
         ms = mapskech43[y][x];
       }
       else if (map == 5 && mode == 2)
       {
        draw_spider(MAX_X / 2 + 15,MAX_Y / 2 + 4);
       }

           if (ms == 1)
           {
            obstacles(x,y,2);
           }
           else if (ms == 2)
           {
            if (foods[y][x] == foodicon)
            {
             base[y][x] = foodicon;
            }
            else if (base[y][x] == snake_head)
            {
             base[y][x] = snake_head;
            }
            else if (base[y][x] == snake_form)
            {
             base[y][x] = snake_form;
            }
            else
            {
            base[y][x] = '!';
            }

            obstacl[y][x] = ' ';
           }
           else if (ms == 3)
           {
            obstacl[y][x] = obstacleicon;
           }

       }
      }
     }

      if ((map == 1 && mode == 2) || (mode == 1))
     {
      food(0,0,1);
      food(0,0,1);
     }
     else if ((map == 2 && mode == 2) || (map == 4 && mode == 2) || (map == 5 && mode == 2))
     {
      food(0,0,1);
      food(0,0,1);
      food(0,0,1);
     }

     /* --------------------------- */
}
void display()
{
     gotoxy(0 ,0);
     int y, x;

     printf ("\n\tScore:");

     text_color(9);
     printf(" %d",score);
     text_color(16);

     if(0 <= score && score < 10)
     {
      for(z= 0 ; z <= (MAX_X - 31) ; z++)
      {
      printf (" ");
      }
     }
     else if (9 < score && score < 100)
     {
      for(z= 0 ; z <= (MAX_X - 32) ; z++)
      {
      printf (" ");
      }
     }
     else if (99 < score && score < 1000)
     {
      for(z= 0 ; z <= (MAX_X - 33) ; z++)
      {
      printf (" ");
      }
     }
     else if (999 < score && score < 10000)
     {
      for(z= 0 ; z <= (MAX_X - 34) ; z++)
      {
      printf (" ");
      }
     }

     if (z >= 4)
     {
      printf("Press ");
      text_color(12);
      printf("\"Enter\" ");
      text_color(16);
      printf("to pause");
     }

      printf ("\n");

    for (y = 0; y < MAX_Y ; y++) {

     for (x = 0; x < MAX_X ; x++)
     {
       if (map == 2 && mode == 2)
       {
        if (anim == (2) * 3 )
        {
         ms = mapskech21[y][x];
        }
        else if (anim == (2) * 2 )
        {
         ms = mapskech22[y][x];
        }
        else if (anim >= (2) * 3 ){anim = 0;}
       }

       if (map == 4 && mode == 2)
       {
         if (anim == (snakelong1+ 5) * 3 )
        {
         ms = mapskech41[y][x];
        }
        else if (anim == (snakelong1 + 5) * 2 )
        {
         ms = mapskech42[y][x];
        }
        else if (anim == (snakelong1 + 5))
        {
         ms = mapskech43[y][x];
        }
        else if (anim >= (snakelong1 + 5) * 3 ){anim = 0;}
       }

           if (ms == 1)
           {
            obstacles(x,y,2);
           }
           else if (ms == 2)
           {
            if (base[y][x] == ' ' || base[y][x] == 'X' )
            {
            base[y][x] = '!';

            obstacl[y][x] = ' ';
            }

           }
           else if (ms == 3)
           {
            obstacl[y][x] = obstacleicon;
           }
           else if(ms == 4)
           {
            if (base[y][x] == ' ' || base[y][x] == 'X' )
            {
            base[y][x] = ' ';

            obstacl[y][x] = ' ';
            }
           }

        if (base[y][x] == snake_head || base[y][x] == snake_form)
       {
        text_color(6);
       }
       else if (base[y][x] == obstacleicon)
       {
        text_color(12);
       }
       else if (base[y][x] == foodicon)
       {
        text_color(14);
       }
       else
       {
        text_color(16);
       }


       if((prevbase[y][x] != base[y][x] && first != 1)||(base[y][x] == snake_form) || first == 1)
       {
        gotoxy(x + 8,y + 2);
        printf ("%c", base[y][x]);
       }

    }

    //   if (first == 1)
    //   {
    //    fwrite(base[y], MAX_X, 1, stdout);        //http://stackoverflow.com/questions/28243184/fastest-way-to-output-a-2d-array-in-c
    //   }

        printf("\n");
    }
      if (soundstatus == 1)
    {
     text_color(9);
     printf ("\t %c - sound on ",songicon);
     text_color(16);
    }
    else if (soundstatus == 2)
    {
     text_color(12);
     printf ("\t %c - sound off",songicon);
     text_color(16);
    }

     gotoxy(MAX_X + 10,MAX_Y / 2 + 2);

     if (mode == 1)
     {
     text_color(12); printf("   Earn a Hi-Score !"); text_color(16);
     }
     if (map == 1 && mode == 2)
     {
      text_color(12); printf("Earn the Score of %d !",objmo2ma1); text_color(16);
     }
     if (map == 2 && mode == 2)
     {
      text_color(12); printf("Earn the Score of %d !",objmo2ma2); text_color(16);
     }
     if (map == 3 && mode == 2)
     {
      text_color(12); printf("Earn the Score of %d !",objmo2ma3); text_color(16);
     }
     if (map == 4 && mode == 2)
     {
      text_color(12); printf("Earn the Score of %d !",objmo2ma4); text_color(16);
     }
     if (map == 5 && mode == 2)
     {
      text_color(12); printf("   Earn a Hi-Score !"); text_color(16);
     }

      for (y = 0; y < MAX_Y ;y++) {
        for (x = 0; x < MAX_X ; x++){
         prevbase[y][x] = base[y][x];}}

     wait(speed);

     first = 2;
     anim ++;
}
void input()
{
        if ( kbhit() ) // If a key is pressed
        {
            prev_key = key;
            key = getch();

            keypressed = 1;
        }
         if (key == 13)
         {

              system ("color 70");

              gotoxy(35,10);
              printf("PAUSED");

              key = prev_key;

              while(key != 13)
              {
                key = getch();
              }

              keybd_event(VK_RETURN,0,0,0);
              wait(0.01);
              keybd_event(VK_RETURN,0,0x02,0);

              system ("cls");
              system ("color f0");

              key = prev_key;
              first = 1;

         }
         else if (key == 110 || key == 78 ) // n || N
         {
          if (soundstatus == 1)
          {
           soundstatus = 2;
           key = prev_key;
          }
          else
          {
           soundstatus = 1;
           key = prev_key;
          }
          keybd_event(VK_RETURN,0,0,0);
          wait(0.01);
          keybd_event(VK_RETURN,0,0x02,0);
         }
         else if(key==27)
         {
           endingame();

           keybd_event(VK_RETURN,0,0,0);
           wait(0.01);
           keybd_event(VK_RETURN,0,0x02,0);
         }
}
void direction()
{
    if (keypressed == 1)
    {
      key = getch();
      keypressed = 0;
    }

     int y = body_head->y, x = body_head->x;

     if (key == UP && prev_key != DOWN) { //UP
          y--;
          move(x, y);
     }
     else if (key == DOWN && prev_key != UP) { //DOWN
          y++;
          move(x, y);
     }
     else if (key == RIGHT && prev_key != LEFT) { // RIGHT
          x++;
          move(x, y);
     }
     else if (key == LEFT && prev_key != RIGHT) { // LEFT
          x--;
          move(x, y);
     }
     else
     {
          key = prev_key;
          direction();
     }

}

void endingame()
{
   stprepeat = 0;
   command = 2;

   system("cls");


      gotoxy(MAX_X /2 - 13 ,MAX_Y /2 - 2);
      printf("Are you sure you want to exit ?");

      gotoxy(MAX_X /2 - 9 ,MAX_Y /2);
      printf("  Yes             --No--");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }
       first = 1;
       stprepeat = 1;
      }

while(stprepeat == 0)
{

if ((press == LEFT || press == RIGHT) && command == 2)
     {

   system("cls");

   command = 1;


      gotoxy(MAX_X /2 - 13 ,MAX_Y /2 - 2);
      printf("Are you sure you want to exit ?");

      gotoxy(MAX_X /2 - 9 ,MAX_Y /2);
      printf("--Yes--             No  ");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }

       gotoxy(10,MAX_Y);

       exit(0);
      }
     }
if ((press == LEFT || press == RIGHT) && command == 1)
    {
    system("cls");

    command = 2;


      gotoxy(MAX_X /2 - 13 ,MAX_Y /2 - 2);
      printf("Are you sure you want to exit ?");

      gotoxy(MAX_X /2 - 9 ,MAX_Y /2);
      printf("  Yes             --No--");

      press = getch();

      if(press == 13)
      {
         if(soundstatus == 1)
         {
          PlaySound("sounds\\Enter.wav", NULL, SND_ASYNC);
         }
       first = 1;
       stprepeat = 1;
      }

    }


if(press == 27)
{
  stprepeat = 1;
  first = 1;
}

    if (kbhit())
    {
     press = getch();

     if (press == RIGHT || press == LEFT || press == 27)
     {}
     else
     {
      gotoxy(MAX_X /2 - 15 , MAX_Y /2 + 4);
      printf("Please don't press non-avabile keys !");
     }
    }
}

press = 0 ;
}

void anticheat()
{
 if (score_verifier != ((score /5) * 7))
 {
  system ("cls");
  system("color 0C");

  gotoxy(MAX_X /2 - 20 ,MAX_Y /2 - 2);
  printf("Please delete you'r cheating program,and");

  gotoxy(MAX_X /2 - 15 ,MAX_Y /2 - 1);
  printf("get a better one ! -_-");

  for (z = 1;z <= 10; z++)
  {
    gotoxy(MAX_X /2 - 4 ,MAX_Y /2 + 2);
    printf(" %d ", z);

    wait(1);
  }

  exit(0);
 }
}

void spider_catch()
{
 int direction = random_between(1,2);

 if ((clock() - spider_move) >= (1.8 * CLOCKS_PER_SEC) && mode == 2 && map == 5)
     {
       spider_move = clock();

       erase_spider(spider_x,spider_y);

      if(( body_head->x > spider_x - 2 || body_head->x > spider_x + 2
        || body_head->x > spider_x - 1 || body_head->x > spider_x + 1)
        && (spider_x + 2 != MAX_X - 2) && (direction == 1 || body_head->y == spider_y))
        {
         draw_spider(spider_x + 1,spider_y);
        }
 else if(( body_head->x < spider_x - 2 || body_head->x < spider_x + 2
        || body_head->x < spider_x - 1 || body_head->x < spider_x + 1)
        && (spider_x - 2 != 2) && (direction == 1 || body_head->y == spider_y))
        {
         draw_spider(spider_x - 1,spider_y);
        }
 else if(( body_head->y > spider_y - 2 || body_head->y > spider_y + 2
        || body_head->y > spider_y - 1 || body_head->y > spider_y + 1)
        && (spider_y + 2 != MAX_Y - 2) && (direction == 2 || body_head->x == spider_x))
        {
         draw_spider(spider_x,spider_y + 1);
        }
 else if(( body_head->y < spider_y - 2 || body_head->y < spider_y + 2
        || body_head->y < spider_y - 1 || body_head->y < spider_y + 1)
        && (spider_y + 2 != 2) && (direction == 2 || body_head->x == spider_x))
        {
         draw_spider(spider_x,spider_y - 1);
        }
     }
}

int main(void)
{
    system ("title Snake - by LoRi xD");

    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);

    deallocate();

    scanoptionsfile();
    scansavegame();

    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(wHnd , &ConCurInf);

    welcome();
    permissions();
    load();
    srand (time(NULL));
    init();

    while (1)
    {
       movement++;

       display();
       input();
       direction();

       spider_catch();

//       snakesound();

       anticheat();
    }

  return 0;
}

void end()
{
     int key;

     pastclock = clock();
     system ("cls");

     if(((mode == 1            ) && score > hscore)
      ||((mode == 2 && map == 1) && score > objmo2ma1)
      ||((mode == 2 && map == 2) && score > objmo2ma2)
      ||((mode == 2 && map == 3) && score > objmo2ma3)
      ||((mode == 2 && map == 4) && score > objmo2ma4)
      ||((mode == 2 && map == 5) && score > hscore))
     {
      text_color(9);
      gotoxy (26, 3);
      printf("Mission Acomplished!");
      text_color(16);

      if(soundstatus == 1)
      {
        PlaySound("sounds\\Applause.wav", NULL, SND_ASYNC);
      }

     }
     else
     {
     text_color(12);
     gotoxy (31, 3);
     printf ("Game Over!");
     text_color(16);

     if(soundstatus == 1)
      {
        PlaySound("sounds\\GameOver.wav", NULL, SND_ASYNC);
      }

     }

     if (mode == 1)
     {
         hscore = hscoremo1;
     }
     else if (mode == 2)
     {
       if(map == 1)
       {
        hscore = hscoremo2ma1;
       }
       if(map == 2)
       {
        hscore = hscoremo2ma2;
       }
       if(map == 3)
       {
        hscore = hscoremo2ma3;
       }
       if(map == 4)
       {
        hscore = hscoremo2ma4;
       }
       if(map == 5)
       {
        hscore = hscoremo2ma5;
       }
     }

         gotoxy (25, 6);
         printf ("Score: %d  Hi-Score: %d", score, hscore);

     if(score > hscore)
     {
       newhiscore = 1;

       if (mode == 1)
       {
        hscoremo1 = score;

         strncpy(day, day1, 3);
         strncpy(month, month1, 3);

         daynr = daynr1;
         h = h1;
         m = m1;
         s = s1;
         y = y11;

        strncpy(player, player1, 18);
       }
       else if (mode == 2)
       {
        if (map == 1)
        {
         hscoremo2ma1 = score;

         strncpy(day, day2, 3);
         strncpy(month, month2, 3);

         daynr = daynr2;
         h = h2;
         m = m2;
         s = s2;
         y = y2;

         strncpy(player, player2, 18);
        }
        if (map == 2)
        {
         hscoremo2ma2 = score;

         strncpy(day, day3, 3);
         strncpy(month, month3, 3);

         daynr = daynr3;
         h = h3;
         m = m3;
         s = s3;
         y = y3;

         strncpy(player, player3, 18);
        }
        if (map == 3)
        {
         hscoremo2ma3 = score;

         strncpy(day, day4, 3);
         strncpy(month, month4, 3);

         daynr = daynr4;
         h = h4;
         m = m4;
         s = s4;
         y = y4;

         strncpy(player, player4, 18);
        }
        if (map == 4)
        {
         hscoremo2ma4 = score;

         strncpy(day, day5, 3);
         strncpy(month, month5, 3);

         daynr = daynr5;
         h = h5;
         m = m5;
         s = s5;
         y = y5;

         strncpy(player, player5, 18);
        }
        if (map == 5)
        {
         hscoremo2ma5 = score;

         strncpy(day, day6, 3);
         strncpy(month, month6, 3);

         daynr = daynr6;
         h = h6;
         m = m6;
         s = s6;
         y = y6;
         strncpy(player, player6, 18);
        }
       }
       else if (mode == 3)
       {

       }


         hscore = score;

         gotoxy (15, 9);
         text_color(9);
         printf(" Congratulations! You broke the last hi-score!");
         text_color(16);

         gotoxy (10, 13);
         printf("Made by");
         text_color(12);
         printf(" %s ", player);
         text_color(16);
         printf("on the date of ");
         text_color(12);
         printf("%s %s %d %d:%d:%d %d",day,month,daynr,h,m,s,y);
         text_color(16);

       ConCurInf.bVisible = TRUE;
       SetConsoleCursorInfo(wHnd, &ConCurInf);

       gotoxy (25, 19);
       printf("Please enter you'r name : ");

       gotoxy (50, 19);

       text_color(12);
       scanf("%s", player);
       text_color(16);

       if (mode == 1)
       {
        strncpy(player1, player, 18);
       }
       else if (mode == 2)
       {
        if(map == 1)
        {
         strncpy(player2, player, 18);
        }
        if(map == 2)
        {
         strncpy(player3, player, 18);
        }
        if(map == 3)
        {
         strncpy(player4, player, 18);
        }
        if(map == 4)
        {
         strncpy(player5, player, 18);
        }
        if(map == 5)
        {
         strncpy(player6, player, 18);
        }
       }
       else if (mode == 3)
       {


       }

       printsavegame();

       }

       printoptionsfile();

       system ("cls");

       gotoxy (25, 6);
       printf ("Score:");
       text_color(9);
       printf (" %d ", score);
       text_color(16);
       printf ("Hi-Score:");
       text_color(9);
       printf (" %d", hscore);
       text_color(16);
       gotoxy (10, 14);
       printf ("Wanna play again? Press Enter to replay or Escape to exit. ");

       key = getch();

       while (key != 13 && key != 27)
       {
        key = getch();
       }
       if (key == 13)
       {
        main();
       }
       else if (key == 27)
       {
        system ("cls");
        exit(0);
       }
 }
