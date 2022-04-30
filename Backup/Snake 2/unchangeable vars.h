// Copyrights for LoRixD - You have NO permission to upload or share this file WHITOUT permissions from LoRixD
//                       - If you want still to upload it look for permission of LoRixD on YouTube OR Gmail

typedef struct snake_body
{ // Snake's body
       int y;
       int x;
       struct snake_body *prev;
       struct snake_body *next;
} body;

struct item
{ // Food position
       int y;
       int x;
} food_pos ,obstacle_pos;

  char base[MAX_Y][MAX_X];     // -Base- (all output will be saved there)
  char prevbase[MAX_Y][MAX_X]; // will help at fast output)

  char foods[MAX_Y][MAX_X];    // foods will be saved there
  char obstacl[MAX_Y][MAX_X];  // obstacles will be here

  char snake1[MAX_Y][MAX_X];   //the normal snake will be here

  char day[5] , month[5];
  char day1[5],month1[5];
  char day2[5],month2[5];
  char day3[5],month3[5];
  char day4[5],month4[5];
  char day5[5],month5[5];
  char day6[5],month6[5];
  char day7[5],month7[5];

  int daynr ,h ,m ,s ,y ;
  int daynr1,h1,m1,s1,y11;
  int daynr2,h2,m2,s2,y2;
  int daynr3,h3,m3,s3,y3;
  int daynr4,h4,m4,s4,y4;
  int daynr5,h5,m5,s5,y5;
  int daynr6,h6,m6,s6,y6;
  int daynr7,h7,m7,s7,y7;

  body *body_head = NULL; // Snake's head
  body *body_tail = NULL; // Snake's taildirection();

  int key, prev_key, keypressed; // recognising keys
  int coins, newhiscore, score, score2; // scores hiscores and coin numbers will be saved
  int z = 1; // for for() commands
  int first = 1; // this value is 1(true) if the current display is the first and its other number(false) if not
  int mode, map; // saves mode/map
  int level;// value of level...
  int score_verifier;

  int spider_x,spider_y;
  int spider_prev_x,spider_prev_y;
  int movement;

  int last_time;
  int eat_time;
  int spider_move;

  int hscoremo1,  // saves the scores
      hscoremo2ma1,
      hscoremo2ma2,
      hscoremo2ma3,
      hscoremo2ma4,
      hscoremo2ma5,
      hscoremo3p1,
      hscoremo3p2,
      hscore;

  int // objmo1,
      objmo2ma1 = 250,
      objmo2ma2 = 230,
      objmo2ma3 = 850,
      objmo2ma4 = 250;
  //  objmo2ma5,
  /*  objmo3p1,
      objmo3p2;*/

 time_t mytime; //has as value the current time

  int ms; // helps at dispaying maps
  int anim = 0; // helps at animating maps
  int snakelong1 = 0;// saves the snake long
  int press, command = 1, stprepeat = 0; //helps at switching the menu
  int obstnum = 0, foodnum = 0; // saves the obstacles/foods number
  int soundstatus = 0; // its 0 if the sound is off or 1 if the sound is on

  char player [20], // save/display the players' name
       player1[20],
       player2[20],
       player3[20],
       player4[20],
       player5[20],
       player6[20],
       player7[20],
       player8[20],
       player9[20] = {"Not_Played"};

  FILE *savegame;     // makes a variable that helps opening files
  FILE *optionsfile;

CONSOLE_CURSOR_INFO ConCurInf;  // helps at hiding cursor
clock_t pastclock; // makes a pastclock variable that helps measuring the time better

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.
