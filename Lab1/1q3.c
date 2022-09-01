#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    int c, duplicate = 0, upper = 0;

    if (argc == 1){
        return 0;
    }else if (argc == 2){
        if (!strcmp(argv[1], "-d")){
            duplicate = 1;
        }else if (!strcmp(argv[1], "-u")){
            upper = 1;
        }else if (!strcmp(argv[1], "-du")){
            duplicate = 1;
            upper = 1;
        }else if (!strcmp(argv[1], "-ud")){
            duplicate = 1;
            upper = 1;
        }
    }else if (argc == 3){
        if ((!strcmp(argv[1], "-d")) && (!strcmp(argv[2], "-u"))){
            duplicate = 1;
            upper = 1;
        }else if ((!strcmp(argv[1], "-u")) && (!strcmp(argv[2], "-d"))){
            duplicate = 1;
            upper = 1;
        }
    }

    printf("Enter your character(s): ");
    while ((c = getchar()) != '\n'){
        if (upper == 1 && isalpha(c)){
            putchar(toupper(c));
            
            if (duplicate == 1){
                putchar(toupper(c));
            }
        }else{
            putchar(c);
            if (duplicate == 1){
                putchar(c);
            }
        }
    }   

}

