#include <stdio.h>
#include <stdlib.h>

enum yn {yes, no};

typedef struct node {
    int element;
    struct node *left;
    struct node *right;
} node;

node *insert(int x, node *p);
enum yn member(int x, node *p);
void inorder(node *p);
void preorder(node *p);
int min(node *p);
node *delete(int x, node *p);
node *off(node *p);

int main(void){
    struct node *init;
    int i, x;
    enum yn a;
   
    init=NULL;
    for(i=0; i<10; i++) {
        init=insert((8-3*i)*(2-i/2), init);
        printf("insert : %d\n", (8-3*i)*(2-i/2));
    }
    init=insert(30, init);
    init=insert(25, init);
    init=insert(31, init);
    init=insert(37, init);
    printf("init = %p\n", init);
    printf("inorder\n");
    if(init != NULL) inorder(init);
    printf("preorder\n");
    if(init != NULL) preorder(init);
    x=31;
    a=member(x, init);
    if(a==yes) printf("Yes: x = %d\n", x);
    else printf("No: x = %d\n", x); 
    x=-2;
    a=member(x, init);
    if(a==yes) printf("Yes: x = %d\n", x);
    else printf("No: x = %d\n", x); 
    x=min(init);
    printf("min = %d\n", x);
    x=16;
    init=delete(x, init);
    printf("deleted x = %d\n", x);
    printf("init = %p\n", init);
    if(init != NULL) preorder(init);
    x=32;
    init=delete(x, init);
    printf("deleted x = %d\n", x);
    printf("init = %p\n", init);
    if(init != NULL) preorder(init);
    x=37;
    init=delete(x, init);
    printf("deleted x = %d\n", x);
    printf("init = %p\n", init);
    if(init != NULL) preorder(init);
    return 0;
}

enum yn member(int x, node *p){
    if (p == NULL) return no;
    if (x == p->element) return yes;
    else if (x > p->element) return member(x, p->right);
    else if (x < p->element) return member(x, p->left);
}

node *insert(int x, node *p){
    node *now, *prev;
    node *new = (node *)malloc(sizeof(node));
    if (p == NULL){ //deal with null pointer
        new -> element = x;
        new -> left = new -> right = NULL;
        return new;
    }
    now = prev = p;
    while (now != NULL){ // search x while now -> leaf
        if (x == now -> element) {free(new); return p;}
        else if (x > now -> element) {
            prev = now;
            now = now -> right;
        }
        else if (x < now -> element) {
            prev = now;
            now = now -> left;
        }
    }
    //create new node to x
    new -> element = x;
    new -> left = NULL; new ->right = NULL;
    if (x > prev->element) prev -> right = new;
    if (x < prev->element) prev -> left = new;
    return p;
}

node *delete(int x, node *p){
    node *now, *prev;
    int mode = -1; // note wheather x is left or right
    if (p == NULL) exit(1);

    now = prev = p;
    while (now != NULL){
        if (x == now -> element) break;
        else{
            prev = now;
            if (x > now->element) {now = now->right; mode = 0;}
            else {now = now->left; mode = 1;}
        }
    }
    if (mode == 0) prev -> right = off(now);
    else if (mode == 1) prev -> left = off(now);
    else p = off(p);
    return p;
}

int min(node *p){
    node *now = p;
    if (p == NULL) exit(1);
    while (now -> left != NULL){
        now = now -> left;
    }
    return now->element;
}

node *off(node *p){
    //remove p node and update subtree
    if (p->right == NULL) return NULL;
    if (p->right->left == NULL && p->right->left == NULL) {
        p->element = p->right->element;
        p->right = NULL;
        return p;
    }
    node *prev = p->right, *now = p->right;
    while (now -> left != NULL){
        prev = now;
        now = now -> left;
    }
    p -> element = now -> element;
    prev -> left = off(now); //update subtree by recursive
    return p;
}

void inorder(node *p){
    if (p == NULL) return;
    inorder(p->left); 
    printf("p = %p, element = %d, left = %p, right = %p\n", 
        p, p->element, p->left, p->right); 
    inorder(p->right);
}

void preorder(node *p){
    if (p == NULL) return;
    printf("p = %p, element = %d, left = %p, right = %p\n", 
        p, p->element, p->left, p->right); 
    preorder(p->left);
    preorder(p->right);
}




