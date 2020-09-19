#include <stdio.h>
#include <stdlib.h>

struct Data{
	int num;
	Data *left;
	Data *right;
}*node;

struct Data *createnode(int num){
	struct Data *data = (struct Data*) malloc(sizeof(struct Data));
	data->num=num;
	data->left=data->right=NULL;
	
	return data;
}

struct Data * insert(struct Data *node, int num){
	if(!node) node = createnode(num);
	else if(num < node->num){
		node->left = insert(node->left, num);
	}
	else if(num > node->num){
		node->right = insert(node->right, num);
	}
	
	return node;
}

void search(struct Data *node, int idx){
	if(!node){
		printf("Not Found!\n");
		return;
	}
	if(node->num == idx){
		printf("Found!\n");
	}
	if(node->num < idx) return search(node->right, idx);
	else if(node->num > idx) return search(node->left, idx);
}

int main(){
	struct Data *root = NULL;
	
	int n;
	printf("How much numbers you want to add : ");
	scanf("%d", &n);
	printf("Please insert numbers : ");
	for(int i=0;i<n;i-=-1){
		int num;
		scanf("%d", &num);
		if(root==NULL){
			root = insert(root, num);
		}
		else{
			insert(root, num);
		}
	}
	
	int idx;
	printf("Insert Index to search : ");
	scanf("%d", &idx);
	search(root,idx);
	return 0;
}
