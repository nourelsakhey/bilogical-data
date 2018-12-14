#include <iostream>
#include <string>
#include <cstring>
#include "rna.h"
#include "sequence.h"
#include "dna.h"
#include "protein.h"
#include "codonstable.h"

using namespace std;

class Protein;

RNA::RNA()
{

}

RNA::RNA(char* seq, RNA_Type type)
{
    this->seq = seq;
    this->type = type;
}

RNA::RNA(RNA& rhs)
{
    type = rhs.type;
    seq = new char;
    seq = rhs.seq;
}

RNA::~RNA()
{
    delete seq;
}

void RNA::Print()
{
    cout << "The RNA Strand = ";

    for (unsigned int i = 0 ; i < strlen(seq) ; i++)
    {
        cout << seq[i] << " ";
    }

    cout << endl;

    cout << "RNA Type = " ;

    switch(type){
case 0:
    cout<<"mRNA"<<endl;
    break;
case 1:
    cout<<"pre_mRNA"<<endl;
    break;
case 2:
    cout<<"mRNA_exon"<<endl;
    break;
case 3:
    cout<<"mRNA_intron"<<endl;
    break;
    }
}

DNA RNA::ConvertToDNA()
{
    char* convrt;
    convrt = new char [strlen(seq)];
    int siz = strlen(seq);

    for (int i = 0 ; i < siz ; i++)
    {
        if (seq[i] == 'U')
        {
            convrt[i] = 'T';
        }
        else
        {
            convrt[i] = seq[i];
        }
    }

    cout << "The Converted Data from RNA to DNA : ";
    for (int j = 0 ; j < siz ; j++)
    {
        cout << convrt[j] << " ";
    }
    cout << endl;
}

Protein RNA::ConvertToProtein(const CodonsTable & table)
{
    char* value;
    value = new char [4];

    char* result;
    result = new char[strlen(seq) / 3];

    int cont = 0;

    for (int i = 0 , k = 0 ; i < strlen(seq) ; i+=3 , k++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            value[j] = seq[j+i];
        }

        result[k] = table.getAminoAcid(value);

        /*for (int k = 0 ; k < 64 ; k++)
        {
            for (int l = 0 ; l < 3 ; l++)
            {
                if(value[l] == table.codons[k].value[l])
                {
                    cont++;
                }
            }

            if (cont == 3)
            {
                table.getAminoAcid()
            }
        }
        */
    }
}

