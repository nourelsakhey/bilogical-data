#include "RNA.h"



RNA::RNA()
{
}
RNA::RNA(char *seq, RNA_type atype,int length) :sequence(length)
{
	seq = seq;
	type = atype;
	
	
}
RNA::RNA(RNA&rhs)
{
	rhs.seq = seq;
	rhs.type = type;
}
void RNA::print() 
{
	cout << "the strand is: ";
	for (int i = 0;i < length;i++) {
		cout << seq[i];
	}
	cout << endl;
	cout << "its type is: " << type;

	
}
Protein RNA::convert_to_Protien(const Condonstable &table)
{
	
}
DNA RNA::convert_to_DNA()
{
	char* arr;
	arr = new char;
	for (int i = 0;i<length;i++)
	{
		if (seq[i] == 'U')
		{
			arr[i] = 'T';
		}
		else
		{
			arr[i] = seq[i];
		}
	}
	DNA_type type = promoter;
	DNA D1(arr, type, length);
	return D1;

}


RNA::~RNA()
{
}
