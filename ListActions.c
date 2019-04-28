#include <stdio.h>
#include <stdlib.h>

// FELIPE REZENDE

typedef struct node
{
   int value;
   struct node *next;
} tNode;

typedef struct List
{
   tNode *init;
   int numberElement;

} tList;

tNode *createNode(int value) {
   tNode *_node;
   _node = malloc(sizeof(tNode));

   _node->value = value;
   _node->next = NULL;

   return _node;
}

tList *createList() {
   tList *_list;
   _list = malloc(sizeof(tList));

   _list->init = NULL;
   _list->numberElement = 0;

   return _list;
}

void showList(tList *list) {
   tNode *node_current = list->init;
   
   while(node_current != NULL){
      printf("Value: %i \n", node_current->value);
      node_current = node_current->next;
   }
}

int searchListItem(tList *list, int searchValue) {
   tNode *node_current = list->init;
   
   while(node_current->next != NULL || node_current->value == searchValue){
      node_current = node_current->next;
   }

   if (node_current->value == searchValue) return 1;
   return 0;
}

int deleteListItem(tList *list, int searchValue) {
   if (list == NULL || list->init == NULL) return 0;
   
   tNode *node_current = list->init, *node_last;
   
   while(node_current->next != NULL && node_current->value != searchValue){
      node_last = node_current; // Guardamos o valor atual para poder apagar em seguida
      node_current = node_current->next;
   }

   if (node_current->value == searchValue) {
      node_last->next = node_current->next;
      printf("[DELETE] %d \n", searchValue);
      free(node_current);
      return 1;
   }
   
   return 0;
}

int addNode(tList *list, int value) {
   if (list == NULL) return 0;
   
   tNode *node_current = list->init;

   if (node_current == NULL) {
      list->init = node_current = createNode(value);
      list->numberElement++;
      return 1;
   }
   
   while(node_current->next != NULL && node_current != node_current->next){
      node_current = node_current->next;
   }

   node_current->next = createNode(value);
   printf("[CREATE] %d \n", node_current->next->value);
   list->numberElement++;
   
   return 1;
}

int main()
{
   tList *list = createList();
   int i, count = 6;
   for(i = 0; i < count; i++)
   {
      int alloced = addNode(list, i);
   }
   deleteListItem(list, 3);
   printf("[ALOCAÇÃO]\n");
   addNode(list, 8);
   showList(list);

   free(list);
   
   return 0;
}

