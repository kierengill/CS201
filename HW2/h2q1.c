#include <stdio.h>
int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1;++i){
        if ((c=getchar())== EOF || c == '\n') {
            break;
        }
        s[i] = c;
    }
    if (c=='\n') {
        s[i]= c;
        ++i;
    }
    s[i] = '\0';
    return i;
  }