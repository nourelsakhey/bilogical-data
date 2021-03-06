#pragma once
#include"sequence.h"
#include"DNA.h"
#include"Protein.h"
#include"Condonstable.h"
#include<iostream>
#include<string>
using namespace std;

class DNA;
enum RNA_type{mRNA,tRNA,uRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA:public sequence
{
private:
	RNA_type type;
	
public:
	RNA();
	RNA(char *seq, RNA_type atype,int length);
	RNA(RNA&rhs);
	void print();
	Protein convert_to_Protien( Codonstable &table);
	DNA convert_to_DNA();
	RNA operator+(RNA &obj);
	bool operator==(RNA &obj);
	bool operator!=(RNA &obj);
	friend ostream& operator<< (ostream&, RNA&);
	friend istream& operator>> (istream&, RNA&);
	~RNA();
};


