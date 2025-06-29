#include <stdio.h>
#include <stdlib.h>

#define N 7 // number of element
#define M 4 // number of set

typedef struct {
    int size[M];
    int root[M];
    int parent[N];
} sets;

void treemerge(int i, int k, sets *S);
int treefind(int j, sets *S);

int main(void){
    sets S;
    int i, j, k;
    FILE *file;
    file=fopen("mtreedata", "r");
    for(i=0; i<M; i++){
        fscanf(file, "%d", &S.size[i]);
        fscanf(file, "%d", &S.root[i]);
    }
    for(j=0; j<N; j++) fscanf(file, "%d", &S.parent[j]);
    printf("initial S\n");
    for(i=0; i<M; i++) printf("%d, %d, %d\n", i, S.size[i], S.root[i]);
    printf("initial parents\n");
    for(j=0; j<N; j++) printf("%d, %d\n", j,S.parent[j]);
    treemerge(1, 3, &S);
    printf("updated S\n");
    for(i=0; i<M; i++) printf("%d, %d, %d\n", i, S.size[i], S.root[i]);
    printf("updated parents\n");
    for(j=0; j<N; j++) printf("%d, %d\n", j, S.parent[j]);
    j=4;
    k=treefind(j, &S);
    printf("element = %d, set = %d\n", j, k);
    printf("updated S\n");
    for(i=0; i<M; i++) printf("%d, %d, %d\n", i, S.size[i], S.root[i]);
    printf("updated parents\n");
    for(j=0; j<N; j++) printf("%d, %d\n", j, S.parent[j]);
    return 0;
}

void treemerge(int i, int k, sets *S){
    int sm, bg;
    //normalization
    if (S->size[i] > S->size[k]){bg = i; sm = k;}
    else {bg = k; sm = i;}
    S->parent[S->root[sm]] = S->root[bg];//connect tree
    S->size[bg] = S->size[sm] + S->size[bg];
    S->size[sm] = 0;
    S->root[sm] = -1;
    return;
}

int treefind(int j, sets *S){
    int nx = S->parent[j];
    int prev = j;
    int rt;
    while (nx > -1){
        prev = nx;
        nx = S->parent[nx];
    }
    rt = prev; //get root
    //initialize nx and prev
    nx = S->parent[j];
    prev = j;
    //path compression
    while (nx != rt){
        S->parent[prev] = rt;
        prev = nx;
        nx = S->parent[prev];
    }
    for (int i=0; i<M; i++){
        if (S->root[i] == rt) return i;
    }
    return 0;
}

