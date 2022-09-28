#ifndef INIT_H_ // if this is not defined don't do it again
#define INIT_H_
#include "global.h"
#include "symbol.h"

struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	0, 0
};
void init()
{
	struct entry *p;
	for (p = keywords; p->token; p++) 
		insert(p->lexptr, p->token);
}
#endif // INIT_H_

