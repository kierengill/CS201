#include <stdio.h>
#define INSIDE 0
#define OUTSIDE 1

main(){
    int c, location;
    location = OUTSIDE;
    while((c = getchar()) != EOF)
    {   
        if(c==' ' || c == '\t')
            location=OUTSIDE;
        else if (location == OUTSIDE) {
            location=INSIDE;
            putchar('\n');
            putchar(c);
        }
        else
            putchar(c);
    }
}