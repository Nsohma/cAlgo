/* �q�[�v�\�[�g�̃v���O������ */

#include <stdio.h>
#include <stdlib.h>
#define N 500        /* The max size of array A. */
void heapsortt(int *A, int n);
void heapify(int *A, int n);
void downmax(int i, int *A, int n);
int deletemax(int *A, int n);
void swap(int i, int j, int *A);

main()
/* �q�[�v�\�[�g�̃e�X�g�v���O���� */
{
 int A[N];
 int n, i;
 FILE *file;

 file=fopen("sortdata", "r");   /* �f�[�^�̓Ǎ��� */
 fscanf(file, "%d", &n);
 if(n>N) 
   {
    printf("Illegal array size n = %d for N = %d\n", n, N); 
    exit(1);
   }
 printf("n = %d\nA = ", n);
 for(i=0; i<n; i++) fscanf(file, "%d", &A[i]);
 for(i=0; i<n; i++) printf("%d ", A[i]);
 printf("\nA = ");
 heapsortt(A, n);                /* �q�[�v�\�[�g�ɂ��z��A�̐��� */
 for(i=0; i<n; i++) printf("%d ",A[i]);
 printf("\n");
 return(0);
}

void heapsortt(int *A, int n)
/* �z��A[0],...,A[n-1]���q�[�v�\�[�g�ɂ�萮�� */
{
 int i;

 heapify(A, n);         /* �q�[�v��; ���������͍ő�v�f������ */
 for(i=n-1; i>0; i--) A[i]=deletemax(A, i+1);  /* �ő�v�f�𖖔��� */
}

void heapify(int *A, int n)
/* A[0],...,A[n-1]���q�[�v�� */
{
 int i;
 for(i=n/2-1; i>=0; i--) downmax(i, A, n);
}

void downmax(int i, int *A, int n)
/* A[i]���牺���ցA�q�[�v�̐������񕜂��邽�߂�swap�����K�p */
{
 int j;

 j=2*i+1;               /* i�̍��̎q */ 
 if(j>=n) return;
 if(j+1<n && A[j]<A[j+1]) j=j+1;   /* j: i�̎q�ő傫�Ȓl������ */
 if(A[j]>A[i])          /* i��j�̌��� */
   {
    swap(i, j, A);
    downmax(j, A, n);   /* j�̉����֍ċA�I���s */
   }
 return;
}

int deletemax(int *A, int n)
/* �q�[�vA[0],...,A[n-1]����ő�v�fA[0]�̏o�͂Ə��� */
{
 int max;

 max=A[0]; A[0]=A[n-1]; /* A[0]�̏o�͂�A[n-1]�̈ړ� */
 downmax(0, A, n-1);    /* �q�[�v�����̉񕜂̂��߉��� */
 return(max);
}

void swap(int i, int j, int *A)
/* Swap A[i] and A[j]. */
{
 int temp;
 temp=A[i]; A[i]=A[j]; A[j]=temp;
 return;
}
