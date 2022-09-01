#include <stdio.h>
#include <string.h>

int countVowels(char *str);

int countVowels(char *str){
    int counter = 0;
    char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    
    for(int i = 0; i < strlen(str); i++){
        for(int j = 0; j < strlen(vowels); j++){
            if(str[i] == vowels[j] && str[i] >= 97 && str[i] <= 122) {
                counter++;
                str[i] = (str[i]-32);
                break;
            }else if(str[i] == vowels[j] && str[i] >= 65 && str[i] <= 90){
                counter++;
                str[i] = (str[i]+32);
                break;
            }
        }
    }
    return counter;
}
