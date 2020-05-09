// Copyrights for LoRixD - You have NO permission to upload or share this file WHITOUT permissions from LoRixD
//                       - If you want still to upload it look for permission of LoRixD on YouTube OR Gmail

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
