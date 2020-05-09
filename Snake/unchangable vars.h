typedef struct snake_body
{ // Snake's body
       int y;
       int x;
       struct snake_body *prev;
       struct snake_body *next;
} body,body2;

struct item
{ // Food position
       int y;
       int x;
} food_pos ,obstacle_pos;

  char day[5],month[5];
  char day1[5],month1[5];
  char day2[5],month2[5];
  char day3[5],month3[5];
  char day4[5],month4[5];
  char day5[5],month5[5];
  char day6[5],month6[5];
  char day7[5],month7[5];

  int daynr,h,m,s,y;
  int daynr1,h1,m1,s1,y11;
  int daynr2,h2,m2,s2,y2;
  int daynr3,h3,m3,s3,y3;
  int daynr4,h4,m4,s4,y4;
  int daynr5,h5,m5,s5,y5;
  int daynr6,h6,m6,s6,y6;
  int daynr7,h7,m7,s7,y7;

body *body_head = NULL; // Snake's head
body *body_tail = NULL; // Snake's taildirection();

body *body_head2 = NULL; // Snake's head
body *body_tail2 = NULL; // Snake's taildirection();

int key , prev_key, keypressed, coins , z = 1, first = 1, mode, map ,informations,newhiscore , objective;

char base[MAX_Y][MAX_X]; // Base
char prevbase[MAX_Y][MAX_X];

char foods[MAX_Y][MAX_X];
char obstacl[MAX_Y][MAX_X];

char snake1[MAX_Y][MAX_X];
char snake2[MAX_Y][MAX_X];

int hscoremo1,
    hscoremo2ma1,
    hscoremo2ma2,
    hscoremo2ma3,
    hscoremo2ma4,
    hscoremo2ma5,
    hscoremo3p1,
    hscoremo3p2,
    hscore;
int score,score2;
time_t mytime;

FILE *savegame;
FILE *optionsfile;

HANDLE hOut;
CONSOLE_CURSOR_INFO ConCurInf;
clock_t pastclock;

int ms;
int anim = 0 , snakelong1 = 0 , snakelong2 = 0;
int press, command = 1, stprepeat = 0;
int obstnum = 0, foodnum = 0;
int soundstatus = 0;

char player [20],
     player1[20],
     player2[20],
     player3[20],
     player4[20],
     player5[20],
     player6[20],
     player7[20],
     player8[20],
     player9[20] = {"Not_Played"};
