#ifndef SNIFFLES_STRING_H
#define SNIFFLES_STRING_H

//Main Header for Sniffles String

class Sniffle
{
private:
	char ch;
	Sniffle* next;
	Sniffle* prev;
public:
	Sniffle(char ch);
	~Sniffle();

	char getChar()
	{
		return ch;
	}

	void setChar(char newch)
	{
		ch = newch;
	}

	bool compChar(char other)
	{
		return ch == other;
	}

	Sniffle* getNext()
	{
		return next;
	}

	Sniffle* getPrev()
	{
		return prev;
	}

	bool nextIsNull()
	{
		return next == nullptr;
	}

	bool prevIsNull()
	{
		return prev == nullptr;
	}

	inline bool compNextChar(char other)
	{
		if(!nextIsNull()) return next->ch == ch;
		else return false;
	}

	inline bool compPrevChar(char other)
	{
		if(!prevIsNull()) return prev->ch == ch;
		else return false;
	}
};

class SniffleString
{
private:
	std::allocator<Sniffle> nodeAllocator;
};

#endif