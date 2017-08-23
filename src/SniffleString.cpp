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