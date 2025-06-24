#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct cell{
    int node;
    struct cell *next;
} cell;

void preorder(int root, cell **S);

int main(void){
    struct cell *S[N], *p, *q;
    int n, j, parent, child, root;
    FILE *file;
    file=fopen("treedata", "r");
    //input the V number
    fscanf(file, "%d", &n);
    printf("n = %d\n", n);
    //initialize S
    for(j=0; j<n; j++) S[j]=NULL;
    fscanf(file, "%d", &parent);
    while(parent >= 0){
        fscanf(file, "%d", &child);
        if(child >= 0){
            p=(struct cell *)malloc(sizeof(struct cell));
            S[parent]=q=p;
        } 
        while(child >= 0){
            q->node=child;
            q->next=NULL;
            fscanf(file, "%d", &child);
            if(child >= 0){
                p=(struct cell *)malloc(sizeof(struct cell));
                q->next=p;
                q=p;
            }
        }
        fscanf(file, "%d", &parent);
    }
    for(j=0; j<n; j++) {
        printf("S[%d] = %p, ", j, S[j]);
        q=S[j];
        while(q != NULL) {
            printf("node = %d, next = %p, ", q->node, q->next);
            q=q->next;
        }
        printf("\n");
    }
    root=0;
    printf("preorder =");
    preorder(root, S);
    printf("\n");
    return(0);
}

void preorder(int root, cell **S){
    cell *q;
    printf("%d ", root);
    q = S[root];
    while (q != NULL){
        preorder(q->node, S);
        q = q -> next;
    }
}

