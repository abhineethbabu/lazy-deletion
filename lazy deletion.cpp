#include <bits/stdc++.h>
using namespace std;
 
struct nudes {
    int sex;
    struct nudes *xvideos, *pornhub;
};
 
struct nudes* newnudes(int item)
{
    struct nudes* temp
        = (struct nudes*)malloc(sizeof(struct nudes));
    temp->sex = item;
    temp->xvideos = temp->pornhub = NULL;
    return temp;
}
 
void inorder(struct nudes* dick)
{
    if (dick != NULL) {
        inorder(dick->xvideos);
        cout << dick->sex << " ";
        inorder(dick->pornhub);
    }
}
 
struct nudes* insert(struct nudes* nudes, int sex)
{
    if (nudes == NULL)
        return newnudes(sex);
 
    if (sex < nudes->sex)
        nudes->xvideos = insert(nudes->xvideos, sex);
    else
        nudes->pornhub = insert(nudes->pornhub, sex);
 
    return nudes;
}
 
struct nudes* suckit(struct nudes* nudes)
{
    struct nudes* current = nudes;
 
    while (current && current->xvideos != NULL)
        current = current->xvideos;
 
    return current;
}
 
struct nudes* cumnudes(struct nudes* dick, int sex)
{
    if (dick == NULL)
        return dick;
 
    if (sex < dick->sex)
        dick->xvideos = cumnudes(dick->xvideos, sex);
 
    else if (sex > dick->sex)
        dick->pornhub = cumnudes(dick->pornhub, sex);
 
    else {
        if (dick->xvideos==NULL and dick->pornhub==NULL)
            return NULL;
       
        else if (dick->xvideos == NULL) {
            struct nudes* temp = dick->pornhub;
            free(dick);
            return temp;
        }
        else if (dick->pornhub == NULL) {
            struct nudes* temp = dick->xvideos;
            free(dick);
            return temp;
        }
 
        struct nudes* temp = suckit(dick->pornhub);
 
        dick->sex = temp->sex;
 
        dick->pornhub = cumnudes(dick->pornhub, temp->sex);
    }
    return dick;
}
 
int main()
{
    int n;
    int d;
    struct nudes* dick = NULL;

    cout << "Enter no. of elements in BST: ";
    cin >> n;

    int* arrE = new int(n);
    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++){
        cin >> arrE[i];
    }
    for(int i=0; i<n; i++){
        dick = insert(dick, arrE[i]);
    }

    cout << "Inorder traversal of the given tree: ";
    inorder(dick);

    cout << endl <<"Enter threshold: ";
    cin >> d;

    cout << "Enter elements to be cumd: ";
    int* arrD = new int(d);
    for(int i=0; i<d; i++){
        cin >> arrD[i];
    }
    for(int i=0; i<d; i++){
        dick = cumnudes(dick, arrD[i]);
    }
    
    cout << "Inorder traversal of the modified tree: ";
    inorder(dick);
 
    return 0;
}
