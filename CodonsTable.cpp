#include "CodonsTable.h"
CodonsTable::CodonsTable()
{

}
CodonsTable::~CodonsTable()
{

}
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
	file.open(codonsFileName);
	while (!file.eof())
	{
		for (int i = 0; i < 64; i++) 
		{
			for (int j = 0; j < 3; j++)
			{
				file >> codons[i].value[j];
			}
			file >> codons[i].AminoAcid;
		}
	}
}
Codon CodonsTable::getAminoAcid(char * value)
{
	int count_ = 0, index=0;
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
void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{

}