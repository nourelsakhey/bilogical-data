#include "Protein.h"



Protein::Protein()
{
}

Protein::Protein(char *p, Protein_Type atype,int length):sequence(length)
{
	for (int i = 0;i < length;i++)
	{
		seq[i] = p[i];
	}
	type = atype;

}

/*DNA* Protein::get_DNAstrands_enoding_me(const DNA&bigDNA)
{

}*/

void Protein::print()
{
	cout << "the strand is: ";
	for (int i = 0;i < length;i++)
	{
		cout << seq[i];
	}
	cout << "the type is:";
	switch (type)
	{
	case hormon:
		cout << "hormon";
		break;
	case enzyme:
		cout << "enzyme";
		break;
	case TE:
		cout << "TE";
		break;
	case cellular_function:
		cout << "cellular_function";
		break;
	default:
		break;
	}

}
Protein Protein ::operator+(Protein &obj) {
	char *newseq;
	newseq = new char[length + obj.length];
	for (int i = 0;i < length;i++) {
		newseq[i] = seq[i];
	}
	for (int j = 0;j < obj.length;j++) {
		newseq[length + j] = obj.seq[j];
	}
	Protein rprotein(newseq, type, length + obj.length);
	return rprotein;
}

bool Protein ::operator==(Protein&obj) {
	if ((length == obj.length) && (type == obj.type))
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

bool Protein::operator!=(Protein& obj) {
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

ostream&operator<<(ostream &out, Protein &obj)
{
	out << "the sequence is:";
	for (int i = 0; i < obj.length; i++)
	{

		out << obj.seq[i] << " ";
	}
	out << endl << "the type of sequence is:" << obj.type << endl;
	return out;
}

istream& operator>> (istream&in, Protein& obj)
{
	cout << "enter the length of the sequence:";
	in >> obj.length;
	cout << "enter the sequence:" << endl;
	for (int i = 0; i < obj.length; i++)
	{
		in >> obj.seq[i];
	}
	cout << "enter the type of the Protein";
	//in >> obj.type;
	return in;
}

Protein::~Protein()
{
}
