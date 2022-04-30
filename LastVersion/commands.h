// Copyrights for LoRixD - You have NO permission to upload or share this file WHITOUT permissions from LoRixD
//                       - If you want still to upload it look for permission of LoRixD on YouTube OR Gmail

int random_between(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void wait(double waittime)
{
    clock_t wait;

    wait = clock() - pastclock + waittime * CLOCKS_PER_SEC;
    while ( clock() - pastclock < wait ) {/*do nothing ...*/}
}
void gotoxy(unsigned short x, unsigned short y)
{
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position = {x, y};
     SetConsoleCursorPosition(handle, position);
}
void add_body(int y, int x)
{
     body *tmp;

     snakelong1 ++;

     tmp = (body *) malloc ( sizeof(body) );
     if (tmp == NULL) {
             system("COLOR FC");
             printf ("\nAn error occured while allocating memory.");
             getchar();
             exit(1);
     }

     if (body_head == NULL) {
              body_head = tmp;
              tmp->prev = NULL;
     }
     else {
          body_tail->next = tmp;
          tmp->prev = body_tail;
     }

     tmp->y = y;
     tmp->x = x;
     tmp->next = NULL;
     body_tail = tmp;
}
void move(int x, int y)
{
     body *curr;
     curr = body_tail;

     base[body_tail->y][body_tail->x] = ' ';

     while (curr != body_head) {
           curr->y = curr->prev->y;
           curr->x = curr->prev->x;
           curr = curr->prev;
     }

     body_head->y = y;
     body_head->x = x;

     draw_snake();

     check();
}
void text_color(int colnum)
{
     WORD wColor;
     //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (colnum & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;

    /* for(z = 1; z<=16; z++)
  {
    text_color(z);
    printf("%d, ",z);
  } */
}
void draw_snake()
{
     body *curr;
     curr = body_head;

     if (curr != NULL)
     {
      base[curr->y][curr->x] = snake_head;
      snake1[curr->y][curr->x] = snake_head;
      curr = curr->next;
     }

     while (curr != NULL)
     {
       base[curr->y][curr->x] = snake_form ;
       snake1[curr->y][curr->x] = snake_head;
       curr = curr->next;
     }

     self_eat();
}
void food(int posx , int posy , int command)
{
   foodnum++;

  if (command == 1)
  {
     do
     {
     // Set the random position of food
     food_pos.x = (rand() % (MAX_X - 3) ) + 1;
     food_pos.y = (rand() % (MAX_Y - 3) ) + 1;
     }
     while(base[food_pos.y][food_pos.x] == snake_head || base[food_pos.y][food_pos.x] == snake_form ||
           base[food_pos.y][food_pos.x] == obstacleicon );

     base[food_pos.y][food_pos.x] = foodicon;
     foods[food_pos.y][food_pos.x] = foodicon;
  }
  else if (command == 2)
  {
     food_pos.x = posx;
     food_pos.y = posy;

     if(base[food_pos.y][food_pos.x] == snake_head || base[food_pos.y][food_pos.x] == snake_form
        || base[food_pos.y][food_pos.x] == obstacleicon )
     {
      system("cls");
      system("COLOR FC");
      printf ("\nSomething meets the food.");
      printf ("\nPlease correct the food num %d at %d-%d", foodnum,food_pos.x,food_pos.y);
      getchar();
      exit(1);
     }

     base[food_pos.y][food_pos.x] = foodicon;
     foods[food_pos.y][food_pos.x] = foodicon;
  }
  else
  {
    system("COLOR FC");

    printf ("Error , %d food command not existing at y = %d x = %d!", command,posy,posx);
    printf ("\nPlease retry the game, If the same problem appears reinstall the program !");

    getchar();
    exit(1);
  }
}
void obstacles(int posx , int posy , int command)
{
   obstnum++;

  if (command == 1)
  {
     do
     {
     // Set the random position of food
     obstacle_pos.x = (rand() % (MAX_X - 3) ) + 1;
     obstacle_pos.y = (rand() % (MAX_Y - 3) ) + 1;
     }
     while(   base [obstacle_pos.y][obstacle_pos.x] == snake_head
           || base [obstacle_pos.y][obstacle_pos.x] == snake_form
           || foods[obstacle_pos.y][obstacle_pos.x] == foodicon
           || (obstnum == 1 && (obstacle_pos.y == body_head->y || obstacle_pos.x == body_head->x)));

     base[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
     obstacl[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
  }
  else if (command == 2)
  {
     obstacle_pos.x = posx;
     obstacle_pos.y = posy;

     if (( base[obstacle_pos.y][obstacle_pos.x]  == snake_head
       || base[obstacle_pos.y][obstacle_pos.x]  == snake_form) && mode != 2 && map != 5)
     {
      end();
     }


     base[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
     obstacl[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
  }
  else
  {
    system("COLOR FC");

    printf ("Error , %d obstacle command not existing at y = %d x = %d!", command,posy,posx);
    printf ("\nPlease retry the game, If the same problem occures reinstall the program !");

    getchar();
    exit(1);
  }
}
void erase_obstacle(int x,int y)
{
 gotoxy(x,y);

   if (foods[y][x] == foodicon)
   {
    base[y][x] = foodicon;
   }
 /*else if (snake1[y][x] == snake_head )
   {
    base[y][x] = snake_head;
   }
   else if (snake1[y][x] == snake_form)
   {
    base[y][x] = snake_form;
   }*/
   else if (base[y][x] == obstacleicon || obstacl[y][x] == obstacleicon)
   {
    base[y][x] = ' ';
    obstacl[y][x] = ' ';
   }
}

void self_eat()
{
     body *tmp;
     tmp = body_head->next;

     while (tmp != NULL){
           if ( (body_head->y == tmp->y) && (body_head->x == tmp->x)){
                tmp = NULL;
                end();
           }
           else {
                tmp = tmp->next;
           }
     }
}

/*void snakesound()
{
 if ((clock() - last_time) >= ( 7 * CLOCKS_PER_SEC) &&
     (clock() - eat_time ) >= ( 2 * CLOCKS_PER_SEC) && soundstatus == 1 )
 {
  last_time = clock();

  PlaySound("sounds\\Snake Hiss.wav", NULL, SND_ASYNC);
 }
}*/

void deallocate()
{
    int y,x;

    for (y = 0; y < MAX_Y ; y++)
    {
     for (x = 0; x < MAX_X ; x++)
     {
      foods[y][x]   = ' ';
      obstacl[y][x] = ' ';

      snake1[y][x]   = ' ';

      base[y][x] = ' ';
      prevbase[y][x] = ' ';
     }
    }

     body_head = NULL;
     body_tail = NULL;

     mytime = time(NULL);

     z = command = first = 1;

     stprepeat = obstnum = anim = foodnum = coins = score = hscore = snakelong1 = newhiscore = score_verifier = map = mode = 0 ;
}

void erase_spider(int x,int y)
{
  erase_obstacle(x-2,y+2);
  erase_obstacle(x-1,y+2);
  erase_obstacle(x,y+2);
  erase_obstacle(x+2,y+2);
  erase_obstacle(x+1,y+2);

  erase_obstacle(x-2,y+1);
  erase_obstacle(x-1,y+1);
  erase_obstacle(x,y+1);
  erase_obstacle(x+2,y+1);
  erase_obstacle(x+1,y+1);

  erase_obstacle(x-2,y);
  erase_obstacle(x-1,y);
  erase_obstacle(x,y);
  erase_obstacle(x+2,y);
  erase_obstacle(x+1,y);

  erase_obstacle(x-2,y-1);
  erase_obstacle(x-1,y-1);
  erase_obstacle(x,y-1);
  erase_obstacle(x+2,y-1);
  erase_obstacle(x+1,y-1);

  erase_obstacle(x-2,y-2);
  erase_obstacle(x-1,y-2);
  erase_obstacle(x,y-2);
  erase_obstacle(x+2,y-2);
  erase_obstacle(x+1,y-2);
  }


void draw_spider(int x,int y)
{
 movement++;

 spider_prev_x = spider_x;
 spider_prev_y = spider_y;

 spider_x = x;
 spider_y = y;

 /*if(movement % 2 == 0)
 {
 erase_spider(x,y);

 obstacles(x,y+1,2);

 obstacles(x-1,y+2,2);
 obstacles(x  ,y+2,2);
 obstacles(x+1,y+2,2);

 obstacles(x+2,y+1,2);
 obstacles(x-2,y+1,2);

 obstacles(x-1,y,2);
 obstacles(x  ,y,2);
 obstacles(x+1,y,2);

 obstacles(x-1,y-1,2);
 obstacles(x+1,y-1,2);
 obstacles(x+2,y+2,2);
 obstacles(x-2,y+2,2);
 }
 else                               //this is the animation, but it has some troubles.. disabled
 {
*/
 obstacles(x,y,2);

 obstacles(x  ,y-1,2);
 obstacles(x+1,y-1,2);
 obstacles(x-1,y-1,2);

 obstacles(x+2,y-2,2);
 obstacles(x-2,y-2,2);

 obstacles(x+2,y+1,2);
 obstacles(x-2,y+1,2);

 obstacles(x  ,y+1,2);
 obstacles(x-1,y+1,2);
 obstacles(x+1,y+1,2);

 obstacles(x+2,y+2,2);
 obstacles(x-2,y+2,2);
// }



}

