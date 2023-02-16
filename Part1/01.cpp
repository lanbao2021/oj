#include <iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *left, *right;
}BiTNode, *BiTree;

int nums[1000] = {0};

BiTNode* fun(int *nums, int left, int right){
    if(left>=right) return NULL;
    int split = left;
    for(int i=left+1; i<right; ++i){
        if(nums[i]>nums[split])
            split = i;
    }
    
    BiTNode* root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = nums[split];
    root->left = fun(nums, left, split);
    root->right = fun(nums, split+1, right);
    
    return root;
}

void PreOrder(BiTNode* tree){
    if(tree!=NULL){
        cout << tree->data << " ";
        if(tree->left==NULL && tree->right==NULL){
            return;
        }
        if(tree->left==NULL){
            cout << "null ";
        }
        else{
            PreOrder(tree->left);
        }
        if(tree->right==NULL){
            cout << "null ";
        }
        else{
            PreOrder(tree->right);
        }
    }
    
}

int main() {
    int tmp;
    int i=0;
    cout << "input nums(stop by EOF): ";
	while(cin >> tmp){
	    nums[i] = tmp;
	    i++;
	}
	
	BiTNode* tree = fun(nums, 0, i);
	PreOrder(tree);
	
	return 0;
}