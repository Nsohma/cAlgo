/* �Q���T���؂ɑ΂���MEMBER, INSERT, MIN, DELETE�̃v���O������
�i�P���ȃA���S���Y���j */

#include <stdio.h>
#include <stdlib.h>
enum yn {yes, no};         /* �񋓌^�f�[�^yn�̒�` */
enum LR {LEFT, RIGHT};
struct node                /* �\����node�̐錾 */
{
 int element;
 struct node *left;
 struct node *right;
};
/* �֐��̐錾 */
enum yn member(int x, struct node *init);
struct node *insert(int x, struct node *init);
int min(struct node *init);
struct node *delete(int x, struct node *init);
struct node *off(struct node *p);
void printpre(struct node *p);
void inorder(struct node *p);

int main()
/* �Q���T���؂̏����̃e�X�g�v���O���� */
{
 struct node *init;
 int i, x;
 enum yn a;

 init=NULL;
 for(i=0; i<10; i++) init=insert((8-3*i)*(2-i/2), init);
 init=insert(30, init);
 init=insert(25, init);
 init=insert(31, init);
 init=insert(37, init);
 printf("init = %p\n", init);
 printf("inorder\n");
 if(init != NULL) inorder(init);
 printf("preorder\n");
 if(init != NULL) printpre(init);
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
 if(init != NULL) printpre(init);
 x=32;
 init=delete(x, init);
 printf("deleted x = %d\n", x);
 printf("init = %p\n", init);
 if(init != NULL) printpre(init);
 x=37;
 init=delete(x, init);
 printf("deleted x = %d\n", x);
 printf("init = %p\n", init);
 if(init != NULL) printpre(init);
 return(0);
}

enum yn member(int x, struct node *init)
/* init���w���Q���T���؂�x�̑��݂𔻒� */
{
 struct node *q;

 q=init;                   /* ��init����T���J�n */
 while(q!=NULL)
   {
    if(q->element == x) return(yes);    /* x�𔭌� */
    if(q->element < x)  q = q->right;
    else q = q->left;
   }
 return(no);               /* x���݂��� */
}

struct node *insert(int x, struct node *init)
/* init���w���Q���T���؂�x��}�����Ainit���X�V */
{
 struct node *p, *q, *r;

 p=(struct node *)malloc(sizeof(struct node)); /* �V�����|�C���^ */
 q=init;                   /* ��init����T���J�n */
 if(init==NULL) init=p;
 while(q!=NULL)
   {
    if(q->element == x) {free(p); return(init);}  /* x�͂��łɑ��� */
    r = q;
    if(q->element < x)     /* �E�̎q�� */
      {
       q = q->right;
       if(q==NULL) r->right = p;
      }
    else                   /* ���̎q�� */
      {
       q = q->left;
       if(q==NULL) r->left = p;
      }
   }
 p->element = x;           /* x��}�� */
 p->left = p->right = NULL;
 return(init);
}

int min(struct node *init)
/* init���w���Q���T���؂̍ŏ��v�f���o�� */
{
 struct node *q, *r;

 q=init;                   /* �����獶�[�̘H�������� */
 if(q==NULL) {printf("Error: Tree is empty.\n"); exit(1);} /* �؂͋� */
 while(q!=NULL) 
   {
    r = q; q = q->left;
   }
 return(r->element);       /* ���ʂ�Ԃ� */
}

struct node *delete(int x, struct node *init)
/* init���w���Q���T���؂���v�fx���������Ainit�̍X�V */
{
 struct node *q, *r, *p;   /* q�͒T�����̃|�C���^�Ar�͂��̐e */
 int side;                 /* side==1: r�̉E�̎q��q�A0: ���̎q��q */

 q=init;                   /* ������T���̊J�n */
 while(q!=NULL)
   {
    if(q->element == x)    /* x�̔��� */
      {
       p=off(q);           /* x�̃Z��q���������Aq�̕����؂��X�V */
       if(p==NULL)         /* �����؂͋� */
         {
          if(q==init) init=NULL;  /* q����init�ł���ꍇ */
          else             /* ���̑��̏ꍇ */
            {
             if(side==1) r->right = NULL;
             else r->left = NULL;
            }
         }
       return(init);       /* �I�� */
      }
    r=q;                   /* �T���𑱂��� */
    if(r->element < x) {q = r->right; side=1;}
    else {q = r->left; side=0;}  
   }
 return(init);
}

struct node *off(struct node *p)
/* �|�C���^p���w���ߓ_�������Ap�̕����؂��X�V */
{
 struct node *q, *r, *s;  /* q�͒T�����̃|�C���^�Ar�͂��̐e�As��r�̐e */
 int side;

 if(p->left==NULL && p->right==NULL) return(NULL);  /* p�̎q�͋��ɋ� */
 if(p->left==NULL || p->right==NULL)  /* p�̎q�̈������ */
   {
    if(p->left == NULL) q=p->right;   /* ��łȂ�����p�֏グ�� */
    else q=p->left;   
    p->element = q->element;
    p->left = q->left;
    p->right = q->right;
    return(p);
   }
 s=p; side=1;              /* p�̎q�͋��ɑ��� */
 r = s->right;             /* p�̉E�̕����؂̍ŏ��v�f��T�� */
 q = r->left;
 while(q!=NULL) 
   {
    s=r; side=0;
    r = q; q = r->left;
   }
 p->element = r->element;
 r=off(r);                 /* �ŏ��v�fr�̏����G�ċA�I���s */
 if(r==NULL)               /* r����̏ꍇ */
   {
    if(side==1) s->right = NULL;
    else s->left = NULL;
   }
 return(p);
}


void printpre(struct node *p) 
/* Print all children of node *p in preorder. */
{
 printf("p = %p, element = %d, left = %p, right = %p\n", 
         p, p->element, p->left, p->right);
 if(p->left != NULL) printpre(p->left);
 if(p->right != NULL) printpre(p->right);
 return;  
}

void inorder(struct node *p) 
/* Print all children of node *p in inorder. */
{
  if (p == NULL) return;
 inorder(p->left);     
 printf("p = %p, element = %d, left = %p, right = %p\n", 
         p, p->element, p->left, p->right);
 inorder(p->right);   
 return;  
}
