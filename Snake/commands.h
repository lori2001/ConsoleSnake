
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
           || foods[obstacle_pos.y][obstacle_pos.x] == foodicon);


     base[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
     obstacl[obstacle_pos.y][obstacle_pos.x] = obstacleicon;
  }
  else if (command == 2)
  {
     obstacle_pos.x = posx;
     obstacle_pos.y = posy;

     if ( base[obstacle_pos.y][obstacle_pos.x]  == snake_head
       || base[obstacle_pos.y][obstacle_pos.x]  == snake_form )
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


void draw_snake2()
{
     body *curr;
     curr = body_head2;

     if (curr != NULL)
     {
      base[curr->y][curr->x] = snake_head2;
      snake2[curr->y][curr->x] = snake_head2;
      curr = curr->next;
     }

     while (curr != NULL)
     {
       base[curr->y][curr->x] = snake_form2 ;
       snake2[curr->y][curr->x] = snake_head2;
       curr = curr->next;
     }

     self_eat2();
}
void add_body2(int y, int x)
{
     body *tmp2;

     snakelong2 ++;

     tmp2 = (body *) malloc ( sizeof(body) );
     if (tmp2 == NULL) {
             system("COLOR FC");
             printf ("\nAn error occured while allocating memory.");
             getchar();
             exit(1);
     }

     if (body_head2 == NULL) {
              body_head2 = tmp2;
              tmp2->prev = NULL;
     }
     else {
          body_tail2->next = tmp2;
          tmp2->prev = body_tail2;
     }

     tmp2->y = y;
     tmp2->x = x;
     tmp2->next = NULL;
     body_tail2 = tmp2;
}
void self_eat2()
{
     body *tmp2;
     tmp2 = body_head2->next;

     while (tmp2 != NULL){
           if ( (body_head2->y == tmp2->y) && (body_head2->x == tmp2->x)){
                tmp2 = NULL;
                end();
           }
           else {
                tmp2 = tmp2->next;
           }
     }
}
void move2(int x, int y)
{
     body *curr;
     curr = body_tail2;

     base[body_tail2->y][body_tail2->x] = ' ';

     while (curr != body_head2) {
           curr->y = curr->prev->y;
           curr->x = curr->prev->x;
           curr = curr->prev;
     }

     body_head2->y = y;
     body_head2->x = x;

     draw_snake2();

     check();
}


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
      snake2[y][x] = ' ';

      base[y][x] = ' ';
      prevbase[y][x] = ' ';
     }
    }

     body_head = NULL;
     body_tail = NULL;

     body_head2 = NULL;
     body_tail2 = NULL;

     z = command = first = 1;

     stprepeat = obstnum = anim = foodnum = coins = score = hscore = snakelong1 = snakelong2 = newhiscore = 0;
}

