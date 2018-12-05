#include "sequence.h"



sequence::sequence()
{
}
sequence::sequence(int alength)
{
	length = alength;
	seq = new char[alength];
}
sequence::sequence(sequence & rhs)
{
	rhs.seq = new char;
	rhs.seq = seq;
}
char* Align(sequence *s1, sequence *s2)
{

}

sequence::~sequence()
{
}
