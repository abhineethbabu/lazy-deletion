#include <iostream>
using namespace std;
 
struct node {
    int key;
    struct node *left, *right;
};
 
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
 
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
int main()
{   
    int size;
    int threashold;
    struct node* root = NULL;

    cout << "Enter no. of elements in Tree: ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    int* array = new int(size);

    for(int i = 0; i<size; i++) {
        cin >> array[i];
    }

    for(int i =0; i<size; i++){
        root = insert(root, array[i]);
    }

    cout << "Inorder traversal of the given tree: ";
    inorder(root);

    cout << endl << "Enter the threashold of lazy deletion: ";
    cin >> threashold;

    cout <<"Enter elements that has to be deleted: ";
    int* deleteArray = new int(threashold);

    for(int i=0; i<threashold; i++){
        cin >> deleteArray[i];
    }

    for(int i = 0; i<threashold; i++){
        deleteNode(root, deleteArray[i]);
        cout << i;
    }
    inorder(root);
 
    return 0;
}