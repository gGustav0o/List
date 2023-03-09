//------------------------INCLUDE------------------------//
#include <iostream>
//------------------------DEFINE------------------------//
#define MEMORY_ERROR 2
#define path R"(C:\Users\Kurai\Desktop\0\Proga\s.txt)"
//------------------------STRUCT------------------------//
struct tree{
    int key;
    int quantity; //the number of elements in the left subtree
    tree* left;
    tree* right;
};
//-------------------ERROR--FUNCTIONS-------------------//
void memoryError(){
    std::cerr<<"Memory error\n";
    exit(MEMORY_ERROR);
}
//------------------------------------------------------//
tree* create(int key){
    tree* element = (tree*)malloc(sizeof(tree));
    if (!element) memoryError();
    element->key = key;
    element->left = nullptr;
    element->right = nullptr;
    element->quantity = 1;
    return element;
}
//--------------------------MAP--------------------------//
void add(tree* root, int key){
    tree* element = create(key);
    while (root){
        if (root->key == key){
            std::cerr<<"This element already exists";
            return;
        }
        if (key < root->key && !root->left){
            root->quantity++;
            root->left = element;
            return;
        }
        if (key > root->key && !root->right){
            root->right = element;
            return;
        }
        if (key < root->key){
            root->quantity++;
            root = root->left;
        } else{
            root= root->right;
        }
    }
}
// if element with this key does not exist returns null
tree* find(tree* root, int key){
    while (root && (root->key != key)){
        if (key < root->key) root = root->left;
        else root = root->right;
    }
    return root;
}
void remove(tree* root, int key){
    tree* temp;
    /* if the current element is on the left of the previous element p == -1
    if the current element is on the right of the previous element p == 1
   */
    int flag;
    while (root){
        if (key == root->key){
            if (flag == -1){
                int quant = root->quantity;
                tree* rr = root->right;
                tree* rl = root->left;
                temp->left = root->right;
                free(root);
                root = rr;
                if (!root) return;
                while (root->left) root = root->left;
                rr->quantity = quant;
                root->left = rl;
                return;
            }
            if (flag == 1){
                int quant = root->quantity;
                tree* rr = root->right;
                tree* rl = root->left;
                temp->right = root->right;
                free(root);
                root = rr;
                if (!root) return;
                while (root->left) root = root->left;
                rr->quantity = quant;
                root->left = rl;
                return;
            }
        }
        if (key < root->key){
            root->quantity--;
            temp = root;
            flag = -1;
            root = root->left;
            continue;
        }
        if (key > root->key){
            temp = root;
            flag = 1;
            root = root->right;
            continue;
        }
    }
    std::cerr<<"This element does not exists";
}
tree* maximum(tree* root){
    while (root->right){
        root = root->right;
    }
    return root;
}
tree* minimum(tree* root){
    while (root->left){
        root = root->left;
    }
    return root;
}
// if element with this key does not exist returns -1
int getNumber(tree* root, int key){
    int number = 0;
    while (root && (root->key != key)){
        if (key < root->key) root = root->left;
        else {
            number += root->quantity;
            root = root->right;
        }
    }
    if (!root) return -1;
    return number + root->quantity;
}
//-------------------------------------------------------//
