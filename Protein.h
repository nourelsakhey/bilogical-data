#pragma once
#include"sequence.h"
#include"DNA.h"
#include"RNA.h"
#include<iostream>
using namespace std;

class DNA;

enum Protein_Type{hormon,enzyme,TE,cellular_function};

class Protein:public sequence 
{
private:
	Protein_Type type;
public:
	Protein();
	Protein(char *p, Protein_Type atype,int length);
	//DNA* get_DNAstrands_enoding_me(const DNA&bigDNA);
	void print();
	Protein operator+(Protein &obj);
	bool operator==(Protein &obj);
	bool operator!=(Protein &obj);
	friend ostream& operator<< (ostream& , Protein&);
	friend istream& operator>> (istream&, Protein&);
	~Protein();
};

