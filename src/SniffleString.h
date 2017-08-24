#ifndef SNIFFLE_STRING_H
#define SNIFFLE_STRING_H

//Main Header for Sniffles String

class Sniffle
{
private:
	char _ch;
	Sniffle* _next;
	Sniffle* _prev;
public:
	Sniffle(char ch);
	~Sniffle();

	char getChar()
	{
		return _ch;
	}

	void setChar(char newch)
	{
		_ch = newch;
	}

	bool compChar(char other)
	{
		return _ch == other;
	}

	Sniffle* getNext()
	{
		return _next;
	}

	void setNext(Sniffle* snif)
	{
		_next = snif;
	}

	Sniffle* getPrev()
	{
		return _prev;
	}

	void setPrev(Sniffle* snif)
	{
		_prev = snif;
	}

	bool nextIsNull()
	{
		return _next == nullptr;
	}

	bool prevIsNull()
	{
		return _prev == nullptr;
	}

	inline bool compNextChar(char other)
	{
		if(!nextIsNull()) return _next->_ch == other;
		else return false;
	}

	inline bool compPrevChar(char other)
	{
		if(!prevIsNull()) return _prev->_ch == other;
		else return false;
	}
};

class SniffleString
{
public:
	std::allocator<Sniffle> nodeAllocator;
private:
	Sniffle* _str;

	Sniffle* alloNode(char ch);

	void deAlloNode(Sniffle* snif)
	{
		nodeAllocator.deallocate(snif, 1);
	}
	//deallocates and empties the entire string.
	void deAlloStr(Sniffle* snif);
public:
	SniffleString(const char* cst);
	~SniffleString();
};

#endif