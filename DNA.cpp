#include "DNA.h"



DNA::DNA()
{
}
DNA::DNA(char*aseq, DNA_type atype,int length):sequence(length)
{
	for (int i = 0;i < length;i++)
	{
		seq[i]=aseq[i]  ;

	}
	type = atype;
}

DNA::DNA(DNA&rhs)
{
	type = rhs.type;
	this->seq = rhs.seq;

}
void DNA::print()
{	cout << "the strand is: " ;
	for (int i = 0;i < length;i++) {
		cout << seq[i];
	}
cout << endl;
cout << "the type of the strand is:";
switch (type)
{ 
case promoter:
	cout << "promoter";
	break;
case motif:
	cout << "motif";
case tail:
	cout << "tail";
case noncoding:
	cout << "noncoding";
default:
	break;
}

}

RNA DNA::convert_to_RNA()
{
	int x, y;
	cout << "enter the star char and the end char";
	cin >> x >> y;
	set_startchar(x);
	set_endchar(y);
	
	char* arr;
		arr = new char[end_char-start_char];
	for (int i = 0;i < end_char;i++) 
	{
		if (this->seq[i] == 'T') 
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
	cout << "the RNA from the DNA is:" << endl;
	R1.print();
	return R1;

}

void DNA::build_complemantary_strand()
{
	complemantary_strand = new DNA;
	complemantary_strand->seq = new char[length];
	for (int i = 0;i < length;i++) {
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
	for (int i = 0; i < (length/2); i++)
	{
		char temp;
		temp = complemantary_strand->seq[i];
		complemantary_strand->seq[i] = complemantary_strand->seq[length-1 - i];
		complemantary_strand->seq[length-1 - i] = temp;
		

	}
	cout << "the complemantary is:" << endl;
	complemantary_strand->print();
	
	
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
DNA DNA ::operator+(DNA &obj) {
		char *newseq;
	newseq = new char[length + obj.length];
	for (int i = 0;i < length;i++) {
		newseq[i] = seq[i];
	}
	for (int j = 0;j < obj.length;j++) {
		newseq[length + j] = obj.seq[j];
	}
	DNA rdna(newseq, type, length + obj.length);
		return rdna;
}

bool DNA ::operator==(DNA&obj) {
	if ((length == obj.length) )
	{

		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool DNA::operator!=(DNA& obj) {
	if ((length == obj.length) && (type == obj.type))
	{
		for (int i = 0; i < length; i++)
		{
			if (seq[i] != obj.seq[i])
			{
				return true;
			}
		}

		return false;
	}
	else {
		return true;
	}
}

ostream&operator<<(ostream &out, DNA &obj)
{
	int x=0;
	out << "the sequence is:";
	while (x<obj.length)
	{
		
			out << obj.seq[x] << " ";
			x++;
	}
	out << endl << "the type of sequence is:" << obj.type << endl;
	return out;
}


istream& operator>> (istream&in, DNA & obj)
{
	cout << "enter the length of the sequence:";
	in >> obj.length;
	obj.type = promoter;
	obj.seq = new char[obj.length];
	cout << "enter the sequence:" << endl;
	for (int i = 0; i < obj.length; i++)

	{
		
		in >> obj.seq[i];
	}
	
	return in;
}



DNA::~DNA()
{
}

