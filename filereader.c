#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "geekbuild.h"
#include "bintree.h"


//typedef struct {
//	char word[150];
//	int meh[15];
//} geek;

int recurse = 0;
int add = 0;
int file = 0;


FILE * openFile(char * heck, char * instructs){
		heck[1] = '\0';
		strcat(heck, ".bin");
	return fopen(heck, instructs);
}

void preOrderAdd(FILE * ptr, struct Node * root){
	if(root!=NULL){
		printf("root->key: %s\n", root->key.word);
		fwrite(&(root->key), sizeof(geek), 1, ptr);
		preOrderAdd(ptr, root->left);
		preOrderAdd(ptr, root->right);
	}
}

struct Node * readin(FILE * ptr, struct Node * r)
{
	fseek(ptr,0,SEEK_END);
	int sz = ftell(ptr);
	rewind(ptr);
		geek blep[sz/sizeof(geek)];
		int i = 0;
	for(i = 0; fread(&blep[i], sizeof(geek), 1, ptr) ==1; i++){
		r = insert(r, &blep[i]);	
	}
	fclose(ptr);
//	preOrder(r);
	return r;
	}

void find(char * wordSearch){
	char * word = malloc(sizeof(wordSearch));
	struct Node * root = NULL;
	geek * match = NULL;
	strcpy(word, wordSearch);
	printf("word: %s\n", word);
	FILE * ptr = openFile(wordSearch, "r");
//	perror("file opened. Or should be.");
	if(ptr != NULL){
//		perror("file not opened");
	//	printf("no words found. exitting\n");
	//	return;
//		exit(0);
	//}
//	printf("word after openFile: %s\n", word);
	root = readin(ptr, root);
//	perror("tree loaded\n");
	match = search(word, root);
	if(match!=NULL){
		printf("%s\n", match->word);
		for(int i = 0; i<match->patNum;i++){
			printf("%d: %s\n", (i+1), match->meh[i]);
		}
	}
	else{
		printf("word not found.");
	}
	}
	else{
		printf("Error 404: File not found.\n");
	}
}



//This no longer does the trick. WE need to ensure that we are adding this to the tree and then we are 
	//How do we prevent duplicates? Do we simply write the entire inOrder list to the file? This seems a little bit
	//	Lex, this is why we're breaking it up into letters. And remember that we do have bin files on our side. Of which we have only one open at a time. We will be okay.
	//	I don't know. I don't like this.
	//		Remember that binary trees are small data storage. It will be okay.
	//		Fine.
int addOne(int args, char * word, geek buffer){
	struct Node * root = NULL;
//	printf("%s\n", word);
		//	perror("printf passed\n");
	FILE * ptr = openFile(&word[0], "r+");	
		if(!ptr){
			printf("File %c not found, making new file\n", word[0]);
			ptr = openFile(&word[0],"a");
			fwrite(&buffer, sizeof(geek), 1, ptr);
			fclose(ptr);
			}
		else{
	//		strcpy(buffer.word, argv[3]);		
		//	for(int i = 0; i<4; i++){
		root = insert(root, &buffer);
		root = readin(ptr, root);
//			printf("addOne root word: %s\n", root->key.word);
		ptr = openFile(&word[0], "w");
		preOrderAdd(ptr, root);

		fclose(ptr);
//			fwrite(&buffer, sizeof(buffer), 1, ptr);
		//	}
		
		//	printf("After copy: %s\n", buffer.word);
		}
		return 0;

}

int recursiveSearch(){
	return 1;
}
void list(char * letter){
	letter[1] = '\0';
	strcat(letter, ".bin");
//	printf("letter file: %s", letter);
	FILE * ptr = fopen(letter, "r");
	if(ptr == NULL){
		printf("%s not found.\n", letter);
		exit(0);
	}
	else {
		struct Node * root = NULL;
		root = readin(ptr, root);
		preOrder(root);
	}
}

//geek *
geek rendLine(char * line){
		//based partially on code from educative.io
	//TODO: tear apart a given line to make a geek struct
		//You can base this on your old CS449 project which you should still have access to.
	geek stress;
       	char word[25];	
	int num = 0;
	int blep = 0;
	char *ptr;	//I don't know what this is
	char *token = strtok(line, " ");
	printf("\n");
	while(token != NULL){
			if(num == 0){
			stress.patNum = strtol(token, &ptr, 10);
			}
			else if(num == 1){
		strcpy(stress.word, token);
//		word = token;
		strcpy(word, token);	
			}
			else if (num > 1){
		strcpy(stress.meh[blep], token);
		++blep;
			}
		++num;
		printf("%s ", token);
		token = strtok(NULL, " ");	
	}
	printf("%s ", word);
			addOne(1, word, stress);
//		num = strtol(token,&ptr,10);
			//
		
		//	printf("%ld\n", num);

}

int insertByFile(char * fp){
	//TODO: open file
	//
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE * outof = fopen(fp, "r");	//This opens the file we are reading from
	geek * insert = NULL;
		if (outof == NULL){
			printf("please provide a valid filepath.\n");
			exit(1);
		}

	while ((read = getline(&line, &len, outof))!= -1) {
//		line = getline(outof);
//		insert = rendLine(line);
//		printf("%s\n", line);
			rendLine(line);

		}
	fclose(outof);
	if(line){
		free(line);
	}
	return 0;
	//	FILE into = openFile(fp, "a");

	//This is wrong.	Is it? Looks right to me.
	//make a 7 dimensional array with
	//1. number of stress patterns
	//2. word
	//3. stress pattern 1
	//4. stress pattern 2
	//5. stress pattern 3
	//6. stress pattern 4
	//7. stress pattern 5
	//pass each of these individually to rendLine to make a geek struct
	//pass geekstruct and word to addOne.
	
}


//This should read a written piece word by word. We'll keep the most checked words in a smaller file.
int readOutFile(char * fileName){
	//Do we want it to make a new file wherever the function was called? Or do we simply want to output to the screen?
	//What about a sentence? CAn we give it a sentence? What if we start with that?
	//Yeah actually. That's a good plan
}


int main(int args, char* argv[]) {
	char word[50];
	if (args<2){
		printf("That's not how you're supposed to play the game\n");
	}
	if(args == 2){

	}
	if(args>=3){
		if(strcmp(argv[1], "-a")==0){		//if tag is -a add the following word
			//TODO: check to ensure all arguments are in order and none are skipped. Maybe it is best to remove the recursive function for now until we can figure that out.
		printf("%s\n", argv[3]);	
			geek buff = toStress(argv);
//newNode(&buff);
			addOne(args, argv[3], buff);
//				printf("Made it to -a\n");
		}
		if(strcmp(argv[1], "-r")==0){		//if tag is -r, add the following words.
			printf("recursive\n");
				geek blep[10];
//				perror("blep created");
				toStressIterative(argv, 0, 2, blep);
			for (int i = 0; i<atoi(argv[2]);++i){
				addOne(args, blep[i].word, blep[i]); 
				}
		}
				//TODO: ensure that added words overwrite if there are duplicates
		if(strcmp(argv[1], "-s")==0){		//if -s tag, search for following word.
			for (int i = 2; i<args; ++i){
				find(argv[i]);
				printf("argv[%d] = %s\n", i, argv[i]);
			}
		}

		if (strcmp(argv[1], "-l")==0){
			//check to make sure that the char recieved is only a singular letter. If not. throw error
			if(strlen(argv[2]) == 1){
				char bleh;
				strcpy(&bleh, argv[2]);//, sizeof(char));
				if(isalpha(bleh)){
//					printf("isalpha checked\n");
					char ch = (tolower(*argv[2]));
					list(&ch);
				}
				else{
					printf("File name must be a letter\n");
					exit(0);
				}
			}
			else{
				printf("file name must be one character in length\n");
				exit(0);
			}
		}
		if(strcmp(argv[1], "-f") ==0){
				printf("%s\n", argv[2]);
				insertByFile(argv[2]);
				}
	}
}


