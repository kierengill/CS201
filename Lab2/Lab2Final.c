#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDSIZE 20
#define BUFSIZE 100

struct node2d *head = NULL;
char buf[BUFSIZE];
int bufp = 0;
char *name_1;
char *name_2;
char word[MAXWORDSIZE];
char word_2[MAXWORDSIZE];

int getword(char *word, int lim);
int getch(void);
void ungetch(int c);
void insertFront2D();
void insertBefore2D();
void insertFront1D();
void insertBefore1D();
void printAll();
void print1DList();
void find1D();
void find2D();

//STRUCTURE OF 1D NODES
struct node1d{
    struct node1d *next;
    char *name;
};

//STRUCTURE OF 2D NODES
struct node2d{
    struct node1d *first;
    char *name;
    struct node2d *down;
};

//MAIN METHOD
int main(){
    while (getword(word, MAXWORDSIZE) != EOF){
        if (strcmp(word, "insertFront2D") == 0){
            insertFront2D();
        }
        else if (strcmp(word, "insertBefore2D") == 0){
            insertBefore2D();
        }
        else if (strcmp(word, "insertFront1D") == 0){
            insertFront1D();
        }
        else if (strcmp(word, "insertBefore1D") == 0){
            insertBefore1D();
        }
        else if (strcmp(word, "printAll") == 0){
            printAll();
        }
        else if (strcmp(word, "print1DList") == 0){
            print1DList();
        }
        else if (strcmp(word, "find1D") == 0){
            find1D();
        }
        else if (strcmp(word, "find2D") == 0){
            find2D();
        }
        else{
            printf("No such command! Please try again: ");
        }
    }
    return 0;
}

//TEXTBOOK FUNCTIONS
int getword(char *word, int lim){
   int c, getch(void);
   void ungetch(int);
   char *w = word;

   while (isspace(c = getch()));
   if (c != EOF)
       *w++ = c;
   if (!isalpha(c)){
       *w = '\0';
       return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
    
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
       printf("ungetch: too many chars\n");
    else
       buf[bufp++] = c;
}

//LAB FUNCTIONS
void insertFront2D(){
    if (getword(word, MAXWORDSIZE)){
        name_1 = word;
    }
    struct node2d *newNode = (struct node2d *)malloc(sizeof(struct node2d));
    int length = strlen(name_1);
    newNode->name = malloc(length * sizeof(char));
    newNode->first = NULL;
    newNode->down = head;
    strcpy(newNode->name, name_1);
    if (head == NULL){
        head = newNode;
    }else{
        struct node2d *temp = head;
        head = newNode;
        newNode -> down = temp;   
    }
}

void insertBefore2D(){
    if (getword(word, MAXWORDSIZE)){
        name_1 = word;
    }
    if (getword(word_2, MAXWORDSIZE)){
        name_2 = word_2;
    }
    if (head==NULL){
        goto end;
    }
    struct node2d *curr = head;
    if(!strcmp(curr-> name, name_2)){
        struct node2d *newNode = (struct node2d *)malloc(sizeof(struct node2d));
        int length = strlen(name_1);
        newNode->name = malloc(length * sizeof(char));
        newNode->first = NULL;
        strcpy(newNode->name, name_1);
        struct node2d *temp = head;
        head = newNode;
        newNode -> down = temp;   
    }else{
        while ( (curr->down != NULL && (strcmp(curr->down->name, name_2)) )){
            curr = curr->down;
        }
        if (curr -> down != NULL){
            struct node2d *newNode = (struct node2d *)malloc(sizeof(struct node2d));
            int length = strlen(name_1);
            newNode->name = malloc(length * sizeof(char));
            newNode->first = NULL;
            strcpy(newNode->name, name_1);
            struct node2d *temp = curr->down;
            curr->down = newNode;
            newNode->down = temp;
        }else{
            end:
            printf("Error: 2D node %s not found!\n", name_2);
            printf("Terminating the run!\n");
            exit(1);
        }
    }
}

void insertFront1D(){
    if (getword(word, MAXWORDSIZE)){
        name_1 = word;
    }
    if (getword(word_2, MAXWORDSIZE)){
        name_2 = word_2;
    }
    struct node2d *curr = head;
    while (curr != NULL && strcmp(curr -> name, name_2)){
        curr = curr -> down;
    }
    if (curr != NULL){
        struct node1d *newNode = (struct node1d *)malloc(sizeof(struct node1d));
        struct node1d *temp = curr -> first;
        int length = strlen(name_1);
        newNode->name = malloc(length * sizeof(char));
        curr->first = newNode;
        newNode -> next = temp;
        strcpy(newNode->name, name_1);
        if (temp == NULL){
            curr->first = newNode;
            newNode -> next = NULL;
        }else{
            curr->first = newNode;
            newNode->next = temp;
        }
    }else{
        printf("Error: 2D node %s not found!\n", name_2);
        printf("Terminating the run!\n");
        exit(1);
    }
}

void insertBefore1D(){
    if (getword(word, MAXWORDSIZE)){
        name_1 = word;
    }
    if (getword(word_2, MAXWORDSIZE)){
       name_2 = word_2;
    }
    struct node2d *curr = head;
    int found = 0;
    while (curr != NULL){
        if (curr -> first != NULL){
            struct node1d *temp = curr->first;
            if (strcmp(temp->name, name_2)==0){
                struct node1d *newNode = (struct node1d *)malloc(sizeof(struct node1d));
                newNode -> name = malloc (strlen(name_1)* sizeof(char));
                strcpy(newNode->name, name_1);
                curr->first = newNode;
                newNode->next = temp;
                found = 1;
                break;
            }else{
                while((temp->next != NULL && (strcmp(temp->next->name, name_2)!=0))){
                    temp = temp->next;
                }
                if (temp->next != NULL){
                    struct node1d *newNode = (struct node1d *)malloc(sizeof(struct node1d));
                    newNode -> name = malloc (strlen(name_1)* sizeof(char));
                    strcpy(newNode->name, name_1);
                    newNode -> next = temp -> next;
                    temp -> next = newNode;
                    found = 1;
                    goto end;
                }
            }
        }
        curr = curr-> down;
    }
    end:

    if (found == 0){
        printf("Error: 1D node %s not found!\n", name_2);
        printf("Terminating the run!\n");
        exit(1);
    }
}

void printAll()
{
    struct node2d *curr = head;
    while (curr != NULL){
        printf("2d node name=%s\n", curr->name);
        if (curr->first != NULL){
            struct node1d *temp = curr->first;
            while (temp != NULL){
               printf("  1d node name=%s\n", temp->name);
               temp = temp->next;
            }
        }
        curr = curr->down;
    }
}

void print1DList(){
    if (getword(word, MAXWORDSIZE)){   
       name_1 = word;
    }
    int found = 0; 
    struct node2d *curr = head;
    while (curr != NULL && found == 0){
        if (strcmp(curr->name, name_1) == 0){
            found = 1;

            printf("2d node name=%s\n", curr->name);

            if (curr->first != NULL){
                struct node1d *temp = curr->first;

                while (temp != NULL){
                    printf("  1d node name=%s\n", temp->name);
                    temp = temp->next;
                }
            }
        }
        curr = curr->down;
    }
    if (found == 0){
        printf("Error: 2D node %s not found!\n", name_1);
        printf("Terminating the run!\n");
        exit(1);
    }
}

void find1D(){
    if (getword(word, MAXWORDSIZE)){
       name_1 = word;
    }
    int found = 0;
    struct node2d *curr = head;
    while (curr != NULL){
       if (curr->first != NULL){
           struct node1d *temp = curr->first;
           while (temp != NULL){
               if (strcmp(temp->name, name_1)){
                   temp = temp->next;
                }else{
                   printf("found\n");
                   found = 1;
                   break;
                }
            }
        }
       curr = curr->down;
    }
    if (found == 0){
       printf("not found\n");
    }
}

void find2D(){
    if (getword(word, MAXWORDSIZE)){
        name_1 = word;
    }
    int found = 0;
    struct node2d *curr = head;
    while (curr != NULL){
        if (strcmp(curr->name, name_1)){
           curr = curr->down;
        }else{
           printf("found\n");
           found = 1;
           break;
        }
    }
    if (found == 0){
        printf("not found\n");
    }
}