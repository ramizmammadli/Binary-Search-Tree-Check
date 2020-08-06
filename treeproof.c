#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n* left;
    struct n* right;
};

typedef struct n node;

node* newNode(int a){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->x = a;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}

int isBST(node* node)  
{  
	if (node == NULL)  
    	return 1;  
      
  /* false if left is > than node */
  	if (node->left != NULL && node->left->x > node->x)  
    	return 0;  
      
  /* false if right is < than node */
  	if (node->right != NULL && node->right->x < node->x)  
    	return 0;  
    
  /* false if, recursively, the left or right is not a BST */
  	if (!isBST(node->left) || !isBST(node->right))  
    	return 0;  
      
  /* passing all that, it's a BST */
	return 1;  
} 

node* sortedArrayToBST(int arr[], int start, int end) 
{ 
    /* Base Case */
    if (start > end) 
      return NULL; 
	
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
     node *root = newNode(arr[mid]); 
  
    /* Recursively construct the left subtree and make it 
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1); 
  
    /* Recursively construct the right subtree and make it 
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end); 
  
    return root; 
} 

int main(void){
    int size, i, l, h, array[100];
    printf("\n----Whether Binary Search Tree or not----\n\n");
	printf("Enter the number of values entered: ");
    scanf("%d", &size);

	for (i=0; i<size; i++){
		printf("%d: ", (i+1));
		scanf("%d", &array[i]);
	}

    l = 0; 
    h = size-1;

    node* head = sortedArrayToBST(array, l, h);

    if (isBST(head) == 0){
        printf("This is not a Binary Search Tree");
    }
    else{
        printf("This is a Binary Search Tree");
    }

    return 0;
}