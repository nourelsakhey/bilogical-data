#include "Condonstable.h"



Condonstable::Condonstable()
{
	

}
void Condonstable::load_condons_from_file(string condons_file_name)
{
	file.open(condons_file_name);
	while (!file.eof())
	{


		for (int i = 0;i < 64;i++) {
			for (int j = 0;j < 3;j++) {
				file >> condons[i].value[j];
			}
			file >> condons[i].aminoacid;
		}

		
	}
}
condon Condonstable::get_aminoacid(char*value)
{
	bool check = true;
	for (int i = 0;i < 64;i++) {
		for (int j = 0;j < 3;j++) {
			if (condons[i].value[j] != value[j]) {
				break;
			}
			
			

		}
		

	}



}
void Condonstable:: set_condon(char*value, char aminoacid, int index)
{

}

Condonstable::~Condonstable()
{
	file.close();
}
