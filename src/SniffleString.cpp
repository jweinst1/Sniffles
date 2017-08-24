#include "SniffleTypes.h"
#include "SniffleString.h"

Sniffle::Sniffle(char ch): _ch(ch), _next(nullptr), _prev(nullptr) 
{

}

Sniffle* SniffleString::alloNode(char ch)
{
	Sniffle* newNode = nodeAllocator.allocate(1);
	nodeAllocator.construct(newNode, ch);
	return newNode;
}

//recursively deallocates an entire string
void SniffleString::deAlloStr(Sniffle* snif)
{
	if(!(snif->nextIsNull())) deAlloStr(snif->getNext());
	if(!(snif->prevIsNull())) deAlloStr(snif->getPrev());
	nodeAllocator.deallocate(snif, 1);
}

//constructs a sniffle string from a cstring
SniffleString::SniffleString(const char* cst)
{
	Sniffle* constr = alloNode(*cst);
	_str = constr;
	while(*cst++)
	{
		constr->setNext(alloNode(*cst));
		constr->getNext()->setPrev(constr);
		constr = constr->getNext();
	}
}

//main destructor for whole string
SniffleString::~SniffleString()
{
	deAlloStr(_str);
}