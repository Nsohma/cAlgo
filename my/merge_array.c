#include <stdio.h>
#include <stdlib.h>

#define N 7
#define M 4

typedef struct {
    int size[M];
    int first[M];
} set;

typedef struct {
    int set[N];
    int next[N];
} element;

void setmerge(int i, int k, set *S, element *E);

int main(void){
    set S; element E;
    int i, j;
    FILE *file;
    for(i=0; i<M; i++) {S.size[i]=0; S.first[i]=-1;}
    for(j=0; j<N; j++) {E.set[j]=-1; E.next[j]=-1;}
    file=fopen("mergedata", "r");
    fscanf(file, "%d", &i);
    while(i>=0) {
        fscanf(file, "%d", &S.size[i]);
        fscanf(file, "%d", &S.first[i]);
        fscanf(file, "%d", &i);
    }
    fscanf(file, "%d", &j);
    while(j>=0) {
        fscanf(file, "%d", &E.set[j]);
        fscanf(file, "%d", &E.next[j]);
        fscanf(file, "%d", &j);
    }
    printf("initial S\n");
    for(i=0; i<M; i++) printf("%d, %d, %d\n", i, S.size[i], S.first[i]);
    printf("initial E\n");
    for(j=0; j<N; j++) printf("%d, %d, %d\n", j, E.set[j], E.next[j]);
    setmerge(0, 3, &S, &E);
    setmerge(0, 1, &S, &E);
    printf("updated S\n");
    for(i=0; i<M; i++) printf("%d, %d, %d\n", i, S.size[i], S.first[i]);
    printf("updated E\n");
    for(j=0; j<N; j++) printf("%d, %d, %d\n", j, E.set[j], E.next[j]);
    return 0;
}

void setmerge(int i, int k, set *S, element *E){
    //merge S[i] and S[k]
    int sm, bg, nx;
    if (S->size[i] > S->size[k]){ // normalization
        bg = i;
        sm = k;
    } else{
        bg = i;
        sm = k;
    }// bg = big S, sm = small S
    
    // new set = S[bg] and S[sm] will be deleted
    nx = S->first[sm];
    while (E->next[nx] != -1){ 
        //search S[sm] last index and convert S[sm] to S[bg]
        E->set[nx] = bg;
        nx = E->next[nx];
    }
    E->next[nx] = S->first[bg];
    E->set[nx] = bg;
    S->first[bg] = S->first[sm];
    S->first[sm] = -1;
    S->size[bg] = S->size[bg] + S->size[sm];
    S->size[sm] = 0;
    return;
}
