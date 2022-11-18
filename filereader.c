#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
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
	char filepath[50] = "~";
//	strcat(letter, ".bin");
		heck[1] = '\0';
		strcat(heck, ".bin");
//		strcat(filepath, heck);
//		printf("%s\n", filepath);
	int blah = chdir("/opt/wordstress/resources");
	getcwd(filepath,sizeof(filepath));
//		printf("HELLO. PRINT SOMETHING: %d %s\n", blah, filepath);
return fopen(heck, instructs);
}

void preOrderAdd(FILE * ptr, struct Node * root){
	if(root!=NULL){
		fwrite(&(root->key), sizeof(geek), 1, ptr);
	//	printf("%s added\n", root->key.word);
		preOrderAdd(ptr, root->left);
		preOrderAdd(ptr, root->right);
		free(root);
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
	chdir("/opt/wordstress/resources");
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
	match = UserSearch(word, root);
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

int addOne(int args, char * word, geek buffer){
	struct Node * root = NULL;
	FILE * ptr = openFile(&word[0], "r+");	
		if(!ptr){
			printf("File %c not found, making new file\n", word[0]);
			ptr = openFile(&word[0],"a");
				if(!ptr) {
					perror(&word[0]);
					exit(EXIT_FAILURE);
				}
			fwrite(&buffer, sizeof(geek), 1, ptr);
			fclose(ptr);
			}
		else{
		root = insert(root, &buffer);
		root = readin(ptr, root);

		ptr = openFile(&word[0], "w");
		preOrderAdd(ptr, root);

		fclose(ptr);
		}
		return 0;

}

int recursiveSearch(){
	return 1;
}
void list(char * letter){
	letter[1] = '\0';
	int blah = chdir("/opt/wordstress/resources");
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

geek rendLine(char * line){
		//based partially on code from educative.io
	
	geek stress;
       	char word[25];	
	int num = 0;
	int blep = 0;
	char *ptr;
	char *token = strtok(line, " ");
//	printf("\n");
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
//	printf("%s ", token);
		token = strtok(NULL, " ");	
	}
//	printf("%s ", word);
			addOne(1, word, stress);
}

int insertByFile(char * fp){
	char * line = NULL;
	size_t len = 0;
	ssize_t read;		
	FILE * outof = fopen(fp, "r");
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
}


int readOutFile(char * fileName){
	//Do we want it to make a new file wherever the function was called? Or do we simply want to output to the screen?
	//What about a sentence? CAn we give it a sentence? What if we start with that?
	//Yeah actually. That's a good plan
}

struct Node * modifiedReadin(char *word, FILE * ptr, struct Node * r){
	fseek(ptr,0,SEEK_END);
	int sz = ftell(ptr);
	rewind(ptr);

	geek blep[sz/sizeof(geek)];
		int i = 0;
	for(i = 0; fread(&blep[i], sizeof(geek), 1, ptr) ==1; i++){
		if(strcmp(blep[i].word,word)!=0){
		r = insert(r, &blep[i]);
		}
	}
	fclose(ptr);
	preOrder(r);
	return r;
}
int deleteFromFile(char * wordRemove){
	//open file for reading
	char * word = malloc(sizeof(wordRemove));
		printf("We past malloc\n");
	struct Node * root = NULL;
	geek * match = NULL;
	strcpy(word, wordRemove);
//	chdir("/opt/wordstress/resources");
	FILE * ptr = openFile(wordRemove, "r+");
		perror("file opened. Or should be.\n");
	if(ptr != NULL){
	root = modifiedReadin(word, ptr, root);
	ptr = fopen("a.bin","w+");
	preOrderAdd(ptr, root);
	fclose(ptr);
	}			
		return 0;
}

int help(){

	printf("Users may use the following flags:\n-a: add word\n-r: insert multiple wordsin series\n-f: insert by text file\n-s: search for a word\n-l: list words in a file. If no file specified, none will be listed.\n-h help\n\nFor more information refer to the README.md file associated with this project.\n");
	return 0;
}
int main(int args, char* argv[]) {
	char word[50];
	if (args<2){
		printf("Did you mean: *stress -help*?\n");	}
	if(args == 2){
		if(strcmp(argv[1],"-help")){
				help();
		}
	}
	if(args>=3){
		if(strcmp(argv[1], "-a")==0){		//if tag is -a add the following word
			//ACTUAL TODO: -a needs be under a different argument number
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
				char fp[PATH_MAX];
					if(getcwd(fp, sizeof(fp)) != NULL) {
						strcat(fp, argv[2]);
					}
					else {
						perror("Something went wrong. I know this was not helpful, but that's all I can tell you.\n");
					}
//				printf("%s\n", argv[2]);
				insertByFile(argv[2]);
				}
		if(strcmp(argv[1],"-d") ==0){
			deleteFromFile(argv[2]);
		}
	}
}


