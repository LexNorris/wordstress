#ifndef TREE_BUILT
#define TREE_BUILT

/*
 * This segment is simply an editted version of the geeksforgeeks binary AVL tree.
 * I used the insert, search, and balance functions to ensure that the tree remained balanced
 * thus ensuring that the program does not sacrifice speed in the name of efficient data storage.
 * (Although, let's be honest with ourselves. If I was really looking for efficient data storage
 * I would have used Assembly and built this thing from the ground up so I would have the fewest 
 * possible bits in the binary file.)
 */
struct Node {
	geek key;
	struct Node *left, *right;
	int height;
};

//create new Node
struct Node * newNode(geek * item){
	struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
	memmove(&(temp->key), (item), sizeof(geek));
//		printf("newNode key: %s\n", temp->key.word);
	temp->left = temp->right = NULL;
	temp->height = 0;
	return temp;
	//	printf("Word in node: %s\n", temp->word.word);
}

int max(int a, int b){
	return (a>b)? a:b;
}


int height(struct Node * N){
	if(N==NULL){
		return 0;
	}
	return 1+max(height(N->left), height(N->right));
		//this basically keeps adding 1. It's very clever. I'm glad to have this in my repertoire now.
}
struct Node * rightRotate(struct Node * root){
	struct Node *newRoot = root->left;
	struct Node *temp2 = newRoot->right;
		//rotation below
	newRoot->right = root;
	root->left = temp2;

	root->height = height(root);
	newRoot->height = height(newRoot);
		return newRoot;
}

struct Node * leftRotate(struct Node * root){
	struct Node * newRoot = root->right;
	struct Node * temp2 = newRoot->left;

	newRoot->left = root;
	root->right = temp2;

	root->height = height(root);
	newRoot->height = height(newRoot);

	return newRoot;
}

int getBalance(struct Node *N){
	if(N==NULL){
		return 0;
	}
	return height(N->left) - height(N->right);
}

struct Node * insert(struct Node * N, geek * key){
	if(N == NULL){
	//	printf("Inserting as root\n");
		return (newNode(key));
	}
	//if there is a duplicate, replace the key and have everything else remain the same.
	if (strcmp(key->word, N->key.word)==0){
		memmove(N->key.word, key->word, sizeof(geek));
		return N;
	}
			
	if (strcmp(key->word, N->key.word)<0){
		N->left = insert(N->left, key);
	}
	else if (strcmp(key->word, N->key.word)>0){
		N->right = insert(N->right, key);
	}
	else{
		puts("Something went horrifically wrong. Contact Lex Norris through GitHub with detailed information on what you have given the program. Without user feedback I won't know if there is a problem. Thank you and I'm sorry. Hopefully, this didn't break anything.\n");
		return N;
	}

	N->height = height(N);

	int balance = getBalance(N);

	if(balance > 1 && strcmp(key->word, N->left->key.word)<0){
		return rightRotate(N);
	}
	if(balance < -1 && strcmp(key->word, N->right->key.word)>0){
		return leftRotate(N);
	}
	if(balance > 1 && strcmp(key->word, N->left->key.word)>0){
		N->left = leftRotate(N->left);
		return rightRotate(N);
	}
	if(balance < -1 && strcmp(key->word, N->right->key.word)<0){
		N->right = rightRotate(N->right);
		return leftRotate(N);
	}
		return N;


}
//This is a search function. This one is all me.

geek * search(char * key, struct Node * root){
				//Should check the given node
	if (strcmp(key, root->key.word)==0){
//		printf("%s, %s\n", key, root->key.word);
//		printf("match\n");
		return &root->key;
	}
	else if(root->left!=NULL && strcmp(key, root->key.word)<0){
//		printf("moving left\n");
		return search(key, root->left);
	}
	else if(root->right!=NULL && strcmp(key, root->key.word)>0){
//		printf("moving right\n");
		return search(key, root->right);
	}
		return NULL;
}
	//This is a testing function for us. This makes sure that all of our nodes are properly parsed when reading from a file and/or inserting into the tree. WE could attempt to maintain the nodes, but I think it would be easier to read out and insert. It should be properly balanced every time, but we'll see
void preOrder(struct Node * root){
	if(root !=NULL){
		printf("%s\n", root->key.word);
		for(int i=0; i < root->key.patNum; i++){
			printf("%d: %s\n", i+1, root->key.meh[i]);
		}
		printf("\n");
	       preOrder(root->left);
		preOrder(root->right);	       
	}
}
#endif
