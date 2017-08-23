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

	Sniffle* getPrev()
	{
		return _prev;
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
private:
	std::allocator<Sniffle> nodeAllocator;

	Sniffle* alloNode(char ch);
};

#endif