#include <stdio.h>
void changeltox (char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == 'l'){
            s[i] = 'x';
        }             
    } 
  }