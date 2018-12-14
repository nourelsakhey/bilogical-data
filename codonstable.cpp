#include "codonstable.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "sequence.h"
#include "rna.h"
#include "dna.h"

using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{
    //ctor
}


void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    string line;
    fstream myfile;
    myfile.open (codonsFileName,ios::in);

    for (int i = 0 ; i < 64 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
           myfile >> codons[i].value[j];
        }
        myfile >> codons[i].AminoAcid;
    }
    myfile.close();
}

Codon CodonsTable::getAminoAcid(char * value)
{
    int cont = 0;
    for (int m = 0 ; m < 64 ; m++)
    {
        for (int n = 0 ; n < 3 ; n++)
        {
            if(value[n] == codons[m].value[n])
            {
                cont++;
            }
            if (cont == 3)
            {
                codon m;
                m.value = value;
                m.AminoAcid = codons[m].AminoAcid;

                return m;
            }
        }
    }
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{

}
