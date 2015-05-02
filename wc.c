#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) 
{
    FILE *fp;
    int charcount = 0;
    int wordcount = 0;
    int linecount = 0;
    int charflag = 0;
    int wordflag = 0;
    int lineflag = 0;
    int inword = 0;
    int i;
    char line[256];
    for(i = 0; i < argc; i++) // set flags
    {
        if (strcmp(argv[i], "-m") == 0)
        {    
            charflag = 1;
        }
        if (strcmp(argv[i], "-w") == 0)
        {    
            wordflag = 1;
        }
        if (strcmp(argv[i], "-l") == 0)
        {    
            lineflag = 1;
        }
        if (strcmp(argv[i], "-ml") == 0 || strcmp(argv[i], "-lm") == 0)
        {    
            charflag = 1;
            lineflag = 1;
        }
        if (strcmp(argv[i], "-mw") == 0 || strcmp(argv[i], "-wm") == 0)
        {    
            charflag = 1;
            wordflag = 1;
        }
        if (strcmp(argv[i], "-wl") == 0 || strcmp(argv[i], "-lw") == 0)
        {    
            wordflag = 1;
            lineflag = 1;
        }
        if (strcmp(argv[i], "-mwl") == 0 || strcmp(argv[i], "-mlw") == 0 || strcmp(argv[i], "-lmw") == 0
                || strcmp(argv[i], "-lwm") == 0 || strcmp(argv[i], "-wlm") == 0 || strcmp(argv[i], "-wml") == 0)
        {    
            charflag = 1;
            wordflag = 1;
            lineflag = 1;
        }
    }
    for(i = 0; i < argc; i++)
    {
        fp = fopen(argv[i], "r"); // opens first command line argument file
    }
    if (fp) 
    {
        while (fgets(line, sizeof(line), fp) != NULL) // read a line
        {   
            linecount++; // increment line counter
            for (i = 0; i < strlen(line); i++)
            {
                if(!isspace(line[i]))
                {
                    inword = 1;
                }
                else
                {
                   if (inword)
                   {
                      inword = 0;
                      wordcount++; // increment word counter
                   }
                }
                charcount++; // increment character counter
            }         
        }
        // print results
        if (lineflag == 1 && wordflag == 0 && charflag == 0)
        {
            printf("%d %s\n", linecount, argv[2]);
        }
        else if (lineflag == 0 && wordflag == 1 && charflag == 0)
        {
            printf("%d %s\n", wordcount, argv[2]);
        }
        else if (lineflag == 0 && wordflag == 0 && charflag == 1)
        {
            printf("%d %s\n", charcount, argv[2]);
        }
        else if (lineflag == 1 && wordflag == 1 && charflag == 0)
        {
            printf("%d %d %s\n", linecount, wordcount, argv[2]);
        }
        else if (lineflag == 1 && wordflag == 0 && charflag == 1)
        {
            printf("%d %d %s\n", linecount, charcount, argv[2]);
        }
        else if (lineflag == 0 && wordflag == 1 && charflag == 1)
        {
            printf("%d %d %s\n", wordcount, wordcount, argv[2]);
        }
        else if (lineflag == 1 && wordflag == 1 && charflag == 1)
        {
            printf("%d %d %d %s\n", linecount, wordcount, charcount, argv[2]);
        }
        else if (lineflag == 1 && wordflag == 1 && charflag == 1)
        {
            printf("%d %d %d %s\n", linecount, wordcount, charcount, argv[2]);
        }
        else if (lineflag == 0 && wordflag == 0 && charflag == 0 && argc == 2)
        {
            printf("%d %d %d %s\n", linecount, wordcount, charcount, argv[1]);
        }
        fclose(fp); // close file
    }
    else
    {
        printf("ERROR: File not found.\n");
    }
    return 0;
}
