#include <stdio.h>
#include <string.h>

int reorder(char **s1, char **s2, char **s3);

int reorder(char **s1, char **s2, char **s3){
    char word1[strlen(*s1) + 1];
    strcpy(word1, *s1);

    char word2[strlen(*s2) + 1];
    strcpy(word2, *s2);

    char word3[strlen(*s3) + 1];
    strcpy(word3, *s3);


    if(strlen(word1) == strlen(word2) && strlen(word1) == strlen(word3) && strlen(word2) == strlen(word3)){
        printf("All 3 are equal length.\n");
        return strlen(word1);   
    }

    else if(strlen(word1) == strlen(word2) || strlen(word1) == strlen(word3) || strlen(word2) == strlen(word3)){
         printf("Two are equal length.\n");
        return 2;

    }else{
        printf("All 3 are unequal length.\n");
        if(strlen(word1) > strlen(word2)){
            if(strlen(word1) > strlen(word3)){
                *s1 = word1;

                if(strlen(word2) > strlen(word3)){
                    *s2 = word2;
                    *s3 = word3;

                }else{
                    *s2 = word3;
                    *s3 = word2;
                }

            }else{
                *s1 = word3;
                *s2 = word1;
                *s3 = word2;
            }
                
        }else if(strlen(word2) > strlen(word3)){
            *s1 = word2;

            if(strlen(word1) > strlen(word3)){
                *s2 = word1;
                *s3 = word3;

            }else{
                *s2 = word3;
                *s3 = word1;
            }

        }else{
            *s1 = word3;
            *s2 = word2;
            *s3 = word1;
        }
        return 1;
    }
}

