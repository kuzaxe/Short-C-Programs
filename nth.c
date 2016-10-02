#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n;
    if (argc != 2 || (n = atoi(argv[1])) < 0) {
        fprintf(stderr, "usage: rot n\n");
        return(1);
    }

    int state;
    state=0;
    int i;
    i=1;

    int c; 

    while ((c = getchar()) != EOF) {
        if (state == 0) {
	    if (c == ' ' || c == '\t') {
		state=0;
	    } else if (c == '\n') {
		printf("\n"); 
                i=0;
		state=0;
            } else if (i<n) {
                state=1;
            } else {
                putchar(c); 
                state=2;
            }
        } else if (state == 1) {
            if (c == ' ' || c == '\t') {
                i=i+1;
		state=0;
            }
            else if (c == '\n') {
                printf("\n"); 
                i=1; 
                state=0;
            } else {
		state=1;
	    }
        } else if (state == 2) {
            if (c == ' ' || c == '\t') {
                state=3;
            } 
            else if (c == '\n') {
                printf("\n"); 
                i=1; 
                state=0;
            }
            else {
                putchar(c);
		state=2;
            }
        } else if (state == 3) {
            if (c == '\n') {
                printf("\n");
                i=1; 
                state=0;
            }
        }
    }

    return(0);
}

