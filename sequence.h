#pragma once
class sequence
{
protected:
	char* seq;
	int length;


public:
	sequence();
	sequence(int length);
	sequence(sequence& rhs);
	virtual void print() = 0;
	friend char* Align(sequence * s1, sequence *s2);

	virtual ~sequence();
};

