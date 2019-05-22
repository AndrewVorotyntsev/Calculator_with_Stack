/*
 ============================================================================
 Name        : Stack.c
 Author      : AndrewVorotyntsev
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102


float factorial(float n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


typedef float T;
typedef struct Node_tag {
    T value;
    struct Node_tag *next;
} Node_t;


void push(Node_t **head, T value) {
    Node_t *tmp = malloc(sizeof(Node_t));
if (tmp == NULL) {
        exit(STACK_OVERFLOW);
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


T pop(Node_t **head) {
    Node_t *out;
    T value;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
}


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *write , *result ;
    write = fopen("Data.txt", "r");
    result = fopen("Result.txt" , "w");
    Node_t *head = NULL;
    char s;
    float a, b, k, n, e, f;
    fscanf(write ,"%f %f %c" , &a,&b,&s);
    push(&head, a);
    push(&head, b);
    if (s=='+')
        k = 0;
    if (s=='-')
        k = 1;
    if (s=='*')
        k = 2;
    if (s=='/')
        k = 3;
    if (s=='^')
        k = 4;
    if (s=='!')
        k = 5;
    push(&head, k);
    fclose(write);
    n = pop(&head);
    if (n==0){
        e = pop(&head);
        f = pop(&head);
        fprintf(result,"Answer=%f", f+e);
    }
    if (n==1){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f-e);
        }
    if (n==2){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f*e);
        }
    if (n==3){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f/e);
        }
    if (n==4){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", pow(f,e));
        }
    if (n==5){
                e = pop(&head);
                f = pop(&head);
                fprintf(result,"Answer=%f", factorial(e));
            }
}
