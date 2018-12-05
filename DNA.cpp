#include "DNA.h"



DNA::DNA()
{
}
DNA::DNA(char*seq, DNA_type atype,int length):sequence(length)
{
	seq = seq;
	type = atype;


}
DNA::DNA(DNA &rhs)
{
	rhs.seq = seq;
	rhs.type = type;
}
void DNA::print()
{	cout << "the strand is: " ;
for (int i = 0;i < start_char - end_char;i++) {
	cout << seq[i];
}
cout << endl;
	cout << "its type is: " << type;

}
RNA DNA::convert_to_RNA()
{
	char* arr;
		arr = new char[end_char-start_char];
	for (int i = 0;i < end_char;i++) 
	{
		if (seq[i] == 'T') 
		{
			arr[i] = 'U';
		}
		else 
		{
			arr[i] = seq[i];
		}
	}
	RNA_type type= pre_mRNA;
	RNA R1(arr, type,get_endchar()-get_startchar());
	return R1;

}
void DNA::build_complemantary_strand()
{
	for (int i = start_char;i < end_char;i++) {
		char x = seq[i];
		if (x == 'A')
		{
			complemantary_strand->seq[i] = 'T';
		}
		else if (x == 'T')
		{
			complemantary_strand->seq[i] = 'A';
		}
		else if (x == 'C')
		{
			complemantary_strand->seq[i] = 'G';
		}
		else if (x == 'G')
		{
			complemantary_strand->seq[i] = 'C';
		}
		else
		{
			complemantary_strand->seq[i] = x;
		}
	}
	for (int i = start_char; i < (end_char/2); i++)
	{
		char temp;
		temp = seq[i];
		seq[i] = seq[end_char-1 - i];
		seq[end_char-1 - i] = temp;

	}

	
}
void DNA::set_endchar(int x) {
	end_char = x;
}
void DNA::set_startchar(int y) {
	start_char = y;
}
int DNA::get_endchar() {
	return end_char;
}
int DNA::get_startchar() {
	return start_char;
}



DNA::~DNA()
{
}
