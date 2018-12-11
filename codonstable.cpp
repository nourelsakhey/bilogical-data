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
    /*string line;
    fstream myfile;
    myfile.open (codonsFileName,ios::in);

    cout <<"klfsjk";

    for (int i = 0 ; i < 64 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
           myfile >> codons[i].value[j];
           cout << "nfkdslkm";
        }
        cout << "nildhsk" << endl;
        myfile >> codons[i].AminoAcid;
    }
    myfile.close();
    */
}

Codon CodonsTable::getAminoAcid(char * value)
{

}

void CodonsTable::setCodon(char * value, char AminoAcid, int index)
{

}
