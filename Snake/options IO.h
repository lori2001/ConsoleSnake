
void scanoptionsfile()
{
    optionsfile = fopen("options.txt", "r");

    if (optionsfile == NULL)
    {
     fclose  (optionsfile);
     optionsfile = fopen("options.txt", "w");

     fprintf (optionsfile, "Soundstatus = 0");

     fclose  (optionsfile);
    }
    else
    {
     optionsfile = fopen("options.txt", "r"); //http://web.cs.swarthmore.edu/~newhall/unixhelp/C_files.html

     fscanf (optionsfile, "Soundstatus = %d", &soundstatus);
     fclose (optionsfile);
    }
}
void printoptionsfile()
{
 optionsfile = fopen("options.txt", "w"); //http://web.cs.swarthmore.edu/~newhall/unixhelp/C_files.html

 fprintf (optionsfile,  "Soundstatus = %d",soundstatus);

 fclose (optionsfile);

}
