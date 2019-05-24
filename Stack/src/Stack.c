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


float factorial(float n)
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


typedef struct Node_tag {
    float value;
    struct Node_tag *next;
} Node_t;


void push(Node_t **head, float value) {
    Node_t *tmp = malloc(sizeof(Node_t));
if (tmp == NULL) {
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


float pop(Node_t **head) {
    Node_t *out;
    float value;
    if (*head == NULL) {
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
    float a,b, e, f;
    fscanf(write,"%f %f %c" , &a ,&b ,&s);
    push(&head, a);
    push(&head, b);
    if (s=='+')
    {
        e = pop(&head);
        f = pop(&head);
        fprintf(result,"Answer=%f", f+e);
    }
    if (s=='-'){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f-e);
        }
    if (s=='*'){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f*e);
        }
    if (s=='/'){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", f/e);
        }
    if (s=='^'){
            e = pop(&head);
            f = pop(&head);
            fprintf(result,"Answer=%f", pow(f,e));
        }
    if (s=='!'){
                e = pop(&head);
                f = pop(&head);
                fprintf(result,"Answer=%f", factorial(e));
            }
}
