#include <stdio.h>
#include <ctype.h>

//tokens definition
#define NUM 256

int lookahead;
int lineNo = 1;
int tokenVal;

void expr(void);
void rest(void);
void term(void);
void match(int);
void error(void);
int lexan(void);

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
	if (lookahead==NUM){
		printf("%d ", tokenVal);
		match(NUM);
	}else{
		error();
	}
}

int lexan(){
    int t;
    while(1){
        t = getchar();
        if(t ==' ' || t =='\t');
        else if (t == '\n')lineNo++;
        else if (isdigit(t)){
			ungetc(t, stdin);
			scanf("%d", &tokenVal);
			fflush(stdin);
			fflush(stdin);			
			
			return NUM;
			
			}
			
		else return t;
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
		lookahead = lexan();
	}
	else error();
}

void error(void){
printf("syntax error\n");
exit(1);	
}

int main() {
   lookahead = lexan();
   expr();
   }
