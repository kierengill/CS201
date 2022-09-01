#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isdiv35();

int main(int argc, char *argv[]){
    
    if(argc != 3){
        printf("Error: Invalid number of arguments!\n");
        return -1;
    }
    
    int lowerBound = atoi(argv[1]);
    int upperBound = atoi(argv[2]);
    
    if(lowerBound > upperBound){
        printf("Error: arg1 > arg 2!\n");
        return -1;
    }else{
        for(int i = lowerBound; i <= upperBound; i++){
            int x = isdiv35(i);
            if(x == 1){
                printf("%i is divisible by 3 and not divisible by 5.\n", i);
            }else if(x ==2){
                printf("%i is divisible by 5 and not divisible by 3.\n", i);
            }else if(x == 3){
                printf("%i is divisible by both 3 and 5.\n", i);
            }else if(x==4){
                printf("%i is not divisible by 3 and not divisible by 5.\n", i);
            }
        }
    }
}

int isdiv35(int n){

    if (n%3 == 0){
        if (n%5 == 0){
            return 3;

        }else{
            return 1;
        }

    }else if (n%5 == 0){
        return 2;

    }else{
        return 4;
    }
}
