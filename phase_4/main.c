#include "global.h"
#include "Init.h"
#include "parse.h"
FILE * input;
FILE * output;
FILE * err;
int main()
{
	input = fopen("file.exp" , "r");
	output = fopen("file.obj" , "w"); // if the file doesn't exist it will create it.
	if (input == NULL){
		printf("the file doesn't exist");
	}
    init();
    parse();
    exit(0);
    return 0;
}

