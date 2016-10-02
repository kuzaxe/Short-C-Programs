#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n;
    if (argc != 2 || (n = atoi(argv[1])) < 0) {
        fprintf(stderr, "usage: rot n\n");
        return(1);
    }

    if (n>25){
	n=n%26;	
    }

    int c;
    while ((c = getchar()) != EOF) {
	int exceed=0;
	int newChar=c;
	
	if (c>96 && c<123) {
	    newChar+=n;
	    if (newChar>122) {exceed=1;}      
	} else if (c>64 && c<91) {
	    newChar+=n;
	    if (newChar>90) {exceed=1;}
	}

	if (exceed){newChar=newChar-26;}
	putchar(newChar);
    }
    return(0);
}

