/* �O���n�b�V���@�̃v���O������ */

#include <stdio.h>    /* �W�����o�͂̃w�b�_�t�@�C���̓Ǎ��� */
#include <stdlib.h>   /* �W�����C�u�����̃w�b�_�t�@�C�� */
#include <string.h>   /* �����񃉃C�u�����̃w�b�_�t�@�C�� */
#define B 4          /* �o�P�b�g�� */
#define W 6           /* �꒷ */
enum yn {yes, no};    /* �񋓌^�f�[�^yn�̒�` */
struct cell           /* �\����cell�̒�` */
{
 char name[W+1];
 struct cell *next;
};
/* �֐��̐錾 */
void insert(char *x, struct cell **A);
void delete(char *x, struct cell **A);
enum yn member(char *x, struct cell **A);
int h(char *x);

int main()  
/* �O���n�b�V���@�̃e�X�g�v���O���� */
{
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
 for(j=0; j<B; j++) 
   {
    printf("A[%d] = %p, ", j, A[j]);
    q=A[j];
    while(q != NULL) 
      {
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
 for(j=0; j<B; j++) 
   {
    printf("A[%d] = %p, ", j, A[j]);
    q=A[j];
    while(q != NULL) 
      {
       printf("%s, next = %p, ", q->name, q->next);
       q=q->next;
      }
    printf("\n");
   }
 return(0);
}

void insert(char *x, struct cell **A)
/* �n�b�V���\A�֕�����x�̑}�� */
{
 int k;
 struct cell *p, *q, *r;

 k=h(x);                         /* x�̓���o�P�b�g�ԍ� */
 q=A[k];                         /* �o�P�b�gk���̒T�� */
 p=(struct cell *)malloc(sizeof(struct cell)); /* �V�����|�C���^�̊l�� */
 if(q==NULL) A[k]=p;
 else
   {
    while(q != NULL)             /* x�̑��݂̃`�F�b�N */
      {  
       if(strcmp(q->name, x)==0) /* x�͂��łɑ��� */
        {
         free(p); return; 
        } 
       else {r=q; q=q->next;}     
      }
    r->next=p;
   }
 strncpy(p->name, x, W);  
 p->name[W] = '\0';          /* x�̑}�� */
 p->next=NULL;
 return;
}

void delete(char *x, struct cell **A)
/* �n�b�V���\A���當����x�̏��� */
{
 int k;
 struct cell *q, *r;

 k=h(x);                         /* x�̃n�b�V���֐��l */
 q=A[k];                         /* �o�P�b�gk����x�̒T�� */
 r=NULL;
 while(q != NULL) 
   {
    if(strcmp(q->name, x)==0)    /* x�𔭌� */
      {
       if(r==NULL) A[k]=q->next; /* x�̏��� */
       else r->next=q->next;
       free(q); return;               /* ��ƏI�� */
      }
    r=q; q=q->next;
   }
 return;                         /* x�͑��݂��� */
}

enum yn member(char *x, struct cell **A)
/* �n�b�V���\A�ɕ�����x�̑��ݔ��� */
{
 struct cell *q, *r;

 q=A[h(x)];                      /* �o�P�b�gh(x)����x�̒T�� */
 while(q != NULL) 
   {
    if(strcmp(q->name, x) == 0) return(yes);     /* x�𔭌� */
    q=q->next;
   }
 return(no);                     /* x�͑��݂��� */
}

int h(char *x)
/* �n�b�V���֐��lh(x)�̌v�Z */
{
 int i, hash;

 hash=i=0;
 while(i<W && x[i]!=0)
  {hash=hash+(int)x[i]; i=i+1;}
 hash=hash%B;
 return(hash);
}

