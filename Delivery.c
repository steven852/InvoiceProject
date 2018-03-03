#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_CATEGORIES 10

//Globals
int year = 0;
char *post = NULL;
char name[20];


//Structs
struct Info{
	
	int size;
	double cost;
	int weight;
};

typedef struct Info Info_s;

FILE *data;
FILE *out;

//Prototypes
void intialize(FILE *data,FILE *out);
void delivery(FILE *data,FILE *out,Info_s *myInfo);
void myclose();

int main(int argc, char **argv){
	Info_s *myInfo = NULL;
	myInfo = (Info_s *)malloc(NUM_OF_CATEGORIES*sizeof(Info_s));
	
	data = fopen(argv[1],"r");
	if (data == NULL){
			printf("ero");
		exit(1);
	}
	
	//intialize(data,out);
	
	fscanf(data,"%d",&year);
	sprintf(name,"%s%d","Invoice",year);
	printf("%s\n",name);
	out = fopen(name,"w");
	if(out == NULL){
		printf("ero2");
		exit(1);
	}
	
	
	printf("%s\n",name);
	

	fprintf(out,"Deliveries of %d\r\n",year);
	
	
	
	
	myclose();
	return 0;
}

void intialize(FILE *data,FILE *out){

	
	
}

void delivery(FILE *data,FILE *out,Info_s *myInfo){
	int i = 0;


//	for(i = 0; i<NUM_OF_CATEGORIES; i++){
//		fscanf(data,);
		
		
//	}
	
	
	
}
void myclose(){
	close(data);
	close(out);
	
}