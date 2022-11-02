#ifndef GEEK_BUILT
#define GEEK_BUILT
typedef struct{
	char word[150];
	char meh[8][19];	//8 different patterns. each pattern can be 6 long
	int patNum;
}geek;

//TOSTRESS takes an array of char arguments and then converts them to a geek struct based on the arguments themselves.
//At present this is used solely for -a arguments. (Single word by user) 
geek toStress(char* argv[]) {
int i;
	//arg 2: number of patterns	
//arg 3: word
//arg 4++ syllable stress
	geek buffer;// = malloc(sizeof(geek));
	strcpy(buffer.word, argv[3]);
		printf("Word is: %s\n", buffer.word);
//	perror("buffer made \n");	
	buffer.patNum = atoi(argv[2]);
//		perror("patNum allocated\n");
	for (i=0;i< atoi(argv[2]); ++i){
		strcpy(buffer.meh[i], argv[i+4]);
	}
		return buffer;
	//	printf("geekbuilder word: %s\ngeekbuilder stress: %s\n", buffer->word,buffer->meh[0]);       
}

//initialize ck to 2, remaining to argv[2]
void toStressIterative(char* argv[], int curr, int ck, geek all[10]){
	if (atoi(argv[2]) == curr){
		perror("returning all");
		return;
	}
		
	else{
		int s = atoi(argv[ck+(curr*2)+1]);
		all[curr].patNum = atoi(argv[ck+(curr*2)+1]);	//3 7 10 13
		strcpy(all[curr].word, argv[ck+(curr*2)+2]);
		for(int i = 0; i< all[curr].patNum; ++i){
			strcpy(all[curr].meh[i], argv[ck+(curr*2)+3+i]);
				//5 6	9	12	15	16
		}
		ck = ck+s;
		toStressIterative(argv, curr+1, ck, all);
	}
}
//No. Something is wrong with how we're passing the variable. Hmm
#endif
