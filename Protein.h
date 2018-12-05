#pragma once
#include"sequence.h"
#include"DNA.h"
#include"RNA.h"

enum Protein_type{hormon,enzyme,TE,cellular_function};
class Protein:public sequence
{
private:
	Protein_type type;
public:
	Protein();
	Protein(char*p);
	DNA* get_DNAstrands_enoding_me(const DNA&bigDNA);
	void print();
	~Protein();
};

