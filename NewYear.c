#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_CATEGORIES 10

//Globals
char post[20];
int year;
FILE *fp;

//Structs
struct Info{
	
	int size;
	double cost;

};

typedef struct Info Info_s;

//Prototypes
void setInfo(Info_s *info);
void myPrint(Info_s *info);
void setYearPost();
void createFile();
void myClose(Info_s* info, FILE* fp);
void myWrite(FILE* fp,Info_s *info);

int main(int argc, char **argv){
	
	Info_s* myInfo = NULL;
	myInfo = (Info_s*)malloc(NUM_OF_CATEGORIES*sizeof(Info_s));
	setYearPost();
	setInfo(myInfo);
	myPrint(myInfo);
	createFile();
	myWrite(fp,myInfo);
	myClose(myInfo,fp);
	return 0;
	
}

//Asks the user the year and post's name
void setYearPost(){
	printf("Type year\n");
	scanf("%d",&year);
	printf("Type your posts name\n");
	scanf("%s",post);

	
}

//Asks the user for his delivery info
void setInfo(Info_s *info){
	int size = 110;
	int i = 0;

	while(size <= 200){
		
		printf("Input cost of sized %d items:  \n",size);
		scanf(" %lf",&(info[i].cost));
	
		info[i].size = size;
		
		if(size == 180){		//size 190 is not common
			size = size + 20;
		}
		else {size = size + 10;}
		i++;
	}
	
	printf("Input cost of no sized items\n");
	scanf("%lf",&(info[i].cost));
	info[i].size = 0;
}

void myPrint(Info_s *info){
	
	int i = 0;
	printf("Your year and post are %d - %s \n",year,post);
	printf("Your list is \n");
	for(i = 0; i<NUM_OF_CATEGORIES; i++){
	
		printf("%d - %lf\n",info[i].size,info[i].cost);
		
	}
	
	
}

void createFile(){

	char name[30] = {'\0'};

	sprintf(name,"%s%d%s",post,year,".txt");

	fp = fopen(name,"w");

	if(fp == NULL){
		exit(1);
 	}
	
}

void myWrite(FILE* fp,Info_s *info){
	int i = 0;
	fprintf(fp,"%d	%s\r\n",year,post);
	while (i < NUM_OF_CATEGORIES){
		fprintf(fp,"%d	%lf\r\n",info[i].size,info[i].cost);
		i++;
	}
	
}

//Close file and free memory
void myClose(Info_s* info, FILE* fp){
	close(fp);
	free(info);
	
}



