#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
#include<cstring>
using namespace std;

class Protein;

struct codon
{
	char value[4]; // {a,b,c,'\0'}
	char aminoacid;


};

class Codonstable
{
private:
	codon codons[64];
	ifstream file;
public:
	Codonstable();
	void load_codons_from_file(string codons_file_name);
	codon get_aminoacid(char*value);
	void set_codon(char*value, char aminoacid, int index);
	~Codonstable();
};

