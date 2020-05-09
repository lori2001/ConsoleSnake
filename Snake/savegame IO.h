
void printsavegame()
{
   savegame = fopen("savegame.txt", "w"); //http://web.cs.swarthmore.edu/~newhall/unixhelp/C_files.html

     fprintf (savegame,"Player Name : %s ", player1);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 0 && mode == 1)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day1,month1,daynr1,h1,m1,s1,y11);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo1);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player Name : %s ", player2);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 1 && mode == 2)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day2,month2,daynr2,h2,m2,s2,y2);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo2ma1);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player Name : %s ", player3);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 2 && mode == 2)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day3,month3,daynr3,h3,m3,s3,y3);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo2ma2);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player Name : %s ", player4);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 3 && mode == 2)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day4,month4,daynr4,h4,m4,s4,y4);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo2ma3);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player Name : %s ", player5);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 4 && mode == 2)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day5,month5,daynr5,h5,m5,s5,y5);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo2ma4);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player Name : %s ", player6);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && map == 5 && mode == 2)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day6,month6,daynr6,h6,m6,s6,y6);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Score : %d ", hscoremo2ma5);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player1 Name : %s ", player7);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player2 Name : %s ", player8);
     fprintf (savegame,  "\x0A");
  if (newhiscore == 1 && mode == 3)
  {
     fprintf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fprintf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day7,month7,daynr7,h7,m7,s7,y7);
  }
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player1 Score : %d ", hscoremo3p1);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Player2 Score : %d ", hscoremo3p2);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"Won by %c", player9);
     fprintf (savegame,  "\x0A");
     fprintf (savegame,"____________________________________________");


     fclose  (savegame);

     }
void scansavegame()
{
    savegame = fopen("savegame.txt", "r"); //http://web.cs.swarthmore.edu/~newhall/unixhelp/C_files.html

    if (savegame == NULL)
    {
     fclose  (savegame);
     savegame = fopen("savegame.txt", "w");

     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");
     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");
     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");
     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");
     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");
     fprintf(savegame,"Player Name : NotPlayed");                        fprintf (savegame,  "\x0A");
     fprintf(savegame,"Played Date : Fri Feb 6 0:14:31 2015");           fprintf (savegame,  "\x0A");
     fprintf(savegame,"Score : 0 ");                                     fprintf (savegame,  "\x0A");
     fprintf(savegame,"____________________________________________");   fprintf (savegame,  "\x0A");

     fclose  (savegame);
    }
    else
    {
     fscanf (savegame,"Player Name : %s ", player1);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day1,month1,&daynr1,&h1,&m1,&s1,&y11);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo1);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player Name : %s ", player2);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day2,month2,&daynr2,&h2,&m2,&s2,&y2);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo2ma1);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player Name : %s ", player3);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day3,month3,&daynr3,&h3,&m3,&s3,&y3);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo2ma2);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player Name : %s ", player4);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day4,month4,&daynr4,&h4,&m4,&s4,&y4);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo2ma3);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player Name : %s ", player5);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day5,month5,&daynr5,&h5,&m5,&s5,&y5);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo2ma4);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player Name : %s ", player6);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day6,month6,&daynr6,&h6,&m6,&s6,&y6);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Score : %d ", &hscoremo2ma5);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player1 Name : %s ", player7);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player2 Name : %s ", player8);
     fscanf (savegame,  "\x0A");
  if (newhiscore == 1 && mode == 3)
  {
     fscanf (savegame,"Played Date : %s",ctime(&mytime));
  }
  else
  {
     fscanf (savegame,"Played Date : %s %s %d %d:%d:%d %d",day7,month7,&daynr7,&h7,&m7,&s7,&y7);
  }
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player1 Score : %d ", &hscoremo3p1);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Player2 Score : %d ", &hscoremo3p2);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"Won by %c", player9);
     fscanf (savegame,  "\x0A");
     fscanf (savegame,"____________________________________________");

     fclose  (savegame);
}
}
