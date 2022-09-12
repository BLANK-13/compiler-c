#include <stdio.h>
#include <ctype.h>
int lookahead;

void expr(void);
void rest(void);
void term(void);
void match(int);
void error(void);

void expr(void){
	term();
	while(1){
		if (lookahead == '+'){
			match('+');
			term();
			putchar('+');
		}
		else if(lookahead == '-'){
			match('-');
			term();
			putchar('-');
			}
			else break;
		}
	}
	
void term (void){
	if (isdigit(lookahead)){
		putchar(' ');
		putchar(lookahead);
		putchar(' ');
		match(lookahead);
	}else{
		error();
	}
}	



void rest(void){
	if (lookahead == '+'){
		match('+');
		term();
		putchar('+');
		rest();
	}else if (lookahead == '-'){
		match('-');
		term();
		putchar('-');
		rest();
	}else error();
}

void match(int token){
	if (lookahead == token){
		lookahead = getchar();
	}
	else error();
}
void error(void){
printf("syntax error\n");
exit(1);	
}

int main() {
   lookahead = getchar();
   expr();
}
