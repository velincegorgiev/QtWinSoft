// 3.Напиши програм кој врши бришење од дрво, така да структурата на дрвото не се губи. 
// Секоја од користените функции да се објасни. (помош: користете web решенија за binary tree delete)

#include <stdio.h>
#include <stdlib.h>

struct treeNode { 
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr; 
}; 

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
TreeNodePtr deleteNode(TreeNodePtr treePtr, int value);
TreeNodePtr findMin(TreeNodePtr treePtr);

int main()
{ 
   int i;
   int item;
   TreeNodePtr rootPtr = NULL;

   insertNode(&rootPtr, 50);
   insertNode(&rootPtr, 30);
   insertNode(&rootPtr, 70);
   insertNode(&rootPtr, 20);
   insertNode(&rootPtr, 40);
   insertNode(&rootPtr, 60);
   insertNode(&rootPtr, 80);

   printf("inorderno pominuvanje pred brisenjeto:\n");
   inOrder(rootPtr);

   printf("\nbrisenje na elementot 30:\n");
   rootPtr = deleteNode(rootPtr, 30);
   inOrder(rootPtr);

   printf("\nbrisenje na elementot 50:\n");
   rootPtr = deleteNode(rootPtr, 50);
   inOrder(rootPtr);

   return 0;
}

void insertNode(TreeNodePtr *treePtr, int value)
{ 
   if (*treePtr == NULL) {   
      *treePtr = malloc(sizeof(TreeNode));
      if (*treePtr != NULL) {
         (*treePtr)->data = value;
         (*treePtr)->leftPtr = NULL;
         (*treePtr)->rightPtr = NULL;
      }
      else {
         printf("ne moze da se dodeli memorija.\n");
      }
   }
   else {
      if (value < (*treePtr)->data)
         insertNode(&((*treePtr)->leftPtr), value);
      else if (value > (*treePtr)->data)
         insertNode(&((*treePtr)->rightPtr), value);
   }
}

void inOrder(TreeNodePtr treePtr)
{ 
   if (treePtr != NULL) {
      inOrder(treePtr->leftPtr);
      printf("%d ", treePtr->data);
      inOrder(treePtr->rightPtr);
   }
}

TreeNodePtr findMin(TreeNodePtr treePtr)
{
   while (treePtr && treePtr->leftPtr != NULL)
      treePtr = treePtr->leftPtr;
   return treePtr;
}

TreeNodePtr deleteNode(TreeNodePtr treePtr, int value)
{
   if (treePtr == NULL) {
      printf("jazolot ne e pronajden.\n");
      return treePtr;
   }

   if (value < treePtr->data) {
      treePtr->leftPtr = deleteNode(treePtr->leftPtr, value);
   }
   else if (value > treePtr->data) {
      treePtr->rightPtr = deleteNode(treePtr->rightPtr, value);
   }
   else {
      if (treePtr->leftPtr == NULL) {
         TreeNodePtr temp = treePtr->rightPtr;
         free(treePtr);
         return temp;
      }
      else if (treePtr->rightPtr == NULL) {
         TreeNodePtr temp = treePtr->leftPtr;
         free(treePtr);
         return temp;
      }
      else {
         TreeNodePtr temp = findMin(treePtr->rightPtr);
         treePtr->data = temp->data;
         treePtr->rightPtr = deleteNode(treePtr->rightPtr, temp->data);
      }
   }
   return treePtr;
}

