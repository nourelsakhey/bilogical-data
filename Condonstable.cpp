
#include"Condonstable.h"

Codonstable::Codonstable()
{

}
Codonstable::~Codonstable()
{

}

void Codonstable::load_codons_from_file(string codonsFileName)
{
	bool exit = true;
	do {
		try {
			(file.is_open());
			exit = true;
		}
		//ifstream file(codonsFileName);
		//try {
		//	file.is_open();
		//}
		catch (const ifstream::failure&e) {
			cout << "the file is not found" << endl;
			exit = false;
		}
	}
	while (!exit);
	while (!file.eof())
	{

		for (int i = 0; i < 64; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				file >> codons[i].value[j];
			}
			file >> codons[i].aminoacid;
		}
	}
}

codon Codonstable::get_aminoacid(char * value)
{
	int count_ = 0, index = 0;
	bool check = true;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 3; j++) {
			if (codons[i].value[j] != value[j]) {

				break;
			}
			else
				continue;
			count_++;
		}
		if (count_ == 3)
		{
			break;
			index = i;
		}

	}
	return codons[index];
}
void Codonstable::set_codon(char * value, char aminoacid, int index)
{

}
