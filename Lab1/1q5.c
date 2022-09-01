#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    
    char *str = argv[1];
    char *except = argv[2];
    char *dup = argv[3];

    for (int i=0; str[i] != '\0'; i++){
        if (!(str[i] >= 'a' && str[i]<='z')){
            printf("Error: String is not lowercase!");
            return -1;
        }else if (strchr(except, str[i]) != NULL){
            continue;    
        }else if (strchr(dup, str[i]) != NULL){
                putchar(str[i]);
                putchar(str[i]);
        }else{
            putchar(str[i]);
        }
    }
    printf("\n");
}
