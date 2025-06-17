/* ２分探索木に対するinorderのプログラム例 */

#include <stdio.h>
#include <stdlib.h>
struct node                /* 構造体nodeの宣言 */
{
 int element;
 struct node *left;
 struct node *right;
};
/* 関数の宣言 */
struct node *insert(int x, struct node *init);
void inorder(struct node *p);

main()
/* ２分探索木のinorder処理のテストプログラム */
{
 struct node *init;
 int i, x;

 init=NULL;            /* 2分探索木の作成 */
 for(i=0; i<10; i++) init=insert((8-3*i)*(2-i/2), init);
 init=insert(30, init);
 init=insert(25, init);
 init=insert(31, init);
 init=insert(37, init);
 printf("init = %p\n", init);
 printf("inorder\n");  /* inorder の実行 */
 if(init != NULL) inorder(init);
 else printf("tree is NULL\n");
 return(0);
}


struct node *insert(int x, struct node *init)
/* initが指す２分探索木にxを挿入し、initを更新 */
{
 struct node *p, *q, *r;

 p=(struct node *)malloc(sizeof(struct node)); /* 新しいポインタ */
 q=init;                   /* 根initから探索開始 */
 if(init==NULL) init=p;
 while(q!=NULL)
   {
    if(q->element == x) {free(p); return(init);}  /* xはすでに存在 */
    r = q;
    if(q->element < x)     /* 右の子へ */
      {
       q = q->right;
       if(q==NULL) r->right = p;
      }
    else                   /* 左の子へ */
      {
       q = q->left;
       if(q==NULL) r->left = p;
      }
   }
 p->element = x;           /* xを挿入 */
 p->left = p->right = NULL;
 return(init);
}


void inorder(struct node *p) 
/* Print all descendants of node *p in inorder. */
{
 if(p->left != NULL) inorder(p->left);      /* 左の子孫のなぞり */
 printf("p = %p, element = %d, left = %p, right = %p\n", 
         p, p->element, p->left, p->right); /* pが指す節点の出力 */
 if(p->right != NULL) inorder(p->right);    /* 右の子孫のなぞり */
 return;  
}
