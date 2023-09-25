 33 #include <stdio.h>
 32 #include <string.h>
 31 #include <stdlib.h>
 30
 29 typedef struct {
 28     int data;
 27     struct node *next;
 26 }node;
 25
 24 node *head = NULL;
 23 node *current = NULL;
 22 void insert(int data) {
 21     node *link = malloc(sizeof(node));
 20     link->data = data;
 19     link->next = head;
 18     head = link;
 17 }
 16 void printList(void){
 15     printf("\nprinting list: ");
 14     node *lp = head;
 13     while(lp != NULL){
 12         printf("%d->", lp->data);
 11         lp = lp->next;
 10     }
  9     printf("\n");
  8 }
  7 void delete(int data) {
  6     node *p = head;
  5     node **temp = &head;
  4     while(p != NULL) {
  3         printf("[%d]->%d\n",p->data, (*temp)->data);
  2         if((*temp)->data == data) {
  1             printf("data found: %d\n", (*temp)->data);
  0             p->next = (*temp)->ne
