#include <stdio.h>
#define MAX 100

// B-Tree Node Structure
struct node {
    int value[MAX];
    struct node *keys[MAX+1];
    struct node *parent;
    int keyCount;
} *tRoot = NULL;

// Globals
int treeOrder;

// Menu functions
void showMenu();
void doInsert();
void doDelete();
void doSearch();
void doInOrder();

// Tree Operations
struct node* newNode(int value,struct node *parent);
struct node* insertN(int value,struct node *root,struct node *parent);


int main(){
    // Initialize
    printf("--- Initialization ---\n");
    printf("B-Tree Order: ");
    scanf("%d",&treeOrder);
    
    // Run menu
    showMenu();
    
    getch();
    return 0;
}

// Menus
void showMenu(){
   system("cls"); 
   printf("      _____           _____              \n");
   printf("     | __  |   ___   |_   _|___ ___ ___  \n");
   printf("     | __ -|  |___|    | | |  _| -_| -_| \n");
   printf("     |_____|           |_| |_| |___|___| \n");
   
   printf("\n\n");
   printf("(1) Insert a Node\n");
   printf("(2) Delete a Node\n");
   printf("(3) Search a Node\n");
   printf("(4) Print In Order\n");
   printf("(5) Exit\n");
    
  switch(getch()){
     case '1' : doInsert();   break;
     case '2' : doDelete();   break;
     case '3' : doSearch();   break;
     case '4' : doInOrder();   break;
     default  : exit(0);
  }                            
}

void doInsert(){
     int value;
     
     system("cls"); 
     printf("--- Insertion ---\n");
     printf("Value: ");
     scanf("%d",&value);
     
     tRoot = insertN(value,tRoot,tRoot);
     
     printf("\n\n\nPress any key to continue...\n");
     getch();
     showMenu();
}

void doDelete(){
     system("cls"); 
     printf("--- Deletion ---\n");
     
     printf("\n\n\nPress any key to continue...\n");
     getch();
     showMenu();
}

void doSearch(){
     system("cls"); 
     printf("--- Search ---\n");
     
     printf("\n\n\nPress any key to continue...\n");
     getch();
     showMenu();
}

void doInOrder(){
     int i;
     
     system("cls"); 
     printf("--- Printing ---\n");
     
     for (i = 0; i < tRoot->keyCount - 1; i++) printf("%d ", tRoot->value[i]);
     
     printf("\n\n\nPress any key to continue...\n");
     getch();
     showMenu();
}

// Operations
struct node* newNode(int value,struct node *parent){
       struct node *root = (struct node*)malloc(sizeof(struct node));
       root->value[0] = value;
       root->keyCount = 2;
       root->parent = parent;
       
       int i;
       for (i = 1; i < MAX; i++) root->value[i] = (int)NULL;
       
       return root;
}

struct node* insertN(int value,struct node *root,struct node *parent){
       int i = 0, j;
       
       if (root == NULL){ // If the tree doesn't have a value yet
          return newNode(value,parent);
       } else { 
          while(1){
             if ( (void*)root->value[i] != NULL ){ // If there is a value in the current box
                if (value == root->value[i]){ // If the value is already inserted
                   printf("Data Already inserted!\n");
                   break;
                } else if ( value >= root->value[i] ){ // if value to be inserted is greater, then proceed to next box
                   i++;
                   continue;
                } else { // This is if the value to be inserted is lesser which means, we can put it now
                   for (j = treeOrder - 2; j >= i; j--) root->value[j+1] = root->value[j]; // move everything to the right
                   root->value[i] = value;
                   root->keyCount++;
                   
                   printf("Keys: %d\n",root->keyCount);
                   break;
                }
             } else { // else if the box is null. Insert directly
               root->value[i] = value;
               root->keyCount++;
               
               printf("Keys: %d\n",root->keyCount);
               break;
             }   
             
             i++;       
          } 
       }
       
       return root;
}

