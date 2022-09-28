#ifndef EMITTER.H
#define EMITTER.H
#include "global.h"
extern FILE * output;
#define IL 1

void emit(int t,int  tval)
{	
	if(IL == 1){
	
	switch(t) {
	case '+':
		fprintf(output, "pop r1\npop r2\nadd r2,r1\npush r2\n"); 
		break;
	case '-':
		fprintf(output,"pop r1\npop r2\nsub r2,r1\npush r2\n");
		break;
	case '*':
		fprintf(output,"pop r1\npop r2\nmult r2,r1\npush r2\n");
		break;
	case '/':
		fprintf(output,"pop r1\npop r2\nrdiv r2,r1\npush r2\n");
		break;
	case DIV:
		fprintf(output,"pop r1\npop r2\ndiv r2,r1\npush r2\n");
		break;
    case MOD:
		fprintf(output,"pop r1\npop r2\nmod r2,r1\npush r2\n");
		break;
	case NUM:
		fprintf(output,"push %d\n",tval);
		break;
	case ID:
		fprintf(output,"push %s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	} } else {
		switch(t) {
case '+': case '-': case '*': case '/':

fprintf(output,"%c", t); 
break;
case DIV:
fprintf(output," DIV ");
break;
case MOD:
fprintf(output," MOD "); 
break;
case NUM:
fprintf(output,"%d", tval);
break;
case ID:
fprintf(output," %s ", symtable[tval].lexptr); 
break;
default:
printf("token %d, tokenval %d\n", t, tval);

}
	}
}

#endif // EMITTER

