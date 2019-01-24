/********************************************************
 * Creatint for practice, free learning purpose.
 * 
 * filename: Demo.c
 * author: Martin
 * date: Thu Jan 24 2019
 * description: detect user input parameters usning in app
 * 
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include <sys/time.h>

/* functions definitions */
static void help(void);
static void showCurentTime(void);

int main(int argc, char *argv[])
{
    /* option sturct to store input parameters. */
    struct option long_option[] = {
        {"help", 0, NULL, 'h'},
        {"time", 0, NULL, 't'},
        {"param", 1, NULL, 'p'},
        {NULL, 0, NULL, 0},
    };

    int morehelp = 0;
    int distime = 0;
    int param = 0;
    
    /* Input detected. */
    while(1){
        int c;
        
        if ((c = getopt_long(argc, argv, "htp:", long_option, NULL)) < 0) {
            break;
        }
        
        switch (c)
        {
            case 'h':
                morehelp++;
                break;
            case 't':
                distime++;
                break;
            case 'p':
                param = atoi(optarg);
                break;
            default:
                break;
        }
    }
    /* Display help information. */
    if (morehelp) {
        help();
        return 0;
    }

    /* Display current time. */
    if (distime) {
        showCurentTime();
    }

    printf("Prameter: %d\n", param);
    printf("Hello, Martin\n");
    return 0;
}

static void help(void)
{
    printf("Usage: Demo [OPTION]...\n"
    "-h,--help      show help information\n"
    "-t,--time      current time\n"
    "-p,--parame    input parameter using in programe\n");
}

static void showCurentTime(void)
{
	time_t timep;
    time(&timep);
    printf("Current Datetime: %s", asctime(gmtime(&timep)));
}
