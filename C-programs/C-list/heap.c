/* �q�[�v�ɂ�����DELETEMIN��INSERT�̃v���O������ */

#include <stdio.h>
#include <stdlib.h>
#define N 500                 /* �z��A�̍ő�T�C�Y */
/* �֐��̐錾 */
void insert(int x, int *A, int *n);
int deletemin(int *A, int *n);
void upmin(int i, int *A, int n);
void downmin(int i, int *A, int n);
void swap(int i, int j, int *A);

main()
/* �q�[�vA[0],...,A[n-1]�ɑ΂���e�X�g�v���O���� */
{
 int A[N];
 int n, i, k, min;

 n=0;
 for(k=0; k<10; k++) 
   {
    insert(100-(5-i)*(5-i), A, &n);
    printf("n = %d\nA = ", n);
    for(i=0; i<n; i++) printf("%d ",A[i]);
    printf("\n");
   }
 for(k=0; k<10; k++) 
   {
    min=deletemin(A, &n);
    printf("n = %d, min = %d\nA = ", n, min);
    for(i=0; i<n; i++) printf("%d ",A[i]);
    printf("\n");
   }
 return(0);
}

void insert(int x, int *A, int *n)
/* �q�[�vA[0],...,A[n-1]�֐V�����v�fx�̑}��; n=n+1 */
{
 int n1;

 n1=*n;                          /* n�̒l�����u�� */
 if(n1>=N) {printf("Error: Heap A is full.\n"); exit(1);}
                                 /* ���`�F�b�N: A�͖��t */
 A[n1]=x;                        /* �����ւ���u�� */
 upmin(n1, A, n1+1);             /* ��ւ̏C�� */
 *n=n1+1;                        /* n�̍X�V */
 return;
}

int deletemin(int *A, int *n)
/* �q�[�vA[0],...,A[n-1]����ŏ��v�fA[0]�̏o�͂Ə���; n=n-1 */
{
 int min, n1;

 n1=*n;                           /* n�̒l�����u�� */
 if(n1<1) {printf("Error: Heap is empty.\n"); exit(1);} /* ��: A�͋� */
 min=A[0]; A[0]=A[n1-1];          /* A[0]�̏o�͂�A[n-1]�̈ړ� */
 if(n1>1) downmin(0, A, n1-1);    /* �q�[�v�����̉񕜂̂��߉��� */
 *n=n1-1;                         /* n�̍X�V */
 return(min);
}

void upmin(int i, int *A, int n)
/* A[i]�������ցA�q�[�v�����񕜂̂���swap�����K�p */
{
 int j;

 if(i<0 || i>=n)                 /* ���`�F�b�N */
   {printf("Illegal element i=%d for n=%d\n", i, n); exit(1);}
 if(i==0) return;                /* ���֓��B����ΏI�� */
 j=(i-1)/2;                      /* i�̐e */
 if(A[j]>A[i])                   /* i��j�̌��� */
   {
    swap(i, j, A); 
    upmin(j, A, n);              /* j�̏���֍ċA�I���s */
   }
 return;
}

void downmin(int i, int *A, int n)
/* A[i]���牺���ցA�q�[�v�����񕜂̂��߂�swap�����K�p */
{
 int j;

 if(i<0 || i>=n)                 /* ���`�F�b�N */
   { printf("Illegal element i=%d for n=%d\n", i, n); exit(1);}
 j=2*i+1;                        /* i�̍��̎q */
 if(j>=n) return;
 if(j+1<n && A[j]>A[j+1]) j=j+1; /* j: i�̎q�ŏ����Ȓl������ */
 if(A[j]<A[i])                   /* i��j�̌��� */
   {
    swap(i, j, A);
    downmin(j, A, n);            /* j�̉����֍ċA�I���s */
   }
 return;
}

void swap(int i, int j, int *A)
/* A[i]��A[j]�̌��� */
{
 int temp;
 temp=A[i]; A[i]=A[j]; A[j]=temp;
 return;
}

