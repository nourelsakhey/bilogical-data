#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Protein;

struct condon
{
	char value[4]; // {a,b,c,'\0'}
	char aminoacid;


};
class Condonstable
{
private:
	condon condons[64];
	ifstream file;
public:
	Condonstable();
	void load_condons_from_file(string condons_file_name);
	condon get_aminoacid(char*value);
	void set_condon(char*value, char aminoacid, int index);
	~Condonstable();
};

