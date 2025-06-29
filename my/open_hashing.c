#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B 4
#define W 6
enum yn {yes, no};

typedef struct cell{
    char name[W+1];
    struct cell *next;
} cell;

void insert(char *x, cell **A);
void delete(char *x, cell **A);
enum yn member(char *x, cell **A);
int h(char *x);


int main(void){
    struct cell *A[B], *q;
    int j;
    enum yn t;
    for(j=0; j<B; j++) A[j]=NULL;
    insert("abcdef", A);
    insert("abcdefg", A);
    insert("abc", A);
    insert("cd", A);
    insert("def", A);
    insert("abcdef", A);
    insert("azc", A);
    insert("azd", A);
    insert("bzd", A);
    for(j=0; j<B; j++){   
        printf("A[%d] = %p, ", j, A[j]);
        q=A[j];
        while(q != NULL) {
           printf("%s, next = %p, ", q->name, q->next);
           q=q->next;
        }
        printf("\n");
    }
    t=member("azd",A);
    if(t==yes) printf("member = yes\n");
    else printf("member = no\n");
    t=member("vwx",A);
    if(t==yes) printf("member = yes\n");
    else printf("member = no\n");
    delete("azd", A);
    delete("cccc", A);
    delete("cd", A);
    delete("abcdefg", A);
    for(j=0; j<B; j++) {
        printf("A[%d] = %p, ", j, A[j]);
        q=A[j];
        while(q != NULL) {
            printf("%s, next = %p, ", q->name, q->next);
            q=q->next;
        }
        printf("\n");
    } 
    return 0;
}

void insert(char *x, cell **A){
    cell *backet = A[h(x)];
    cell *prev = backet;
    cell *new = (cell *)malloc(sizeof(cell));
    if (backet == NULL){
        strncpy(new->name, x, W); new->name[W] = '\0'; 
        new -> next = NULL;
        A[h(x)] = new;
        return;   
    }
    while (backet != NULL){
        if (!strcmp(backet->name, x)){ //already x exist
            free(new);
            return; 
        }
        prev = backet;
        backet = backet->next;
    }
    //create new cell for x
    strncpy(new->name, x, W); new->name[W] = '\0'; 
    new -> next = NULL; 
    prev -> next = new;
}

void delete(char *x, cell **A){
    cell *backet = A[h(x)];
    cell *prev;
    int exist = 0;
    while (backet != NULL){
        if (!strcmp(backet->name, x)){
            exist++;
            break;
        }
        prev = backet;
        backet = backet -> next;
    }
    if (exist){
        prev -> next = backet -> next;
        free(backet);
    } 
}

enum yn member(char *x, cell **A){
    cell *backet = A[h(x)];
    while (backet != NULL){
        if (!strcmp(backet->name, x)) return yes;
        backet = backet->next;
    }
    return no;
}

int h(char *x){
    int sum=0;
    while (*x){
        sum += *x; 
        x++;
    }
    return sum % B;
}


