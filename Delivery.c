#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_CATEGORIES 10

//Globals
int year = 0;
char *post = NULL;
char name[20];
char postyear[20];

//Structs
struct Info{
	int size;
	double cost;
	int weight;
};

typedef struct Info Info_s;

//Prototypes
void delivery();

int main(int argc, char **argv){
	Info_s *myInfo = NULL;
	myInfo = (Info_s *)calloc(NUM_OF_CATEGORIES,sizeof(Info_s));
	
	//printf("%s\n",argv[1]);
	
	//Initialize
	FILE *data;
	FILE *out;
	sprintf(postyear,"%s%s",argv[1],".txt");
	data = fopen(postyear,"r");
	if (data == NULL){
		perror("error opening file data\n");
		exit(1);
	}
	
	fscanf(data,"%d",&year);
	sprintf(name,"%s%d","Invoice",year);
	
	out = fopen(name,"a");
	if(out == NULL){
		perror("error opening file out");
		exit(1);
	}
	//End of initialize
	
	close(data);
	close(out);
	return 0;
}


void delivery(){

}
